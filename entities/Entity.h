// DYLAN
#ifndef ENTITY_H
#define ENTITY_H

class Entity {
    public: 
        Entity(); 

        int hp;                 // Max HP amount
        int currentHp;          // Current hp amount
        int shields;            // Shield Amount
        int shieldGain;         // Gain of shield per usage
        int baseDmg;            // Base DMG ammount
        float critChance;       // Crit Chance, value between 0-1, IF crit is above 1, auto crit
        
        // Return Functions
        int getHP();            // Get max hp
        int getCurrentHp();     // Returns current health
        int getShields();       // Get shield
        int getShieldGain();    // Get the amount of shield gain
        int getBaseDmg();       // Get base damage
        float getCritChance();  // Get critical chance
        
        int damage();           // Calculate how much damage to deal to opponent

        // Update Functions
        int updateMaxHP(int amount);
        int updateHP(int amount);           // Update Hp
        int updateShields(int amount);      // Update shields
        int updateShieldAmount(int amount); // Update shield gain amount
        int updateBaseDmg(int amount);      // Update base damage
        float updateCritChance(float amount);   // Update crit chance

        // Shield Corrode Percentage 0.35 per turn
        int shieldTurnCorrode();

        // Gameplay Functions
        void hurt(int amount);
        virtual void defend() = 0;

        // Deconstructor
        ~Entity();
};

#endif