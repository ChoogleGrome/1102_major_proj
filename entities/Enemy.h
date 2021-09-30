// DYLAN - 7-10 ish enemies, 3 bosses
#ifndef ENEMY_H
#define ENEMY_H

#include "Entitiy.h"
#include "Player.h"

class Enemy : public Entity {
    private:
        int tierLevel = 0; // What tier level enemy starts showing, 0 - all, 1-3 - sepcific tiers 
        bool boss = false; // Is boss?
        float chance = 0.2; // Chance of showing up
        int xpDrop = 10; // Xp dropped per death

        int moveCounter = 0; // What move they are on, range between 0-moveNum
        int *moveset; // Array of moves, 0 - attack, 1 - defend, 2 - hidden (chnace of either attack or defence)
        int moveNum; // Length of *moveset array

    public:
        // Get Functions
        bool isBoss();
        int deathXp();
        int showNextMove();

        // Gameplay Functions
        bool attack(Player player);
        bool defend();
};

// Example Enemy
class Grunt : public Enemy {
    int chance = 0.5;
    int xpDrop = 5;

    int moveset[3] = {0, 0, 1};
    int moveNum = 3;
};

#endif