#pragma once
#include "Behavior.h"
#include "dCommonVars.h"
#include "NiPoint3.h"

class TacArcBehavior final : public Behavior
{
public:
	bool m_usePickedTarget;

	Behavior* m_action;

	bool m_checkEnv;

	Behavior* m_missAction;

	Behavior* m_blockedAction;

	float m_minDistance;

	float m_maxDistance;

	uint32_t m_maxTargets;

	bool m_targetEnemy;

	bool m_targetFriend;

	bool m_targetTeam;

	float m_angle;

	float m_upperBound;

	float m_lowerBound;

	float m_farHeight;

	float m_farWidth;

	uint32_t m_method;

	NiPoint3 m_offset;

	/*
	 * Inherited
	 */
	
	explicit TacArcBehavior(const uint32_t behavior_id) : Behavior(behavior_id)
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
