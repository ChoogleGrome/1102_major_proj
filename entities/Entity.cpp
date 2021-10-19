#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "Entity.h"

Entity::Entity(){

}

// Return max hp
int Entity::getHP(){
    return hp;
}

// Return current hp
int Entity::getCurrentHp(){
    return currentHp;
}

// Return shields
int Entity::getShields(){
    return shields;
}

// Return the amount of shield a player or a monster can gain when defending
int Entity::getShieldGain(){
    return shieldGain;
}

// Return damage
int Entity::getBaseDmg(){
    return baseDmg;
}

// Return critcal chance
float Entity::getCritChance(){
    return critChance;
}


int Entity::updateMaxHP(int amount){
    hp += amount;
    return hp;
}

// Update Functions
int Entity::updateHP(int amount){
    currentHp += amount;
    if (currentHp > hp) { currentHp = hp; }
    return currentHp;
}

// Update shield 
int Entity::updateShields(int amount){
    shields += amount;
    return shields;
}

// Update shield gain amount
int Entity::updateShieldAmount(int amount){
    shieldGain += amount;
    return shieldGain;
}

// Update base damage
int Entity::updateBaseDmg(int amount){
    baseDmg += amount;
    return baseDmg;
}

// Update critical chance
float Entity::updateCritChance(float amount){
    critChance += amount;
    return critChance;
}

// Reduce shield by 35 percent each turn
int Entity::shieldTurnCorrode(){
    updateShieldAmount(shields * 0.35);
    return shields;
}

// Return damage
int Entity::damage() {
    float crit = ((float)(std::rand() % 101 - 1))/100; // Casting is needed is rand is int by default

    // Determining whether the damage should crit or not
    if (crit < (this->critChance)) { 
        return floor(this->baseDmg * 1.5);
    } 

    // Return damage
    return floor(this->baseDmg);
}

// Inflict damage to self
void Entity::hurt(int amount){

    // Determining amount of remaining damage is left once shield is broken
    int remainingDmg = this->shields - amount;

    // If shield is lower than damage, set shield to zero and subtract remaining damage to hp
    if (remainingDmg <= 0) {
        this->shields = 0;
        this->currentHp -= abs(remainingDmg);

    // If shield is higher than damage reduce shield only
    } else {
        this->shields -= amount;
    }
}

// Pure virtual defend
void Entity::defend() {}

// Deconstructor
Entity::~Entity(){

}