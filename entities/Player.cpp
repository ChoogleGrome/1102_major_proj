#include <iostream>
#include <string.h>
#include "Entitiy.h"
#include "Player.h"

Player::Player(){
    NumItems = 0;
}
 
// returns an array of the players items
Artifacts* Player::getItems(){
    return items;
}

// shows the players current level and xp gained.
int Player::getXp(){
    return xp;
}

//adds the amount of experience from enemies
bool Player::increseXp(int amount){
    xp += amount; // adds amount to the current xp
    if(xp > 100){  
        level = level + 1; // if xp reaches a point greater than 100 a level is added
        xp = xp - 100; // and then xp cap is subtracted to rest progression
    }
    return 0;
}


bool Player::addItem(Artifacts newItem){
    newItem = items[NumItems];
    return 0;
}

bool Player::attack(Enemy enemy){
    int dirrectDmg;

    if (enemy.shields - baseDmg < 0 ){
        dirrectDmg = shields - baseDmg;
        updateShieldAmount(-enemy.shields);
    } 

    updateHP(-dirrectDmg);
    return 0;
}

bool Player::defend(){
    shields += shieldGain;
    return 0;
}

Player::~Player(){

}