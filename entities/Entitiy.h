// DYLAN
#ifndef ENTITY_H
#define ENTITY_H

class Entity {
    private:
        int hp; // max HP amount
        int currentHp; //current hp amount
        int shields; // Shield Amount
        int shieldGain; // Gain of shield per usage
        int baseDmg; // Base DMG ammount
        float critChance; // Crit Chance, value between 0-1, IF crit is above 1, auto crit

    public:  
        // Return Functions
        int getHP(); // gets max hp
        int getCurrentHp(); //returns current health
        int getShields();
        int getShieldGain();
        int getBaseDmg();
        float getCritChance();

        // Update Functions
        bool updateHP(int amount);
        bool updateShields(int amount);
        bool updateShieldAmount(int amount);
        bool updateBaseDmg(int amount);
        bool updateCritChance(int amount);

        // Shield Corrode Percentage 0.35 per turn
        bool shieldTurnCorrode();

        // Gameplay Functions - DO NOT CODE, STILL FIGURING OUT TYPES
        virtual bool attack();
        virtual bool defend();
};

#endif