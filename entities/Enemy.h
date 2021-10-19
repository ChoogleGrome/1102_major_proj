// DYLAN - 7-10 ish enemies, 3 bosses
#ifndef ENEMY_H
#define ENEMY_H
#include "Player.h"
#include "Entity.h"
#include <string>

struct Player;

class Enemy : public Entity {
    protected:
        std::string name = "Empty"; // Preset name to "EMPTY"
        int moveCounter = 0;        // Set move counter to 0, this will be used to loop through enemy moveset
        int *moveset;               // Pointer to enemy moveset
        int moveNum;                // Number of moves an enemy will have
    public:

        // Constructor
        Enemy();
        Enemy(std::string nm, int *moves, int numMoves, int dimensionTier, int HP, int shieldgain, int basedmg, float critchance); // Movecounter = 0 

        // Get Functions
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

    // Constructor
    Grunt(std::string nm = "GRUNT", int *moves = new int[3], int numMoves = 3, int dimensionTier = 1, int HP = 25, int shieldgain = 2, int basedmg = 4, float critchance = 0.1):Enemy(nm, moves, numMoves, dimensionTier, HP, shieldgain, basedmg, critchance) { };
    void init(int dimensionTier);
};

// Enemy Two
class Slime : public Enemy {
public:

    // Constructor
    Slime(std::string nm = "SLIME", int *moves = new int[5], int numMoves = 5, int dimensionTier = 1, int HP = 30, int shieldgain = 3, int basedmg = 4, float critchance = 0.25):Enemy(nm, moves, numMoves, dimensionTier, HP, shieldgain, basedmg, critchance) { };
    void init(int dimensionTier);
};

// Enemy Three
class Assassin : public Enemy {
public:

    // Constructor
    Assassin(std::string nm = "ASSASSIN", int *moves = new int[4], int numMoves = 4, int dimensionTier = 1, int HP = 15, int shieldgain = 1, int basedmg = 6, float critchance = 0.75):Enemy(nm, moves, numMoves, dimensionTier, HP, shieldgain, basedmg, critchance) { };
    void init(int dimensionTier);
};

// Enemy Four
class Thief : public Enemy {
public:

    // Constructor
    Thief(std::string nm = "THIEF", int *moves = new int[3], int numMoves = 3, int dimensionTier = 1, int HP = 15, int shieldgain = 2, int basedmg = 6, float critchance = 0.4):Enemy(nm, moves, numMoves, dimensionTier, HP, shieldgain, basedmg, critchance) { };
    void init(int dimensionTier);
};

// Enemy Five
class Tank : public Enemy {
public:

    // Constructor
    Tank(std::string nm = "TANK", int *moves = new int[7], int numMoves = 7, int dimensionTier = 1, int HP = 80, int shieldgain = 7, int basedmg = 3, float critchance = 0.05):Enemy(nm, moves, numMoves, dimensionTier, HP, shieldgain, basedmg, critchance) { };
    void init(int dimensionTier);
};

//// Boss Enemies /////

// Boss One
class KingSlime : public Enemy {
public:

    // Constructor
    KingSlime(std::string nm = "KING SLIME", int *moves = new int[10], int numMoves = 10, int dimensionTier = 1, int HP = 150, int shieldgain = 15, int basedmg = 6, float critchance = 0.3):Enemy(nm, moves, numMoves, dimensionTier, HP, shieldgain, basedmg, critchance) { };
    void init(int dimensionTier);
};

// Boss Two
class Dragon : public Enemy {
public:   

    // Constructor
    Dragon(std::string nm = "DRAGON", int *moves = new int[10], int numMoves = 10, int dimensionTier = 1, int HP = 150, int shieldgain = 5, int basedmg = 8, float critchance = 0.23):Enemy(nm, moves, numMoves, dimensionTier, HP, shieldgain, basedmg, critchance) { };
    void init(int dimensionTier);
};

// Boss Three
class Angel : public Enemy {
public:

    // Constructor
    Angel(std::string nm = "ANGEL", int *moves = new int[8], int numMoves = 8, int dimensionTier = 1, int HP = 150, int shieldgain = 3, int basedmg = 10, float critchance = 0.35):Enemy(nm, moves, numMoves, dimensionTier, HP, shieldgain, basedmg, critchance) { };
    void init(int dimensionTier);
};


#endif