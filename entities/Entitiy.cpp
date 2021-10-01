#include <iostream>
#include <string.h>
#include "Entitiy.h"

Entity::Entity(){

}

//Return functions
int Entity::getHP(){
    return hp;
}

int Entity::getCurrentHp(){
    return currentHp;
}

int Entity::getShields(){
    return shields;
}

int Entity::getShieldGain(){
    return shieldGain;
}

int Entity::getBaseDmg(){
    return baseDmg;
}

float Entity::getCritChance(){
    return critChance;
}

//Update Functions
bool Entity::updateHP(int amount){
    currentHp += amount;
}

bool Entity::updateShields(int amount){
    shields += amount;
}

bool Entity::updateShieldAmount(int amount){
    shieldGain += amount;
}

bool Entity::updateBaseDmg(int amount){
    baseDmg += amount;
}

bool Entity::updateCritChance(int amount){
    critChance += amount;
}

//Shield Corrosion by 35 percent each turn
bool Entity::shieldTurnCorrode(){
    if (shields = 0){
        return false;
    }
    shields = shields * 0.35;
    return true;
}

Entity::~Entity(){

}