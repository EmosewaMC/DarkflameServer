#pragma once
#include "CppScripts.h"

class AmBridge : public CppScripts::Script
{
public:
    void OnStartup(Entity* self) override;
    void OnRebuildComplete(Entity* self, Entity* target) override;
    void OnTimerDone(Entity* self, std::string timerName) override;
    void OnHitOrHealResult(Entity* self, Entity* attacker, int32_t damage) override;
};
