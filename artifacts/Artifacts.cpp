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
    critChance = 0;     // Crit Chance, value between 0-1 

    amount = 0;         // Increment based on copies of items
}

Artifacts::~Artifacts(){}

//// Increase health items /////

// Artifact 1
Herbs::Herbs(){
    name = "Herbs";
    hp = 50;
    desc = "Increases Current Health by 50";
}

Herbs::~Herbs(){}

// Artifact 2
GreenGemStone::GreenGemStone(){
    name = "Green Gem Stone";
    baseDmg = 5;
    critChance = 0.15;
    desc = "Attack Gem, increases Base DMG by 5 and Crit Chance by 0.15";
}

GreenGemStone::~GreenGemStone(){}


//// Increase max hp items ////

// Artifact 1
StrangeElixir::StrangeElixir(){
    name = "Strange Elixir";
    maxHp = 20;
    hp = 20;
    desc = "Increases Max and Current HP by 20";
}

StrangeElixir::~StrangeElixir(){}

//// Increase base damage items ////

// Artifact 1
Whetstone::Whetstone(){
    name = "Whetstone";
    baseDmg = 10;
    desc = "Increases Base Damage by 10";
}

Whetstone::~Whetstone(){}

// Artifact 2
RedGemStone::RedGemStone(){
    name = "Red Gem Stone";
    shieldGain = 5;
    desc = "Shield Gem Stone, Increases shield gain by 5";
}

RedGemStone::~RedGemStone(){}

// Artifact 3
HiddenBlade::HiddenBlade(){
    name = "Hidden Blade";
    critChance = 0.25;
    desc = "Increases Crit Chance by 0.25";
}

HiddenBlade::~HiddenBlade(){}


//// Increase shield ////

// Artifact 1
BlueGemStone::BlueGemStone(){
    name = "Red Gem Stone";
    maxHp = 15;
    hp = 15;
    desc = "Health Gem Stome, Increases Current and Max HP by 15";
}

BlueGemStone::~BlueGemStone(){}

//// Increase shield gains ////

// Artifact 1
SpareBattery::SpareBattery(){
    name = "Spare Battery";
    shieldGain = 10;
    desc = "Increases shield gain by 10";
}

SpareBattery::~SpareBattery(){}


//// Crit Chance Stats ////

// Artifact 1
BookOnMonsters::BookOnMonsters(){
    name = "Book On Monsters";
    critChance = 0.10;
    maxHp = 20;
    desc = "increases Max Hp by 20, but does not heal you. Also increases Crit Chance by 0.1";
}

BookOnMonsters::~BookOnMonsters(){}

//// Mixed Stats ////

// Artifact 1 - Reduce health and increase base damage
ExpiredMilk::ExpiredMilk(){
    name = "Expired Milk";
    hp = -15;
    baseDmg = 30;
    desc = "Decreases HP by 15 but increases Base DMG by 30";
}

ExpiredMilk::~ExpiredMilk(){}