#include "Team.hpp"

SmartTeam::SmartTeam(Character* lead) : Team(lead) {}

void SmartTeam::attack(Team *enemies)
{
    if (enemies == nullptr)
    {
        throw std::invalid_argument("Enemy team is null!");
    }

    if (!enemies->stillAlive())
    {
        throw std::runtime_error("The enemy is already dead");
    }

    std::vector<Character *> aliveMembers = getAliveFighters(enemies->fighters);
    if(aliveMembers.capacity() == 0)
    {
        return;
    }

    // Sort enemies by health in ascending order - weakest first
    std::sort(aliveMembers.begin(), aliveMembers.end(), [](const Character* a, const Character* b) {
        return a->getHealth() < b->getHealth();
    });

    // Sort team members by their attack power in descending order - strongest first
    std::sort(fighters.begin(), fighters.end(), [](const Character* a, const Character* b) {
        return a->getPower() > b->getPower();
    });

    for (const auto& fighter : fighters)
    {
        // The fighter with the most power goes first
        this->leader = closetMemberIsAlive(fighters, this->leader);
        Character *theEnemy = closetEnemyIsAlive(aliveMembers, this->leader);
        attackEnemy(fighter, theEnemy);
    }
}
