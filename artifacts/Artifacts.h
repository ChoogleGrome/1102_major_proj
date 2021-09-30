// LUKE - about 10-15 ish items
#ifndef ARTIFACT_H
#define ARTIFACT_H

#include <string>

class Artifacts {
    public:
        std::string name = "";


        int hp = 0; // HP amount 
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

// Artifact 1 - Increase max health
class Herbs : public Artifacts {
    public:
        std::string name = "Herbs";
        int hp = 50 * amount;
};

// Artifact 2 - Reduce health increase base damage
class ExpiredMilk : public Artifacts {
    public:
        std::string name = "Expired Milk";
        int hp = -10 * amount;
        int baseDmg = 10 * amount;
};

// Artifact 3 - Increase Damage
class Knife : public Artifacts {
    public:
        std::string name = "Knife";
        int baseDmg = 5 * amount;
};

// Artifact 4 - Increase Damage
class Sword : public Artifacts {
    public:
        std::string name = "Sword";
        int baseDmg = 10 * amount;
};

#endif