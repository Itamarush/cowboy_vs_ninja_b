#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
#include <vector>
#include <array>
#include <algorithm>

#include "Point.hpp"
#include "Cowboy.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "OldNinja.hpp"

using namespace ariel;
using namespace std;

namespace ariel
{
    class Team 
    {
        
        public:
        vector <Character*> fighters;
        Character *leader;

        Team(Character *leader);
        Team() : leader(nullptr){};
        Team(const Team &) = default;
        Team &operator=(const Team &) = default;
        Team(Team &&) noexcept = default;
        Team &operator=(Team &&) noexcept = default;
        virtual ~Team();
        virtual void add(Character*);
        virtual Character *closetMemberIsAlive(std::vector<Character *>&, Character*);
        virtual Character *closetEnemyIsAlive(std::vector<Character *>&, Character*);
        void attackEnemy(Character *, Character *);
        void setLeader(Character *);
        virtual void attack(Team *);
        virtual int stillAlive();
        virtual void print();
        std::vector<Character *> getAliveFighters(const std::vector<Character *>&);

    };

    class Team2 : public Team
    {
        Character *leader;
        
        public:
        Team2(Character* lead);
        Team2() : leader(nullptr), Team(nullptr) {}
        Team2(const Team2 &) = default;
        Team2 &operator=(const Team2 &) = default;
        Team2(Team2 &&) noexcept = default;
        ~Team2() override = default;
        Team2 &operator=(Team2 &&) noexcept = default;
        void add(Character* character) override;
        int stillAlive() override;
        void print() override;
        std::vector<Character *> getFighters();

    };

        class SmartTeam : public Team
        {
            public:
            SmartTeam(Character* lead);
            void attack(Team *enemies) override;
        };

}