#pragma once
#include "Behavior.h"

class AirMovementBehavior final : public Behavior
{
public:

	/*
	 * Inherited
	 */

	explicit AirMovementBehavior(const uint32_t behavior_id) : Behavior(behavior_id)
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

	/**
	 * Handles calculating a behavior node from the NPCs side.
	 * 
	 * @param context The base behavior context on which this behavior node is executed.  
	 * @param bitStream A BitStream containing information about how the client has calculated the behavior.
	 * If this is a server side only calculation, this is generally empty.
	 * @param branch The context of the behavior for this behaviors branch.
	 */
	void Calculate(BehaviorContext* context, RakNet::BitStream* bitStream, BehaviorBranchContext branch) override;

	/**
	 * Handles syncing a behavior to match what is going on on the client.
	 * 
	 * @param context The base context on which this behavior node is executed.  
	 * @param bitStream A BitStream containing information about how the client is calculating the behavior.
	 * @param branch The context of the behavior for this behaviors branch.
	 */
	void Sync(BehaviorContext* context, RakNet::BitStream* bitStream, BehaviorBranchContext branch) override;

	void Load() override;
};
