#pragma once

#include "Character.hpp"


namespace ariel
{
    class Cowboy : public Character
    {
        int bulletsCounter;

    public:
        Cowboy(std::string name, Point location);
        void shoot(Character *ninjaToShoot);
        bool hasboolets();
        void reload();
        int getBulletCounter();
    };
}