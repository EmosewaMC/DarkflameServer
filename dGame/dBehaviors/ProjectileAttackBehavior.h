#pragma once
#include "Behavior.h"
#include "NiPoint3.h"

class ProjectileAttackBehavior final : public Behavior
{
public:
	LOT m_lot;

	uint32_t m_projectileCount;

	float m_projectileSpeed;

	float m_maxDistance;

	float m_spreadAngle;

	NiPoint3 m_offset;

	bool m_trackTarget;

	float m_trackRadius;

	bool m_useMouseposit;

	/*
	 * Inherited
	 */

	explicit ProjectileAttackBehavior(const uint32_t behavior_id) : Behavior(behavior_id)
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
