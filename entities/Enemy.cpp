#include <iostream>
#include <string.h>
#include "Entity.h"
#include "Enemy.h"
#include "Player.h"


// Constructor to create intiail attributes for enemy
Enemy::Enemy(){
    hp = 0;
    currentHp = hp;
    baseDmg = 0;
    critChance = 0;
    shields = 0;
    shieldGain = 0;
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

    /*
    if (moveCounter == moveNum){
        moveCounter = 0;
    }
    
    std::cout << moveNum << std::endl;

    if (moveset[moveCounter] == 0)
        {
            std::cout << "Enemy Next Move: Defend" << std::endl;;
        } else {
            std::cout << "Enemy Next Move: Attack" << std::endl;;
        }

    return moveset[moveCounter++];
    */

   //This code will not work unless we use pointers, 
   //It is impossible to pass information from the child class (moveSet, moveNum) back to parent class
   //Only Parent class to child class which is why defend works but not this

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


////// List of all possible enemies ///////

//Enemy One
Grunt::Grunt(int DimensionTier){
    hp = 25 * DimensionTier;
    currentHp = hp;
    shields = 0;
    shieldGain = 2;
    baseDmg = 4 * DimensionTier;
    critChance = 0.1 * DimensionTier;
}

//Enemy Two
Slime::Slime(int DimensionTier){
    hp = 30 * DimensionTier;
    currentHp = hp;
    baseDmg = 4 * DimensionTier;
    critChance = 0.25 * DimensionTier;
}

//Enemy Three
Assassin::Assassin(int DimensionTier){
    hp = 15 * DimensionTier;
    currentHp = hp;
    baseDmg = 4 * DimensionTier;
    critChance = 0.75 * DimensionTier;
}

//Enemy Four
Theif::Theif(int DimensionTier){
    hp = 15 * DimensionTier;
    currentHp = hp;
    baseDmg = 6 * DimensionTier;
    critChance = 0.4 * DimensionTier;
}

//Enemy Five
Tank::Tank(int DimensionTier){
    hp = 80 * DimensionTier;
    currentHp = hp;
    baseDmg = 3 * DimensionTier;
    critChance = 0.05 * DimensionTier;
}

//Enemy Six
KingSlime::KingSlime(int DimensionTier){
    hp = 150 * DimensionTier;
    currentHp = hp;
    baseDmg = 6 * DimensionTier;
    critChance = 0.3 * DimensionTier;
}

//Enemy Seven
Dragon::Dragon(int DimensionTier){
    hp = 150 * DimensionTier;
    currentHp = hp;
    baseDmg = 8 * DimensionTier;
    critChance = 0.23 * DimensionTier;

    // add damage co9unter thta increases every turn
}

//Enemy Eight
Angel::Angel(int DimensionTier){
    hp = 150 * DimensionTier;
    currentHp = hp;
    baseDmg = 10 * DimensionTier;
    critChance = 0.35 * DimensionTier;
}



