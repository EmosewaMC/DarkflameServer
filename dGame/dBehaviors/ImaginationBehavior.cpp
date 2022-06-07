#include "ImaginationBehavior.h"
#include "BehaviorBranchContext.h"
#include "DestroyableComponent.h"
#include "dpWorld.h"
#include "EntityManager.h"
#include "dLogger.h"


void ImaginationBehavior::Handle(BehaviorContext* context, RakNet::BitStream* bitStream, const BehaviorBranchContext branch)
{
	auto* entity = EntityManager::Instance()->GetEntity(branch.target);

	if (entity == nullptr)
	{
		return;
	}

	auto* destroyable = entity->GetComponent<DestroyableComponent>();

	if (destroyable == nullptr)
	{
		return;
	}

	destroyable->Imagine(this->m_imagination);

}

void ImaginationBehavior::Calculate(BehaviorContext* context, RakNet::BitStream* bitStream, const BehaviorBranchContext branch)
{
	Handle(context, bitStream, branch);
}

void ImaginationBehavior::Load()
{
	this->m_imagination = GetInt("imagination");
}
