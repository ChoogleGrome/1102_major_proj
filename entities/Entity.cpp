#include <iostream>
#include <string.h>
#include "Entity.h"

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
void Entity::updateHP(int amount){
    currentHp += amount;
}

void Entity::updateShields(int amount){
    shields += amount;
}

void Entity::updateShieldAmount(int amount){
    shieldGain += amount;
}

void Entity::updateBaseDmg(int amount){
    baseDmg += amount;
}

void Entity::updateCritChance(int amount){
    critChance += amount;
}

//Shield Corrosion by 35 percent each turn
void Entity::shieldTurnCorrode(){
    updateShieldAmount(shields * 0.35);
}

Entity::~Entity(){

}