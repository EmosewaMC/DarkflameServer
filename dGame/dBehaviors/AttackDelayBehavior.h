#pragma once
#include "Behavior.h"

class AttackDelayBehavior final : public Behavior
{
public:
	Behavior* m_action;

	float m_delay;

	uint32_t m_numIntervals;

	bool m_ignoreInterrupts;

	/*
	 * Inherited
	 */
	
	explicit AttackDelayBehavior(const uint32_t behaviorId) : Behavior(behaviorId)
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
	/**
	 * Handles syncing a behavior to match what is going on on the client.
	 * 
	 * @param context The base context on which this behavior node is executed.  
	 * @param bitStream A BitStream containing information about how the client is calculating the behavior.
	 * @param branch The context of the behavior for this behaviors branch.
	 */
	void Sync(BehaviorContext* context, RakNet::BitStream* bitStream, BehaviorBranchContext branch) override;

	void SyncCalculation(BehaviorContext* context, RakNet::BitStream* bitStream, BehaviorBranchContext branch) override;
	
	void Load() override;
};
