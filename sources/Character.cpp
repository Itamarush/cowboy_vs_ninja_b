#include "Character.hpp"

using namespace std;

namespace ariel{
    
    Character::Character(string name, Point location, int _hp, int isPlaying, int isCowboy):
    name(name), location(location), _hp(_hp), isPlaying(isPlaying), isCowboy(isCowboy){}

    bool Character::isAlive()
    {
        return _hp;
    }

    double Character::distance(Character* other)
    {
        return location.distance(other->getLocation());
    }

    void Character::hit(int damage)
    {
        if (damage < 0)
        {
            throw std::invalid_argument("damage value cannot be negative");
        }
        
        this->_hp -= damage;
        
        if (_hp < 0)
        {
            this->_hp = 0;
        }
    }

    std::string Character::print()
    {
        std::ostringstream oss;
        if (!isAlive())
        {
            oss << "(" << name << ")" << std::endl;
        }
        else
        {
            oss << name << " " << _hp << " " << &location << std::endl;
        }
        return oss.str();
    }

    std::string Character::getName()
    {
        return this->name;
    }

    Point Character::getLocation()
    {
        return location;
    }

    void Character::setLocation(Point loca)
    {
        location = loca;
    }

    void Character::setIsPlaying(bool par)
    {
        this->isPlaying = par;
    }

    bool Character::getIsPlaying()
    {
        return this->isPlaying;
    }

    bool Character::getIsNinja()
    {
        return !(this->isCowboy);
    }

    bool Character::getIsCowboy()
    {
        return this->isCowboy;
    }
}