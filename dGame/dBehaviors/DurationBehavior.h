#pragma once
#include "Behavior.h"

class DurationBehavior final : public Behavior
{
public:
	float m_duration;

	Behavior* m_action;
	
	explicit DurationBehavior(const uint32_t behavior_id) : Behavior(behavior_id)
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
private:
	float m_Timer = 0.0f;
};
