#ifndef __GHOSTCOMPONENT__H__
#define __GHOSTCOMPONENT__H__

#include "Component.h"
#include "eReplicaComponentType.h"

class Entity;

namespace tinyxml2 {
	class XMLDocument;
};

class GhostComponent : public Component {
public:
	static const eReplicaComponentType ComponentType = eReplicaComponentType::GHOST;

	GhostComponent(Entity* parent);

	void LoadFromXml(tinyxml2::XMLDocument* doc) override;
	void UpdateXml(tinyxml2::XMLDocument* doc) override;

	bool GetIsInvisible() const { return m_IsInvisible; };
	void SetIsInvisible(bool isInvisible) { m_IsInvisible = isInvisible; };

	void SetInvisible(bool isInvisible);

private:
	bool m_IsInvisible;
};

#endif  //!__GHOSTCOMPONENT__H__
