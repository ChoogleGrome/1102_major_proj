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

<<<<<<< HEAD
Grunt::~Grunt(){

}

//Enemy Two
Slime::Slime(int DimensionTier){
    hp = 30 * DimensionTier;
    currentHp = hp;
    baseDmg = 4 * DimensionTier;
    critChance = 0.25 * DimensionTier;
}

Slime::~Slime(){

}

//Enemy Three
Assassin::Assassin(int DimensionTier){
    hp = 15 * DimensionTier;
    currentHp = hp;
    baseDmg = 4 * DimensionTier;
    critChance = 0.75 * DimensionTier;
}

Assassin::~Assassin(){

}

//Enemy Four
Theif::Theif(int DimensionTier){
    hp = 15 * DimensionTier;
    currentHp = hp;
    baseDmg = 6 * DimensionTier;
    critChance = 0.4 * DimensionTier;
}

Theif::~Theif(){

}

//Enemy Five
Tank::Tank(int DimensionTier){
    hp = 80 * DimensionTier;
    currentHp = hp;
    baseDmg = 3 * DimensionTier;
    critChance = 0.05 * DimensionTier;
}

Tank::~Tank(){

}
//Enemy Six
KingSlime::KingSlime(int DimensionTier){
    hp = 150 * DimensionTier;
    currentHp = hp;
    baseDmg = 6 * DimensionTier;
    critChance = 0.3 * DimensionTier;
}

KingSlime::~KingSlime(){

}

//Enemy Seven
Dragon::Dragon(int DimensionTier){
    hp = 150 * DimensionTier;
    currentHp = hp;
    baseDmg = 8 * DimensionTier;
    critChance = 0.23 * DimensionTier;
=======
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
>>>>>>> 89953b7af25bef9be9c8b7d3348081c25ae1b68f

//Enemy ability to defend itself
void Enemy::defend(){
    shields += shieldGain;
    //return 0;
}

<<<<<<< HEAD
Dragon::~Dragon(){

}

//Enemy Eight
Angel::Angel(int DimensionTier){
    hp = 150 * DimensionTier;
    currentHp = hp;
    baseDmg = 10 * DimensionTier;
    critChance = 0.35 * DimensionTier;
}

Angel::~Angel(){
    
}


=======
//Deconstructor
Enemy::~Enemy(){
}

>>>>>>> 89953b7af25bef9be9c8b7d3348081c25ae1b68f
