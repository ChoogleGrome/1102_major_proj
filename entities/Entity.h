// DYLAN
#ifndef ENTITY_H
#define ENTITY_H

class Entity {
    protected:
       

    public: 
        Entity(); 
        int hp; // max HP amount
        int currentHp; //current hp amount
        int shields; // Shield Amount
        int shieldGain; // Gain of shield per usage
        int baseDmg; // Base DMG ammount
        float critChance; // Crit Chance, value between 0-1, IF crit is above 1, auto crit
        // Return Functions
        int getHP(); // gets max hp
        int getCurrentHp(); //returns current health
        int getShields();
        int getShieldGain();
        int getBaseDmg();
        float getCritChance();

        // Update Functions
        int updateHP(int amount);
        int updateShields(int amount);
        int updateShieldAmount(int amount);
        int updateBaseDmg(int amount);
        int updateCritChance(int amount);

        // Shield Corrode Percentage 0.35 per turn
        int shieldTurnCorrode();

        // Gameplay Functions - DO NOT CODE, STILL FIGURING OUT TYPES
        bool attack();
        bool defend();
        //virtual bool attack();
        //virtual bool defend();
        ~Entity();
};

#endif
