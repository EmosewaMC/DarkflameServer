#include "GhostComponent.h"
#include "Entity.h"
#include "GameMessages.h"

GhostComponent::GhostComponent(Entity* parent) : Component(parent) {
	m_IsInvisible = false;
}

void GhostComponent::LoadFromXml(tinyxml2::XMLDocument* doc) {
	auto* ghst = doc->FirstChildElement("obj")->FirstChildElement("ghst");
	if (!ghst) return;
	ghst->QueryAttribute("i", &m_IsInvisible);
}

void GhostComponent::UpdateXml(tinyxml2::XMLDocument* doc) {
	auto* obj = doc->FirstChildElement("obj");
	if (!obj) return;

	auto* ghst = obj->FirstChildElement("ghst");
	if (!ghst) {
		ghst = doc->NewElement("ghst");
		obj->LinkEndChild(ghst);
	}

	ghst->SetAttribute("i", m_IsInvisible);
}

void GhostComponent::SetInvisible(bool isInvisible) {
	if (m_IsInvisible == isInvisible) return; // Don't toggle if we are in the same state as requested.
	SetIsInvisible(isInvisible);
	GameMessages::SendToggleGMInvis(m_Parent->GetObjectID(), isInvisible, UNASSIGNED_SYSTEM_ADDRESS);
}
