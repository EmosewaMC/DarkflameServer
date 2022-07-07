#include "AmBridge.h"
#include "EntityManager.h"
#include "DestroyableComponent.h"

void AmBridge::OnStartup(Entity* self) 
{
    
}

void AmBridge::OnRebuildComplete(Entity* self, Entity* target) 
{
    const auto consoles = EntityManager::Instance()->GetEntitiesInGroup("Console" + GeneralUtils::UTF16ToWTF8(self->GetVar<std::u16string>(u"bridge")));

    if (consoles.empty())
    {
        return;
    }

    auto* console = consoles[0];

    console->NotifyObject(self, "BridgeBuilt");

    self->AddTimer("SmashBridge", 50);

    // Technically the faction should be -1 
    auto destroyableComponent = self->GetComponent<DestroyableComponent>();
    if (destroyableComponent) {
        destroyableComponent->SetFaction(4);
        destroyableComponent->SetIsSmashable(false);
    }
}

void AmBridge::OnTimerDone(Entity* self, std::string timerName) 
{
    if (timerName != "SmashBridge")
    {
        return;
    }

    self->Smash(self->GetObjectID(), VIOLENT);
}

void AmBridge::OnHitOrHealResult(Entity* self, Entity* attacker, int32_t damage) {
    auto destroyableComponent = self->GetComponent<DestroyableComponent>();
    if (destroyableComponent) {
        destroyableComponent->Heal(damage);
    }

    const auto consoles = EntityManager::Instance()->GetEntitiesInGroup("Console" + GeneralUtils::UTF16ToWTF8(self->GetVar<std::u16string>(u"bridge")));

    if (consoles.empty())
    {
        return;
    }

    auto* console = consoles[0];
    if (console) {
        console->OnUse(self);
    }
}
