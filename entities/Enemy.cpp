#include <iostream>
#include <string.h>
#include "Entity.h"
#include "Enemy.h"
#include "Player.h"

Enemy::Enemy(){
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
/*
bool Enemy::attack(Player player){
    int dirrectDmg;

    if (player.shields - baseDmg < 0 ){
        dirrectDmg = shields - baseDmg;
        updateShieldAmount(-player.shields);
    } 

    updateHP(-dirrectDmg);
    return 0;
}
*/
bool Enemy::defend(Player player){
    shields =  0.35 * player.baseDmg;
    return true;
}

Enemy::~Enemy(){
}




Grunt::Grunt(int DimensionTeir){
    hp = 25 * DimensionTeir;
    currentHp = hp;
    baseDmg = 4 * DimensionTeir;
    critChance = 0.1 * DimensionTeir;
}

Grunt::~Grunt(){
    
}


Slime::Slime(int DimensionTeir){
    hp = 30 * DimensionTeir;
    currentHp = hp;
    baseDmg = 4 * DimensionTeir;
    critChance = 0.25 * DimensionTeir;
}

Assassin::Assassin(int DimensionTeir){
    hp = 15 * DimensionTeir;
    currentHp = hp;
    baseDmg = 4 * DimensionTeir;
    critChance = 0.75 * DimensionTeir;
}

Theif::Theif(int DimensionTeir){
    hp = 15 * DimensionTeir;
    currentHp = hp;
    baseDmg = 6 * DimensionTeir;
    critChance = 0.4 * DimensionTeir;
}

Tank::Tank(int DimensionTeir){
    hp = 80 * DimensionTeir;
    currentHp = hp;
    baseDmg = 3 * DimensionTeir;
    critChance = 0.05 * DimensionTeir;
}

KingSlime::KingSlime(int DimensionTeir){
    hp = 150 * DimensionTeir;
    currentHp = hp;
    baseDmg = 6 * DimensionTeir;
    critChance = 0.3 * DimensionTeir;
}

Dragon::Dragon(int DimensionTeir){
    hp = 150 * DimensionTeir;
    currentHp = hp;
    baseDmg = 8 * DimensionTeir;
    critChance = 0.23 * DimensionTeir;

    // add damage co9unter thta increases every turn
}

Angel::Angel(int DimensionTeir){
    hp = 150 * DimensionTeir;
    currentHp = hp;
    baseDmg = 10 * DimensionTeir;
    critChance = 0.35 * DimensionTeir;
}



