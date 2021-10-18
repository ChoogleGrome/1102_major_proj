// DYLAN - 7-10 ish enemies, 3 bosses
#ifndef ENEMY_H
#define ENEMY_H
#include "Player.h"
#include "Entity.h"
#include <string>

struct Player;

class Enemy : public Entity {
    protected:
        std::string name = "Empty";
        bool boss = false;      // Is enemy a boss?
        float chance = 0.2;     // Chance of showing up
        int xpDrop = 10;        // Xp dropped per death
        int moveCounter = 0; 
        int *moveset;    
        int moveNum; 
    public:

        // Constructor
        Enemy();
        Enemy(std::string nm, bool isBoss, float chnc, int xp, int *moves, int numMoves, int dimensionTier, int hp, int shieldgain, int basedmg, float critchance); // Movecounter = 0 

        // Get Functions
        bool isBoss();
        int deathXp();
        int showNextMove();
        std::string getName();

        // Gameplay Functions
        void defend();

        virtual void init(int dimensionTier) = 0;

        // Deconstructor
        ~Enemy();
};

//// Normal Enemies ////

// Enemy One
class Grunt : public Enemy {
public:

    // Construntor
<<<<<<< HEAD
    Grunt(int DimensionTier);

    // Attributes
    float chance = 0.6;
    int xpDrop = 5;
    int moveset[3] = {0, 0, 1};
    int moveNum = 3;

    // Deconstructor
    ~Grunt();
=======
    Grunt(std::string nm = "Grunt", bool isBoss = false, float chnc = 0.6, int xp = 5, int *moves = new int[3], int numMoves = 3, int dimensionTier = 1, int hp = 25, int shieldgain = 2, int basedmg = 4, float critchance = 0.1):Enemy(nm, isBoss, chnc, xp, moves, numMoves, dimensionTier, hp, shieldgain, basedmg, critchance) { };
    void init(int dimensionTier);
>>>>>>> 89953b7af25bef9be9c8b7d3348081c25ae1b68f
};

// Enemy Two
class Slime : public Enemy {
public:

    // Constructor
    Slime(std::string nm = "Slime", bool isBoss = false, float chnc = 0.75, int xp = 8, int *moves = new int[5], int numMoves = 5, int dimensionTier = 1, int hp = 30, int shieldgain = 0, int basedmg = 4, float critchance = 0.25):Enemy(nm, isBoss, chnc, xp, moves, numMoves, dimensionTier, hp, shieldgain, basedmg, critchance) { };
    void init(int dimensionTier);
};

// Enemy Three
class Assassin : public Enemy {
public:

    // Constructor
    Assassin(std::string nm = "Assasin", bool isBoss = false, float chnc = 0.4, int xp = 10, int *moves = new int[4], int numMoves = 4, int dimensionTier = 1, int hp = 15, int shieldgain = 0, int basedmg = 6, float critchance = 0.75):Enemy(nm, isBoss, chnc, xp, moves, numMoves, dimensionTier, hp, shieldgain, basedmg, critchance) { };
    void init(int dimensionTier);
    // Attributes
    // std::string name = "Assasin";
    // float chance = 0.4;
    // int xpDrop = 10;
    // int moveset[4] = {2, 0, 2, 1};
    // int moveNum = 4;

    // Deconstructor
};

// Enemy Four
class Thief : public Enemy {
public:

    // Constructor
    Thief(std::string nm = "Thief", bool isBoss = false, float chnc = 0.45, int xp = 2, int *moves = new int[3], int numMoves = 3, int dimensionTier = 1, int hp = 15, int shieldgain = 0, int basedmg = 6, float critchance = 0.4):Enemy(nm, isBoss, chnc, xp, moves, numMoves, dimensionTier, hp, shieldgain, basedmg, critchance) { };
    void init(int dimensionTier);

    // Attributes
    // std::string name = "Theif";
    // float chance = 0.45;
    // int xpDrop = 2;
    // int moveset[3] = {1, 0, 1};
    // int moveNum = 3;

    // Deconstructor
    // ~Theif();
};

// Enemy Five
class Tank : public Enemy {
public:

    // Constructor
    Tank(std::string nm = "Tank", bool isBoss = false, float chnc = 0.3, int xp = 13, int *moves = new int[7], int numMoves = 7, int dimensionTier = 1, int hp = 80, int shieldgain = 10, int basedmg = 3, float critchance = 0.05):Enemy(nm, isBoss, chnc, xp, moves, numMoves, dimensionTier, hp, shieldgain, basedmg, critchance) { };
    void init(int dimensionTier);

    // Attributes
    // std::string name = "Tank";
    // float chance = 0.3;
    // int xpDrop = 13;
    // int moveset[7] = {0, 0, 1, 1, 0, 0, 0};
    // int moveNum = 7;

    // Deconstructor
    // ~Tank();
};

//// Boss Enemies /////

// Boss One
class KingSlime : public Enemy {
public:

    // Constructor
    KingSlime(std::string nm = "King Slime", bool isBoss = true, float chnc = 0.5, int xp = 25, int *moves = new int[10], int numMoves = 10, int dimensionTier = 1, int hp = 150, int shieldgain = 15, int basedmg = 6, float critchance = 0.3):Enemy(nm, isBoss, chnc, xp, moves, numMoves, dimensionTier, hp, shieldgain, basedmg, critchance) { };
    void init(int dimensionTier);

    // Attributes
    // std::string name = "King Slime";
    // bool boss = true;
    // float chance = 0.5;
    // int xpDrop = 25;
    // int moveset[10] = {1, 0, 1, 1, 0, 1, 2, 0, 1, 0};
    // int moveNum = 10;

    // Deconstructor
    // ~KingSlime();
};

// Boss Two
class Dragon : public Enemy {
public:   

    // Constructor
    Dragon(std::string nm = "Dragon", bool isBoss = true, float chnc = 0.3, int xp = 25, int *moves = new int[10], int numMoves = 10, int dimensionTier = 1, int hp = 150, int shieldgain = 5, int basedmg = 8, float critchance = 0.23):Enemy(nm, isBoss, chnc, xp, moves, numMoves, dimensionTier, hp, shieldgain, basedmg, critchance) { };
    void init(int dimensionTier);

    // Attributes
    // std::string name = "Dragon";
    // bool boss = true;
    // float chance = 0.3;
    // int xpDrop = 25;
    // int moveset[10] = {0, 0, 0, 1, 1, 1, 1, 1, 1, 1};
    // int moveNum = 10;

    // Deconstructor
    // ~Dragon();
};

// Boss Three
class Angel : public Enemy {
public:

    // Constructor
    Angel(std::string nm = "Angel", bool isBoss = true, float chnc = 0.6, int xp = 25, int *moves = new int[8], int numMoves = 8, int dimensionTier = 1, int hp = 150, int shieldgain = 3, int basedmg = 10, float critchance = 0.35):Enemy(nm, isBoss, chnc, xp, moves, numMoves, dimensionTier, hp, shieldgain, basedmg, critchance) { };
    void init(int dimensionTier);

    // Attributes
    // std::string name = "Angel";
    // bool boss = true;
    // float chance = 0.6;
    // int xpDrop = 25;
    // int moveset[8] = {1, 1, 0, 1, 2, 2, 1, 0};
    // int moveNum = 8;

    // Deconstructor
    // ~Angel();
};


#endif