#pragma once
#include "Behavior.h"

class JetPackBehavior final : public Behavior 
{
public:
	int32_t m_WarningEffectID;
	float m_Airspeed;
	float m_MaxAirspeed;
	float m_VerticalVelocity;
	bool m_EnableHover;
	bool m_BypassChecks = true; // from what I can tell this defaulted true in live

	/*
	 * Inherited
	 */

	explicit JetPackBehavior(const uint32_t behavior_id) : Behavior(behavior_id) {
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

	void Calculate(BehaviorContext* context, RakNet::BitStream* bitStream, BehaviorBranchContext branch) override;

	void Load() override;
};
