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
        void updateHP(int amount);
        void updateShields(int amount);
        void updateShieldAmount(int amount);
        void updateBaseDmg(int amount);
        void updateCritChance(int amount);

        // Shield Corrode Percentage 0.35 per turn
        void shieldTurnCorrode();

        // Gameplay Functions - DO NOT CODE, STILL FIGURING OUT TYPES
        virtual bool attack()=0;
        virtual bool defend();
        ~Entity();
};

#endif
