#include "StartBehavior.h"
#include "BehaviorBranchContext.h"

void StartBehavior::Handle(BehaviorContext* context, RakNet::BitStream* bitStream, BehaviorBranchContext branch)
{
	branch.start = this->m_behaviorId;
	
	this->m_action->Handle(context, bitStream, branch);
}

void StartBehavior::Calculate(BehaviorContext* context, RakNet::BitStream* bitStream, BehaviorBranchContext branch)
{
	branch.start = this->m_behaviorId;

	this->m_action->Calculate(context, bitStream, branch);
}

void StartBehavior::Load()
{
	this->m_action = GetAction("action");
}
