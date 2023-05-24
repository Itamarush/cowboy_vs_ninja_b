#include "Team.hpp"

Team2::Team2(Character *leader) : Team(leader) {}
      
void Team2::add(Character *character)
{
    if (character->getIsPlaying())
    {
        throw std::runtime_error(character->getName() + " is already in a team!");
    }
    if (fighters.size() >= 10)
    {
        throw std::runtime_error("The team is full, cannot add more members!");
    }
    if (std::find(fighters.begin(), fighters.end(), character) != fighters.end())
    {
        throw std::runtime_error(character->getName() + " is already in the team!");
    }
    this->fighters.push_back(character);
    character->setIsPlaying(true);
}
    std::vector<Character *> Team2::getFighters()
    {
        return fighters;
    }

    int Team2::stillAlive()
    {
        int count = 0;
        for (auto member : fighters)
        {
            if (member->isAlive())
            {
                count++;
            }
        }
        return count;
    }

    void Team2::print()
    {
        for (auto member : fighters)
        {
            std::cout << "    " << member->print() << std::endl;
        }
    }
