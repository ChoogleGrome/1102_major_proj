#include <iostream>
#include <string.h>
#include "Entitiy.h"
#include "Player.h"

Player::Player(){

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
    return xp;
}

//currently missing code needs discussion
bool Player::addItem(Artifacts newItem){
       
}

bool Player::attack(Enemy enemy){

}

bool Player::defend(){

}

Player::~Player(){

}