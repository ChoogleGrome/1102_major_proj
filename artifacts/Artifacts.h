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

#endif