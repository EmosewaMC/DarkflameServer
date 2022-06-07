#pragma once
#include "Behavior.h"

class KnockbackBehavior final : public Behavior
{
public:
	/*
	 * Inherited
	 */

	uint32_t m_strength;
	uint32_t m_angle;
	bool m_relative;
	uint32_t m_time;
	

	explicit KnockbackBehavior(const uint32_t behaviorID) : Behavior(behaviorID)
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
