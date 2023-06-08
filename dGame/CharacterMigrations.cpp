#include "CharacterMigrations.h"

#include "Entity.h"
#include "MissionComponent.h"
#include "eMissionState.h"
#include "eMissionTaskType.h"

void CharacterMigrations::RetriggerMetaMission(Entity* player) {
	auto missionComponent = player->GetComponent<MissionComponent>();
	if (!missionComponent) return;
	for (const auto& [missionId, mission] : missionComponent->GetMissions()) {
		if (!(mission->IsAchievement() || mission->GetMissionState() != eMissionState::ACTIVE)) continue;
		for (const auto task : mission->GetTasks()) {
			if (task->GetType() != eMissionTaskType::META) continue;
			task->SetProgress(0); // Set progress to zero as we are going to "replay" progressing the mission by just checking if the subtask mission is complete
			for (const auto& subTask : task->GetAllTargets()) {
				if (missionComponent->GetMissionState(subTask) != eMissionState::COMPLETE) continue;
				task->SetProgress(task->GetProgress() + 1);
			}
		}
	}
}
