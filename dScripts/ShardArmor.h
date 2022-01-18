#pragma once
#include "CppScripts.h"

class ShardArmor : public CppScripts::Script
{
public:
    /**
     * On a hit to self, a counter goes up by 1 and when this counter hits 5 one of two things will happen: 
     * 1) If the player is wearing Shard Armor, the player is restored 3 armor. 
     * 2) If the player is wearing the Imaginite Pack, the player is restored 5 imagination.
     * 
     * @param self The Entity that was hit.
     * @param attacker The Entity that attacked self.
     */
    void OnHit(Entity* self, Entity* attacker);
private:
    /**
     * The LOT of the Shard Armor.
     */
    LOT ShardArmorLOT = 13354;
    /**
     * The LOT of the Imaginite Pack.
     */
    LOT ImaginitePackLOT = 15975;
    /**
     * The armor last equipped when this file was called.  
     */
    LOT previouslyEquippedArmor = 0;
    /**
     * The number of times we have been hit with the same armor equipped.
     */
    int32_t numTimesHit = 0;
    /**
     * The number of hits to trigger this ability.
     */
    int32_t numHitsToTrigger = 5;
};