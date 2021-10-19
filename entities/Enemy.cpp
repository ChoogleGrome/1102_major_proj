#include <iostream>
#include <string.h>
#include "Entity.h"
#include "Enemy.h"
#include "Player.h"

// Enemy contructor

// Enemy(enemy name, ref to moves array, )
Enemy::Enemy(std::string nm, int *moves, int numMoves, int HP, int shieldgain, int basedmg, float critchance){
    hp = HP;
    currentHp = hp;
    baseDmg = basedmg;
    critChance = critchance;
    shields = 0;
    shieldGain = shieldgain;

    name = nm;
    moveset = moves;
    moveNum = numMoves;
}

// Setting enemy Grunt difficulty and moveset
void Grunt::init(int dimensionTier) {
    hp *= dimensionTier;
    currentHp = hp;
    baseDmg *= dimensionTier;
    shieldGain *= dimensionTier;

    // Enemy Moveset
    moveset[0] = 0;
    moveset[1] = 0;
    moveset[2] = 1;
}

// Setting enemy Slime difficulty and moveset
void Slime::init(int dimensionTier) {
    hp *= dimensionTier;
    currentHp = hp;
    baseDmg *= dimensionTier;
    shieldGain *= dimensionTier;

    moveset[0] = 0;
    moveset[1] = 0;
    moveset[2] = 1;
}

// Setting enemy Assassin difficulty and moveset
void Assassin::init(int dimensionTier) {
    hp *= dimensionTier;
    currentHp = hp;
    baseDmg *= dimensionTier;
    shieldGain *= dimensionTier;

    // Moveset
    moveset[0] = 2;
    moveset[1] = 0;
    moveset[2] = 2;
    moveset[3] = 1;
}

// Setting enemy Thief difficulty and moveset
void Thief::init(int dimensionTier) {
    hp *= dimensionTier;
    currentHp = hp;
    baseDmg *= dimensionTier;
    shieldGain *= dimensionTier;

    // Moveset
    moveset[0] = 1;
    moveset[1] = 0;
    moveset[2] = 1;
}

// Setting enemy Tank difficulty and moveset
void Tank::init(int dimensionTier) {
    hp *= dimensionTier;
    currentHp = hp;
    baseDmg *= dimensionTier;
    shieldGain *= dimensionTier;

    // Moveset
    moveset[0] = 0;
    moveset[1] = 0;
    moveset[2] = 1;
    moveset[3] = 1;
}

// Setting enemy King Slime difficulty and moveset
void KingSlime::init(int dimensionTier) {
    hp *= dimensionTier;
    currentHp = hp;
    baseDmg *= dimensionTier;
    shieldGain *= dimensionTier;

    // Moveset
    moveset[0] = 1;
    moveset[1] = 0;
    moveset[2] = 1;
    moveset[3] = 1;
    moveset[4] = 1;
    moveset[5] = 2;
    moveset[6] = 0;
    moveset[7] = 0;
    moveset[8] = 1;
}

// Setting enemy Dragon difficulty and moveset
void Dragon::init(int dimensionTier) {
    hp *= dimensionTier;
    currentHp = hp;
    baseDmg *= dimensionTier;
    shieldGain *= dimensionTier;

    // Moveset
    moveset[0] = 0;
    moveset[1] = 0;
    moveset[2] = 0;
    moveset[3] = 1;
    moveset[4] = 1;
    moveset[5] = 1;
    moveset[6] = 1;
    moveset[7] = 2;
    moveset[8] = 1;
    moveset[9] = 1;
}

// Setting enemy Grunt difficulty and moveset
void Angel::init(int dimensionTier) {
    hp *= dimensionTier;
    currentHp = hp;
    baseDmg *= dimensionTier;
    shieldGain *= dimensionTier;

    // Moveset
    moveset[0] = 1;
    moveset[1] = 1;
    moveset[2] = 0;
    moveset[3] = 1;
    moveset[4] = 2;
    moveset[5] = 2;
    moveset[6] = 1;
}


//Shows the next move that the enemy will make
int Enemy::showNextMove(){

    // Reset move counter when it reaches the end of enemy moveset
    if (moveCounter == moveNum){
        moveCounter = 0;
    }
    return moveset[moveCounter++];

    return 0;
}

// Get the name of the enemy
std::string Enemy::getName() {
    return name;
}

////// Gameplay functions for the enemy //////

//Enemy ability to defend itself, gain shields
void Enemy::defend(){
    shields += shieldGain;
}

//Deconstructor
Enemy::~Enemy(){
}

