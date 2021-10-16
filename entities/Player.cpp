#include <iostream>
#include <string.h>
#include "Entity.h"
#include "Player.h"
#include "../artifacts/Artifacts.h"

Player::Player(){
    NumItems = 0;
    currentHp = 100;
    hp = 100;
    baseDmg = 3;
    critChance = 0.2;
    shields = 0;
    shieldGain = 3;
    level = 0;
    xp = 0;
}
 
// Returns an array of the players items
Artifacts* Player::getItems(){
    return items;
}

// Shows the players current level and xp gained.
int Player::getXp(){
    return xp;
}

// Adds the amount of experience from enemies
void Player::increseXp(int amount){
    xp += amount;           // adds amount to the current xp
    if(xp > 100){  
        level = level + 1;  // if xp reaches a point greater than 100 a level is added
        xp = xp - 100;      // and then xp cap is subtracted to rest progression
    }
}

// Get the player level
int Player::getLevel(){
    return level;
}

// Add artifact to the array
bool Player::addItem(Artifacts newItem){
    newItem = items[NumItems];
    return 0;
}

// Defend (add shields to the player)
void Player::defend(){
    shields += shieldGain;
    //return 0;
}

// Deconstructor
Player::~Player(){

}