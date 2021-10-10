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

bool Enemy::attack(Player player){
    int dirrectDmg;

    if (player.shields - baseDmg < 0 ){
        dirrectDmg = shields - baseDmg;
        updateShieldAmount(-player.shields);
    } 

    updateHP(-dirrectDmg);

}
bool Enemy::defend(Player player){
    shields =  0.35 * player.baseDmg;
    return true;
}
Enemy::~Enemy(){
}
