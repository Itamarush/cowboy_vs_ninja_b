#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
#include "Point.hpp"
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <sstream>

namespace ariel{
    class Character{
        private:
            Point location;
            int _hp;
            std::string name;
            bool isPlaying;
            bool isCowboy;

        public:
            Character(std::string, Point, int, int, int);
            virtual ~Character() = default;
            Character(const Character &) = default;
            Character &operator=(const Character &) = default;
            Character(Character &&) noexcept = default;
            Character &operator=(Character &&) noexcept = default;
            int getHealth() const;
            int getPower() const;
            bool isAlive();
            double distance(Character*);
            void hit(int);
            virtual std::string print();
            std::string getName();
            Point getLocation();
            void setLocation(Point);
            void setIsPlaying(bool);
            bool getIsPlaying();
            bool getIsNinja();
            bool getIsCowboy();
    };
}

#endif