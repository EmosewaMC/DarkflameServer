#ifndef __CHARACTERMIGRATIONS__H__
#define __CHARACTERMIGRATIONS__H__

class Entity;

namespace CharacterMigrations {
	/**
	 * Fixes an issue where players could have a Meta task that has all the target missions completed, but the Meta task is not completed
	 * This was caused by a mission cache issue that was fixed previously.  This function ensures players that have affected achievements are
	 * properly progressed to where they should be.
	 * 
	 * @param player The player to fix
	 */
	void RetriggerMetaMission(Entity* player);
}

#endif  //!__CHARACTERMIGRATIONS__H__
