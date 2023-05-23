/**
 * Demo file for the exercise on binary tree
 *
 * @author Evgeny Hershkovitch Neiterman
 * @since 2023-03
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
#include <random>
#include <chrono>

using namespace std;

#include "sources/Team.hpp" //no need for other includes

using namespace ariel;

double random_float(double min = -100, double max = 100) {
    std::default_random_engine generator(static_cast<unsigned long>(std::chrono::system_clock::now().time_since_epoch().count()));
    std::uniform_real_distribution<double> distribution(min, max);

    return distribution(generator);
}

    auto multi_attack = [](int n, Team &attacker, Team &defender) {
        for (int i = 0; i < n; i++) {
            if (defender.stillAlive()) {
                attacker.attack(&defender);
            }
        }
    };

    auto create_yninja = [](double x = random_float(), double y = random_float()) {
    return new YoungNinja{"Bob", Point{x, y}};
};

auto create_tninja = [](double x = random_float(), double y = random_float()) {
    return new TrainedNinja{"Bob", Point{x, y}};
};

auto create_oninja = [](double x = random_float(), double y = random_float()) {
    return new OldNinja{"Bob", Point{x, y}};
};

auto create_cowboy = [](double x = random_float(), double y = random_float()) {
    return new Cowboy{"Bob", Point{x, y}};
};

int main() {
        auto team_c1 = create_cowboy(0, 0);
        auto team2_c1 = create_cowboy(-2, 0);
        auto team_c2 = create_cowboy(-3, 0);
        auto team2_c2 = create_cowboy(1, 0);//
        auto team2_c3 = create_cowboy(3, 0);//
        auto team_c3 = create_cowboy(5, 0);//
        auto team2_c4 = create_cowboy(-5, 0);

        Team team1{team_c1};
        team1.add(team_c2);
        team1.add(team_c3);
        Team2 team2{team2_c2};
        team2.add(team2_c1);
        team2.add(team2_c3);
        team2.add(team2_c4);

        multi_attack(4, team1, team2);

           // The captain of team2 is the closest enemy to the captain of team1, and therefore should be dead.
        // CHECK((!team2_c2->isAlive() && team2_c1->isAlive() && team2_c3->isAlive() && team2_c4->isAlive()));

        // At this point, the captain should be team2_c3; hence, the next enemy to be attacked by team2 should team_c3.
        multi_attack(6, team2, team1);
        // CHECK((!team_c3->isAlive() && team_c1->isAlive() && team_c2->isAlive()));

        // Killing the new captain
        while (team2_c3->isAlive()) {
            team_c1->reload();
            team_c1->shoot(team2_c3);
        }

        bool aa = !team2_c2->isAlive();
        bool bb = team2_c1->isAlive();
        bool cc = !team2_c3->isAlive();
        bool dd = team2_c4->isAlive();

        //Next captain should be team2_c1, hence, the next enemy to be attacked by team2 should team_cc.
        multi_attack(7, team2, team1);

        int aa1 = team_c3->isAlive();
        int bb1 = team_c1->isAlive();
        int cc1 = !team_c2->isAlive();

}
