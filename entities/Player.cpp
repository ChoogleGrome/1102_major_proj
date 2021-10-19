#include <iostream>
#include <string.h>
#include "Entity.h"
#include "Player.h"
#include "../artifacts/Artifacts.h"

Player::Player(){
    NumItems = 0;
    currentHp = 100;
    hp = 100;
    baseDmg = 10;
    critChance = 0.2;
    shields = 0;
    shieldGain = 3;
}

// Adds the amount of experience from enemies
void Player::increseXp(int amount){
    xp += amount;           // adds amount to the current xp
    if(xp > 100){  
        level = level + 1;  // if xp reaches a point greater than 100 a level is added
        xp = xp - 100;      // and then xp cap is subtracted to rest progression
    }
}


// Add artifact to the array
bool Player::addItem(int i){
    items[i].amount++;
    
    // updateHP(items[i].hp * items[i].amount);
    currentHp += items[i].hp * items[i].amount;
    hp += items[i].maxHp * items[i].amount;
    if (currentHp > hp) { currentHp = hp; }

    // updateShieldAmount(items[i].shields * items[i].amount);
    shields += items[i].shields * items[i].amount;
    shieldGain += items[i].shieldGain * items[i].amount;

    // updateBaseDmg(items[i].baseDmg * items[i].amount);
    baseDmg += items[i].baseDmg * items[i].amount;

    // updateCritChance(items[i].critChance * items[i].amount);
    critChance += items[i].critChance * items[i].amount;

    return true;
}


// Defend (add shields to the player)
void Player::defend(){
    shields = shieldGain;
}

// Deconstructor
Player::~Player(){
}