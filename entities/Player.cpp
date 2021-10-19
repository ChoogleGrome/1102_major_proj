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
    level = 0;
    xp = 0;

    items[0] = Herbs();

    // items = new Artifacts[5];
}

 
// Player::Player(int size){
//     NumItems = 0;
//     currentHp = 100;
//     hp = 100;
//     baseDmg = 3;
//     critChance = 0.2;
//     shields = 0;
//     shieldGain = 3;
//     level = 0;
//     xp = 0;

    
//     items = new Artifacts[size];
// }


// Returns an array of the players items
// void Player::getItems(){
//     for (int i = 0; i < NumItems; i++){
//         std::cout << items[i].name << ", "; 
//     }
//    std::cout << std::endl;
// }


// Shows the players current level and xp gained.s
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
bool Player::addItem(int i){
    items[i].amount++;
    NumItems++;

    this->updateMaxHP(items[i].maxHp * items[i].amount);
    
    this->updateHP(items[i].hp * items[i].amount);
    hp += items[i].maxHp * items[i].amount;

    this->updateShieldAmount(items[i].shields * items[i].amount);
    shieldGain = items[i].shieldGain * items[i].amount;

    this->updateBaseDmg(items[i].baseDmg * items[i].amount);
    
    this->updateCritChance(items[i].critChance * items[i].amount);

    return true;
}


// Defend (add shields to the player)
void Player::defend(){
    shields += shieldGain;
}

// Deconstructor
Player::~Player(){
}