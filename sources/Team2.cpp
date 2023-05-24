#include "Team.hpp"

Team2::Team2(Character *leader) : Team(leader) {}
      
    std::vector<Character *> Team2::getFighters()
    {
        return fighters;
    }


// void Team2::attack(Team *enemies)
// {
//     if (enemies == nullptr)
//     {
//         throw std::invalid_argument("Enemy team is null!");
//     }

//     if (!enemies->stillAlive())
//     {
//         throw std::runtime_error("The enemy is already dead");
//     }
//         for (const auto& fighter : fighters)
//         {
//             Character *theEnemy;
//             this->leader = closetMemberIsAlive(fighters, this->leader);
//             std::vector<Character *> aliveMembers = getAliveFighters(enemies->fighters);
//             if(aliveMembers.capacity() == 0)
//             {
//                 return;
//             }
//             theEnemy = closetEnemyIsAlive(aliveMembers, this->leader);
//             attackEnemy(fighter, theEnemy);
            
//         }
// }

void Team2::print()
{
    std::string indent = "    ";
    for (auto member : fighters) {
        std::cout << indent << member->print() << std::endl;
    }
}
