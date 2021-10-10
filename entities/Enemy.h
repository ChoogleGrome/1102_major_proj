// DYLAN - 7-10 ish enemies, 3 bosses
#ifndef ENEMY_H
#define ENEMY_H

#include "Entitiy.h"
#include "Player.h"

class Enemy :public Entity {
    private:
        Enemy();
        int tierLevel = 0; // What tier level enemy starts showing, 0 - all, 1-3 - sepcific tiers 
        bool boss = false; // Is boss?
        float chance = 0.2; // Chance of showing up
        int xpDrop = 10; // Xp dropped per death

        int moveCounter = 0; // What move they are on, range between 0-moveNum
        int *moveset; // Array of moves, 0 - attack, 1 - defend, 2 - hidden (chace of either attack or defence)
        int moveNum; // Length of *moveset array

    public:
        // Get Functions
        bool isBoss();
        int deathXp();
        int showNextMove();

        // Gameplay Functions
        bool attack(Player player);
        bool defend(Player player);
        ~Enemy();
};

//Enemies
class Grunt : public Enemy {
    int chance = 0.6;
    int xpDrop = 5;

    int moveset[3] = {0, 0, 1};
    int moveNum = 3;
};

class Slime : public Enemy {
    int chance = 0.75;
    int xpDrop = 8;

    int moveset[5] = {1, 0, 1, 1, 0};
    int moveNum = 5;
};

class Assassin : public Enemy {
    int chance = 0.4;
    int xpDrop = 10;

    int moveset[4] = {2, 0, 2, 1};
    int moveNum = 4;
};

class Theif : public Enemy {
    int chance = 0.45;
    int xpDrop = 2;

    int moveset[3] = {1, 0, 1};
    int moveNum = 3;
};

class Tank : public Enemy {
    int chance = 0.3;
    int xpDrop = 13;

    int moveset[7] = {0, 0, 1, 1, 0, 0, 0};
    int moveNum = 7;
};

class KingSlime : public Enemy {
    int chance = 0.5;
    bool boss = true;
    int xpDrop = 25;

    int moveset[10] = {1, 0, 1, 1, 0, 1, 2, 0, 1, 0};
    int moveNum = 10;
};

class Dragon : public Enemy {
    int chance = 0.3;
    int xpDrop = 25;
    bool boss = true;

    int moveset[10] = {0, 0, 0, 1, 1, 1, 1, 1, 1, 1};
    int moveNum = 10;
};

class Angel : public Enemy {
    int chance = 0.6;
    int xpDrop = 25;
    bool boss = true;

    int moveset[8] = {1, 1, 0, 1, 2, 2, 1, 0};
    int moveNum = 8;
};


#endif