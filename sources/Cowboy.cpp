#include "Cowboy.hpp"
#include "Character.hpp"
#include "Point.hpp"

using namespace ariel;

Cowboy::Cowboy(std::string name, Point location)
    : Character(name, location, 110, 0, 1)
{
    this->bulletsCounter = 6;
}

void Cowboy::shoot(Character *enemy)
{
    if (!this->isAlive())
    {
        throw std::runtime_error("The attacking chararcter is dead");
    }
    if (enemy == nullptr)
    {
        throw std::runtime_error("The enemy is already dead");
    }
    if (!enemy->isAlive())
    {
        throw std::runtime_error("The targett is dead");
    }
    if (this == enemy)
    {
        throw std::runtime_error("The attacking and attacked player is the same character");
    }
    if (this->isAlive() && bulletsCounter)
    {
        enemy->hit(10);
        this->bulletsCounter--;
    }
}

bool Cowboy::hasboolets()
{
    return this->bulletsCounter;
}

void Cowboy::reload()
{
    if (!this->isAlive())
    {
        throw std::runtime_error("dead Cowboy cant reload!");
    }
    
    this->bulletsCounter = 6;
}

int Cowboy::getBulletCounter()
{
    return this->bulletsCounter;
}
