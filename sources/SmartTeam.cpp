#include "Team.hpp"

void SmartTeam::attack(Team *enemies) {
    if (enemies == nullptr) {
        throw std::invalid_argument("Enemy team is null!");
    }

    if (!enemies->stillAlive()) {
        throw std::runtime_error("The enemy team is already dead");
    }

    for (const auto& fighter : fighters) {
        // Get a list of alive members from the enemy team
        std::vector<Character *> aliveEnemies = getAliveMembers(enemies->fighters);
        
        if(aliveEnemies.empty()) { return; }
        
        // Find the weakest enemy (with the lowest health)
        Character *weakestEnemy = aliveEnemies.front();
        for (const auto& enemy : aliveEnemies) {
            if (enemy->getHealth() < weakestEnemy->getHealth()) {
                weakestEnemy = enemy;
            }
        }

        // Attack the weakest enemy
        attackEnemy(fighter, weakestEnemy);
    }
}
