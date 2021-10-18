// LUKE - about 10-15 ish items
#ifndef ARTIFACT_H
#define ARTIFACT_H

#include <string>

class Artifacts {
    public:

        Artifacts();

        std::string name;

        int hp;             // HP amount 
        int maxHp;          // Amount to increase max hp by

        int shields;        // Shield Amount (Start round with x shields)
        int shieldGain;     // Gain of shield per usage

        int baseDmg;        // Base DMG ammount
        float critChance;   // Crit Chance, value between 0-1 

        int amount = 0;         // Increment based on copies of items

        ~Artifacts();
};


//// Increase health items /////

// Artifact 1
class Herbs : public Artifacts {
    public:
        Herbs();
        ~Herbs();
};

// Artifact 2
class GreenGemStone : public Artifacts {
    public:
        GreenGemStone();
        ~GreenGemStone();
};


//// Increase max hp items ////

// Artifact 1
class StrangeElixir : public Artifacts {
    public:
        StrangeElixir();
        ~StrangeElixir();
};


//// Increase base damage items ////

// Artifact 1
class Whetstone : public Artifacts {
    public:
        Whetstone();
        ~Whetstone();
};

// Artifact 2
class RedGemStone : public Artifacts {
    public:
        RedGemStone();
        ~RedGemStone();
};

// Artifact 3
class HiddenBlade : public Artifacts {
    public:
        HiddenBlade();
        ~HiddenBlade();
};


//// Increase shield ////

// Artifact 1
class BlueGemStone : public Artifacts {
    public:
        BlueGemStone();
        ~BlueGemStone();
};


//// Increase shield gains ////

// Artifact 1
class SpareBattery : public Artifacts {
    public:
        SpareBattery();
        ~SpareBattery();
};


//// Crit Chance Stats ////

// Artifact 1
class BookOnMonsters : public Artifacts {
    public:
        BookOnMonsters();
        ~BookOnMonsters();
};

//// Mixed Stats ////

// Artifact 1 - Reduce health and increase base damage
class ExpiredMilk : public Artifacts {
    public:
        ExpiredMilk();
        ~ExpiredMilk();
};

#endif