#include "ShardArmor.h"
#include "InventoryComponent.h"
#include "Item.h"
#include "DestroyableComponent.h"
#include "dLogger.h"

void ShardArmor::OnHit(Entity* self, Entity* attacker) {
    Game::logger->Log("ShardArmor", "Previously equipped = %i with number of hits = %i", previouslyEquippedArmor, numTimesHit);
    auto inventoryComponent = self->GetComponent<InventoryComponent>();
    if (inventoryComponent == nullptr) return;

    if (inventoryComponent->IsEquipped(ShardArmorLOT)) {
        Game::logger->Log("ShardArmor", "Found Shard Armor equipped");
        if (previouslyEquippedArmor != ShardArmorLOT) {
            Game::logger->Log("ShardArmor", "Previously equipped item was not the Shard Armor");
            previouslyEquippedArmor = ShardArmorLOT;
            numTimesHit = 0;
        }
    } else if (inventoryComponent->IsEquipped(ImaginitePackLOT)) {
        Game::logger->Log("ShardArmor", "Found Imaginate Pack equipped");
        if (previouslyEquippedArmor != ImaginitePackLOT) {
            Game::logger->Log("ShardArmor", "Previously equipped item was not the Imaginite Pack");
            previouslyEquippedArmor = ImaginitePackLOT;
            numTimesHit = 0;
        }
    } else {
        return;
    }
    numTimesHit++;
    Game::logger->Log("ShardArmor", "Number of times hit = %i", numTimesHit);
    if(numTimesHit == numHitsToTrigger) {
        auto destroyableComponent = self->GetComponent<DestroyableComponent>();
        if (destroyableComponent == nullptr) return;

        if (previouslyEquippedArmor == ShardArmorLOT) {
            Game::logger->Log("ShardArmor", "Repairing...");
            destroyableComponent->Repair(3);
        } else if (previouslyEquippedArmor == ImaginitePackLOT) {
            Game::logger->Log("ShardArmor", "Imagining...");
            destroyableComponent->Imagine(5);
        }
    }
}