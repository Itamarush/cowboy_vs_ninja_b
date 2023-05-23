#pragma once

#include "Character.hpp"
using namespace ariel;
using namespace std;

namespace ariel
{
	class Ninja : public ariel::Character{
		int speed;

	public:
		Ninja(string name, Point location, int _hp, int speed, int isPlaying, int isCowboy);
		void move(Character*);
		void slash(Character*);
	};
}
