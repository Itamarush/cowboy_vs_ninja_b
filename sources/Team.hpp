#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
#include <vector>
#include <array>

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
        protected:
        vector <Character*> fighters;
        Character *leader;
        
        public:
        Team(Character *leader);
        Team() = default;
        ~Team();
        virtual void add(Character *player);
        virtual Character *closetMemberIsAlive(std::vector<Character *> &members, Character *leader);
        virtual Character *closetEnemyIsAlive(std::vector<Character *> &members, Character *leader);
        void attackEnemy(Character *attacker, Character *victim);
        void setLeader(Character *newLeader);
        void attack(Team * enemy);
        virtual int stillAlive();
        virtual void print();
        ///
            std::vector<Character *> getAliveMembers(const std::vector<Character *> &characters) const;

    };

        class Team2 : public Team
    {
        vector <Character*> fighters2;
        Character *leader;
        
        public:
        Team2(Character *leader);
        void add(Character *player) override;
        int stillAlive() override;
        void print() override;
        std::vector<Character *> getMembers();
        std::vector<Character *> getAliveMembers(const std::vector<Character *> &characters);

    };



}