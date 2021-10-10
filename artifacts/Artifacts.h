// LUKE - about 10-15 ish items
#ifndef ARTIFACT_H
#define ARTIFACT_H

#include <string>

class Artifacts {
    public:
        std::string name = "";

        int hp = 0; // HP amount 
        int maxHp = 0; // Amount to increase max hp by

        int shields = 0; // Shield Amount (Start round with x shields)
        int shieldGain = 0; // Gain of shield per usage

        int baseDmg = 0; // Base DMG ammount
        float critChance = 0; // Crit Chance, value between 0-1 

        int amount = 0; // Increment based on copies of items
};

// Example Artifact Declaration 
class Berries : public Artifacts {
    public:
        int hp = 20 * amount; // ALWAYS MULTIPLY BY AMOUNT
}; 

//// Increase health items /////

// Artifact 1
class Herbs : public Artifacts {
    public:
        std::string name = "Herbs";
        int hp = 50 * amount;
};

// Artifact 2
class GreenGemStone : public Artifacts {
    public:
        std::string name = "Green Gem Stone";
        int baseDmg = 5 * amount;
};


//// Increase max hp items ////

// Artifact 1
class StrangeElixir : public Artifacts {
    public:
        std::string name = "Strange Elixir";
        int maxHp = 20 * amount;
};


//// Increase base damage items ////

// Artifact 1
class Whetstone : public Artifacts {
    public:
        std::string name = "Whetstone";
        int baseDmg = 10 * amount;
};

// Artifact 2
class RedGemStone : public Artifacts {
    public:
        std::string name = "Red Gem Stone";
        int baseDmg = 5 * amount;
};

// Artifact 3
class HiddenBlade : public Artifacts {
    public:
        std::string name = "Hidden Blade";
        int hp = 10 * amount;
};


//// Increase shield ////

// Artifact 1
class BlueGemStone : public Artifacts {
    public:
        std::string name = "Red Gem Stone";
        int shields = 5 * amount;
};


//// Increase shield gains ////

// Artifact 1
class SpareBattery : public Artifacts {
    public:
        std::string name = "Spare Battery";
        int shildGains = 10 * amount;
};


//// Crit Chance Stats ////

// Artifact 1
class BookOnMonsters : public Artifacts {
    public:
        std::string name = "Book On Monsters";
        int critChance = 0.05 * amount;
};

//// Mixed Stats ////

// Artifact 1 - Reduce health and increase base damage
class ExpiredMilk : public Artifacts {
    public:
        std::string name = "Expired Milk";
        int hp = -15 * amount;
        int baseDmg = 10 * amount;
};

#endif