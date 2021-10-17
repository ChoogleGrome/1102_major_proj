#include <iostream>
#include <string.h>

#include "Artifacts.h"

Artifacts::Artifacts(){
    name = "?";

    hp = 0;             // HP amount 
    maxHp = 0;          // Amount to increase max hp by

    shields = 0;        // Shield Amount (Start round with x shields)
    shieldGain = 0;     // Gain of shield per usage

    baseDmg = 0;        // Base DMG ammount
    critChance = 0;   // Crit Chance, value between 0-1 

    amount = 0;         // Increment based on copies of items
}

Artifacts::~Artifacts(){}

//// Increase health items /////

// Artifact 1
Herbs::Herbs(){
    name = "Herbs";
    hp = 50 * amount;
}

Herbs::~Herbs(){}

// Artifact 2
GreenGemStone::GreenGemStone(){
    name = "Green Gem Stone";
    baseDmg = 5 * amount;
}

GreenGemStone::~GreenGemStone(){}


//// Increase max hp items ////

// Artifact 1
StrangeElixir::StrangeElixir(){
    name = "Strange Elixir";
    maxHp = 20 * amount;
}

StrangeElixir::~StrangeElixir(){}

//// Increase base damage items ////

// Artifact 1
Whetstone::Whetstone(){
    name = "Whetstone";
    baseDmg = 10 * amount;
}

Whetstone::~Whetstone(){}

// Artifact 2
RedGemStone::RedGemStone(){
    name = "Red Gem Stone";
    baseDmg = 5 * amount;
}

RedGemStone::~RedGemStone(){}

// Artifact 3
HiddenBlade::HiddenBlade(){
    name = "Hidden Blade";
    hp = 10 * amount;
}

HiddenBlade::~HiddenBlade(){}


//// Increase shield ////

// Artifact 1
BlueGemStone::BlueGemStone(){
    name = "Red Gem Stone";
    shields = 5 * amount;
}

BlueGemStone::~BlueGemStone(){}

//// Increase shield gains ////

// Artifact 1
SpareBattery::SpareBattery(){
    name = "Spare Battery";
    shieldGain = 10 * amount;
}

SpareBattery::~SpareBattery(){}


//// Crit Chance Stats ////

// Artifact 1
BookOnMonsters::BookOnMonsters(){
    name = "Book On Monsters";
    critChance = 0.10 * amount;
}

BookOnMonsters::~BookOnMonsters(){}

//// Mixed Stats ////

// Artifact 1 - Reduce health and increase base damage
ExpiredMilk::ExpiredMilk(){
    name = "Expired Milk";
    hp = -15 * amount;
    baseDmg = 10 * amount;
}

ExpiredMilk::~ExpiredMilk(){}