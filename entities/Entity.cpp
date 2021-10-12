#include <iostream>
#include <string.h>
#include "Entity.h"
#include <iostream>

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
int Entity::updateHP(int amount){
    currentHp += amount;
    return currentHp;
}

int Entity::updateShields(int amount){
    shields += amount;
    return shields;
}

int Entity::updateShieldAmount(int amount){
    shieldGain += amount;
    return shieldGain;
}

int Entity::updateBaseDmg(int amount){
    baseDmg += amount;
    return baseDmg;
}

int Entity::updateCritChance(int amount){
    critChance += amount;
    return critChance;
}

//Shield Corrosion by 35 percent each turn
int Entity::shieldTurnCorrode(){
    updateShieldAmount(shields * 0.35);
    return shields;
}

int Entity::damage() {
    int crit = rand() % 100;
    if (crit < (this->critChance * 100)) { return this->baseDmg * 1.5; } 
    return this->baseDmg;
}

bool Entity::hurt(int amount){
    int remainingDmg = this->shields - amount;

    if (remainingDmg < 0) {
        this->shields = 0;
        this->currentHp -= abs(remainingDmg);
    } else {
        this->shields -= amount;
    }

    return true;
}

bool Entity::defend() {
    return false;
}

Entity::~Entity(){

}