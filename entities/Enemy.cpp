#include <iostream>
#include <string.h>
#include "Entity.h"
#include "Enemy.h"
#include "Player.h"

Enemy::Enemy(){
    hp = 0;
    currentHp = hp;
    shields = 0;
    baseDmg = 0;
    critChance = 0;
}


//returns boss
bool Enemy::isBoss(){
    return boss;
}

//retuns the experinece droped
int Enemy::deathXp(){
    return xpDrop;
}

//Shows the Next move that the enemy will make
int Enemy::showNextMove(){
    return moveset[moveNum];
}

//gameplay functions for the enemy

bool Enemy::attack(Player player){
    int remainingDmg = 0;;
    if (player.shields >= 0){
        remainingDmg = player.shields - this->baseDmg;
        
        player.shields -= this->baseDmg;

        if (remainingDmg < 0){
            player.shields = 0;
            player.currentHp -= abs(remainingDmg);
        } 
    }
    return true;
}

bool Enemy::defend(Player player){
    shields =  0.35 * player.baseDmg;
    return true;
}

Enemy::~Enemy(){
}




Grunt::Grunt(int DimensionTier){
    hp = 25 * DimensionTier;
    currentHp = hp;
    shields = 0;
    baseDmg = 4 * DimensionTier;
    critChance = 0.1 * DimensionTier;
}

Grunt::~Grunt(){
    
}


Slime::Slime(int DimensionTier){
    hp = 30 * DimensionTier;
    currentHp = hp;
    baseDmg = 4 * DimensionTier;
    critChance = 0.25 * DimensionTier;
}

Assassin::Assassin(int DimensionTier){
    hp = 15 * DimensionTier;
    currentHp = hp;
    baseDmg = 4 * DimensionTier;
    critChance = 0.75 * DimensionTier;
}

Theif::Theif(int DimensionTier){
    hp = 15 * DimensionTier;
    currentHp = hp;
    baseDmg = 6 * DimensionTier;
    critChance = 0.4 * DimensionTier;
}

Tank::Tank(int DimensionTier){
    hp = 80 * DimensionTier;
    currentHp = hp;
    baseDmg = 3 * DimensionTier;
    critChance = 0.05 * DimensionTier;
}

KingSlime::KingSlime(int DimensionTier){
    hp = 150 * DimensionTier;
    currentHp = hp;
    baseDmg = 6 * DimensionTier;
    critChance = 0.3 * DimensionTier;
}

Dragon::Dragon(int DimensionTier){
    hp = 150 * DimensionTier;
    currentHp = hp;
    baseDmg = 8 * DimensionTier;
    critChance = 0.23 * DimensionTier;

    // add damage co9unter thta increases every turn
}

Angel::Angel(int DimensionTier){
    hp = 150 * DimensionTier;
    currentHp = hp;
    baseDmg = 10 * DimensionTier;
    critChance = 0.35 * DimensionTier;
}



