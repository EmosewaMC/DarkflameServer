#pragma once
#include "Behavior.h"

class AreaOfEffectBehavior final : public Behavior
{
public:
	Behavior* m_action;

	uint32_t m_maxTargets;

	float m_radius;

	int32_t m_ignoreFaction;

	int32_t m_includeFaction;

    int32_t m_TargetSelf;

	int32_t m_targetEnemy;

	int32_t m_targetFriend;
	
	/*
	 * Inherited
	 */
	explicit AreaOfEffectBehavior(const uint32_t behaviorId) : Behavior(behaviorId)
	{
	}
	/**
	 * Handles calculating a behavior node from the players side.
	 * 
	 * @param context The base behavior context on which this behavior node is executed.  
	 * @param bitStream A BitStream containing information about how the client has calculated the behavior.
	 * If this is a server side only calculation, this is generally empty.
	 * @param branch The context of the behavior for this behaviors branch.
	 */
	void Handle(BehaviorContext* context, RakNet::BitStream* bitStream, BehaviorBranchContext branch) override;
	
	void Calculate(BehaviorContext* context, RakNet::BitStream* bitStream, BehaviorBranchContext branch) override;

	void Load() override;
};
