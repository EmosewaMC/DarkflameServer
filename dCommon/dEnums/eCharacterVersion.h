#pragma once

#ifndef __ECHARACTERVERSION__H__
#define __ECHARACTERVERSION__H__

#include <cstdint>

enum class eCharacterVersion : uint32_t {
// Versions from the live game
	RELEASE = 0, // Initial release of the game
	LIVE, // Fixes for the 1.9 release bug fixes for missions leading up to joining a faction

// New versions for DLU fixes
	PLAYER_FACTION_FLAGS, // Fixes the "Joined a faction" player flag not being set properly
	VAULT_SIZE, // Fixes vault size value and fixes speed base value in level component
	META_TASK, // Fixes an issue where META tasks were not being completed properly
	UP_TO_DATE, // will become SPEED_BASE
};

#endif  //!__ECHARACTERVERSION__H__
