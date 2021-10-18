#include <iostream>
#include <string.h>
#include "Entity.h"
#include "Enemy.h"
#include "Player.h"


// Constructor to create intiail attributes for enemy
// Enemy::Enemy() { }

Enemy::Enemy(std::string nm, bool isBoss, float chnc, int xp, int *moves, int numMoves, int dimensionTier, int hP, int shieldgain, int basedmg, float critchance){
    hp = hP * dimensionTier;
    currentHp = hp;
    baseDmg = basedmg * dimensionTier;
    critChance = critchance;
    shields = 0;
    shieldGain = shieldgain * dimensionTier;

    name = nm;
    boss = isBoss;
    chance = chnc;
    xpDrop = xp;
    moveset = moves;
    moveNum = numMoves;
}

void Grunt::init(int dimensionTier) {
    hp *= dimensionTier;
    baseDmg *= dimensionTier;
    shieldGain *= dimensionTier;

    moveset[2] = 1;
}

void Slime::init(int dimensionTier) {
    hp *= dimensionTier;
    baseDmg *= dimensionTier;
    shieldGain *= dimensionTier;

    moveset[2] = 1;
}

void Assassin::init(int dimensionTier) {
    hp *= dimensionTier;
    baseDmg *= dimensionTier;
    shieldGain *= dimensionTier;

    moveset[0] = 2;
    moveset[2] = 2;
    moveset[3] = 1;
}

void Thief::init(int dimensionTier) {
    hp *= dimensionTier;
    baseDmg *= dimensionTier;
    shieldGain *= dimensionTier;

    moveset[0] = 1;
    moveset[2] = 1;
}

void Tank::init(int dimensionTier) {
    hp *= dimensionTier;
    baseDmg *= dimensionTier;
    shieldGain *= dimensionTier;

    moveset[2] = 1;
    moveset[3] = 1;
}

void KingSlime::init(int dimensionTier) {
    hp *= dimensionTier;
    baseDmg *= dimensionTier;
    shieldGain *= dimensionTier;

    moveset[0] = 1;
    moveset[2] = 1;
    moveset[3] = 1;
    moveset[4] = 1;
    moveset[5] = 2;
    moveset[8] = 1;
}

void Dragon::init(int dimensionTier) {
    hp *= dimensionTier;
    baseDmg *= dimensionTier;
    shieldGain *= dimensionTier;

    moveset[3] = 1;
    moveset[4] = 1;
    moveset[5] = 1;
    moveset[6] = 1;
    moveset[7] = 2;
    moveset[8] = 1;
    moveset[9] = 1;
}

void Angel::init(int dimensionTier) {
    hp *= dimensionTier;
    baseDmg *= dimensionTier;
    shieldGain *= dimensionTier;

    moveset[0] = 1;
    moveset[1] = 1;
    moveset[3] = 1;
    moveset[4] = 2;
    moveset[5] = 2;
    moveset[6] = 1;
}

//Determines if enemy is boss or normal
bool Enemy::isBoss(){
    return boss;
}

//Returns the experinece droped by the enemy
int Enemy::deathXp(){
    return xpDrop;
}

//Shows the next move that the enemy will make
int Enemy::showNextMove(){
    return moveset[moveCounter++];

   return 0;
}

std::string Enemy::getName() {
    return name;
}

////// Gameplay functions for the enemy //////

//Enemy ability to defend itself
void Enemy::defend(){
    shields += shieldGain;
    //return 0;
}

//Deconstructor
Enemy::~Enemy(){
}

