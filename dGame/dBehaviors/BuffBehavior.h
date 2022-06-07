#pragma once
#include "Behavior.h"

class BuffBehavior final : public Behavior
{
public:
	uint32_t m_health;

	uint32_t m_armor;

	uint32_t m_imagination;
	
	/*
	 * Inherited
	 */
	explicit BuffBehavior(const uint32_t behaviorId) : Behavior(behaviorId)
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

	void UnCast(BehaviorContext* context, BehaviorBranchContext branch) override;

	void Timer(BehaviorContext* context, BehaviorBranchContext branch, LWOOBJID second) override;

	void End(BehaviorContext* context, BehaviorBranchContext branch, LWOOBJID second) override;
	
	void Load() override;
};
