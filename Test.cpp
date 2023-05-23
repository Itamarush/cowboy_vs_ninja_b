#include "doctest.h"
#include <iostream>
#include <string>
#include "sources/Character.hpp"
#include "sources/Point.hpp"
#include "sources/Team.hpp"

using namespace ariel;
using namespace std;

TEST_CASE("Point class tests") {
    Point p1(1.0,2.0), p2(9.0,8.0);
    
    CHECK(p1.getX() == 1.0);
    CHECK(p1.getY() == 2.0);
    CHECK(p2.getX() == 9.0);
    CHECK(p2.getY() == 8.0);

    CHECK(p1.distance(p2) == 10.0);
    CHECK(p1.print().compare("(1.0,2.0)") == 0);

    Point p3(0.0, 0.0), p4(3.0, 4.0);

    Point p5 = Point::moveTowards(p3 ,p4, 2.0);
    CHECK(p5.getX() == 1.2);
    CHECK(p5.getY() == 1.6);

    Point p6 = Point::moveTowards(p3, p4, 5.0);
    CHECK(p6.getX() == 3.0);
    CHECK(p6.getY() == 4.0);

}

TEST_CASE("Cowboy class tests") {
    Point p1(0.0,0.0), p2(3.0,4.0);
    Cowboy *Chen = new Cowboy("Chen", p1);
    Cowboy *Nadav = new Cowboy("Nadav", p2);
    
    CHECK_EQ(Chen->getName(), "Chen");
    CHECK_EQ(Nadav->getName(), "Nadav");
    
    double dest = Chen->distance(Nadav);
    CHECK(dest == 5.0);
    CHECK(Chen->isAlive() == true);
    CHECK(Chen->hasBullets() == true);
    CHECK(Nadav->isAlive() == true);
    CHECK(Nadav->hasBullets() == true);

    for(int i = 0; i < 6; i++)
        Chen->shoot(Nadav);
    
    CHECK(Chen->hasBullets() == false);
    CHECK(Nadav->isAlive() == true);

    Chen->reload();

    CHECK(Chen->hasBullets() == true);

    for(int i = 0; i < 5; i++)
        Chen->shoot(Nadav);

    CHECK(Chen->hasBullets() == true);
    CHECK(Nadav->isAlive() == false);

    CHECK_THROWS(Chen->shoot(Nadav)); // Character is already dead
    CHECK_THROWS(Chen->shoot(Chen)); // Impossible situation
    CHECK_THROWS(Chen->shoot(NULL)); // Impossible situation

}

TEST_CASE("Ninjas class tests") {
    Point p1(0.0,0.0), p2(3.0,4.0), p3(-1.0,-5.0);
    OldNinja* Chen = new OldNinja("Chen", p2);
    YoungNinja* Nadav = new YoungNinja("Nadav", p1);
    TrainedNinja* Sesko = new TrainedNinja("Sesko", p3);

    CHECK_EQ(Chen->getName(), "Chen");
    CHECK_EQ(Nadav->getName(), "Nadav");
    CHECK_EQ(Sesko->getName(), "Sesko");
}

TEST_CASE("Test case: No characters in the team")
{
    Team team(nullptr);

    CHECK(team.stillAlive() == 0);
}

TEST_CASE("Test case: Adding characters to the team")
{
    Cowboy* cowboy = new Cowboy("John", Point(1.0, 1.0));
    Team team(cowboy);

    CHECK(team.stillAlive() == 1);

    team.add(new OldNinja("Mike", Point(2.0, 2.0)));
    team.add(new YoungNinja("Kate", Point(3.0, 3.0)));

    CHECK(team.stillAlive() == 3);
}

TEST_CASE("Test case: Copy constructor")
{
    Cowboy* cowboy = new Cowboy("John", Point(1.0, 1.0));
    Team teamA(cowboy);
    teamA.add(new OldNinja("Mike", Point(2.0, 2.0)));
    teamA.add(new YoungNinja("Kate", Point(3.0, 3.0)));

    Team teamB(teamA);

    CHECK(teamB.stillAlive() == 3);
}

TEST_CASE("Test case: Assignment operator")
{
    Cowboy* cowboy = new Cowboy("John", Point(1.0, 1.0));
    Team teamA(cowboy);
    teamA.add(new OldNinja("Mike", Point(2.0, 2.0)));
    teamA.add(new YoungNinja("Kate", Point(3.0, 3.0)));

    Team teamB(new Cowboy("Alex", Point(4.0, 4.0)));
    teamB.add(new TrainedNinja("Sam", Point(5.0, 5.0)));

    teamB = teamA;

    CHECK(teamB.stillAlive() == 3);
}

TEST_CASE("Test case: Attacking another team")
{
    Cowboy* cowboyA = new Cowboy("John", Point(1.0, 1.0));
    Team teamA(cowboyA);
    teamA.add(new OldNinja("Mike", Point(2.0, 2.0)));

    Cowboy* cowboyB = new Cowboy("Alex", Point(3.0, 3.0));
    Team teamB(cowboyB);
    teamB.add(new TrainedNinja("Sam", Point(4.0, 4.0)));

    teamA.attack(&teamB);

    CHECK(teamA.stillAlive() >= 1);
    CHECK(teamB.stillAlive() >= 1);
}

TEST_CASE("Test case: Attacking an empty team")
{
    Cowboy* cowboyA = new Cowboy("John", Point(1.0, 1.0));
    Team teamA(cowboyA);

    Team teamB(nullptr);

    teamA.attack(&teamB);

    CHECK(teamA.stillAlive() >= 1);
    CHECK(teamB.stillAlive() == 0);
}

TEST_CASE("Test case: Attacking with no players in the team")
{
    Team teamA(nullptr);
    Team teamB(new OldNinja("Mike", Point(1.0, 1.0)));

    teamA.attack(&teamB);

    CHECK(teamA.stillAlive() == 0);
    CHECK(teamB.stillAlive() >= 1);
}