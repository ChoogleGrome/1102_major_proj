// DYLAN - 7-10 ish enemies, 3 bosses
#ifndef ENEMY_H
#define ENEMY_H
#include "Player.h"
#include "Entity.h"

struct Player;

class Enemy :public Entity {
    private:
        bool boss = false;      // Is enemy a boss?
        float chance = 0.2;     // Chance of showing up
        int xpDrop = 10;        // Xp dropped per death
        int moveCounter = 0;    // What move they are on, range between 0-moveNum
        int *moveset;           // Array of moves, 0 - attack, 1 - defend, 2 - hidden (chace of either attack or defence)
        int moveNum;            // Length of *moveset array
    public:

        // Constructor
        Enemy();

        // Get Functions
        bool isBoss();
        int deathXp();
        int showNextMove();

        // Gameplay Functions
        void defend();

        // Deconstructor
        ~Enemy();
};

//// Normal Enemies ////

// Enemy One
class Grunt : public Enemy {
public:

    // Construntor
    Grunt(int DimensionTier);

    // Attributes
    float chance = 0.6;
    int xpDrop = 5;
    int moveset[3] = {0, 0, 1};
    int moveNum = 3;

    // Deconstructor
    //~Grunt();
};

// Enemy Two
class Slime : public Enemy {
public:

    // Constructor
    Slime(int DimensionTier);

    // Attributes
    float chance = 0.75;
    int xpDrop = 8;
    int moveset[5] = {1, 0, 1, 1, 0};
    int moveNum = 5;

    // Deconstructor
    ~Slime();
};

// Enemy Three
class Assassin : public Enemy {
public:

    // Constructor
    Assassin(int DimensionTier);

    // Attributes
    float chance = 0.4;
    int xpDrop = 10;
    int moveset[4] = {2, 0, 2, 1};
    int moveNum = 4;

    // Deconstructor
    ~Assassin();
};

// Enemy Four
class Theif : public Enemy {
public:

    // Constructor
    Theif(int DimensionTier);

    // Attributes
    float chance = 0.45;
    int xpDrop = 2;
    int moveset[3] = {1, 0, 1};
    int moveNum = 3;

    // Deconstructor
    ~Theif();
};

// Enemy Five
class Tank : public Enemy {
public:

    // Constructor
    Tank(int DimensionTier);

    // Attributes
    float chance = 0.3;
    int xpDrop = 13;
    int moveset[7] = {0, 0, 1, 1, 0, 0, 0};
    int moveNum = 7;

    // Deconstructor
    ~Tank();
};

//// Boss Enemies /////

// Boss One
class KingSlime : public Enemy {
public:

    // Constructor
    KingSlime(int DimensionTier);

    // Attributes
    bool boss = true;
    float chance = 0.5;
    int xpDrop = 25;
    int moveset[10] = {1, 0, 1, 1, 0, 1, 2, 0, 1, 0};
    int moveNum = 10;

    // Deconstructor
    ~KingSlime();
};

// Boss Two
class Dragon : public Enemy {
public:   

    // Constructor
    Dragon(int DimensionTier);

    // Attributes
    bool boss = true;
    float chance = 0.3;
    int xpDrop = 25;
    int moveset[10] = {0, 0, 0, 1, 1, 1, 1, 1, 1, 1};
    int moveNum = 10;

    // Deconstructor
    ~Dragon();
};

// Boss Three
class Angel : public Enemy {
public:

    // Constructor
    Angel(int DimensionTier);

    // Attributes
    bool boss = true;
    float chance = 0.6;
    int xpDrop = 25;
    int moveset[8] = {1, 1, 0, 1, 2, 2, 1, 0};
    int moveNum = 8;

    // Deconstructor
    ~Angel();
};


#endif