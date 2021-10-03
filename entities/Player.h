// DYLAN
#ifndef PLAYER_H
#define PLAYER_H

#include "Entitiy.h"
#include "../artifacts/Artifacts.h"
#include "Enemy.h"

class Player : public Entity {
    private:
        Artifacts *items; 
        int xp; // every 100 xp level up
        int level; // start lvl 1

    private:
        // Init
        Player();

        // Get functions
        Artifacts* getItems(); // Return array of items
        int getXp(); // XP
        int getLevel(); // Levels

        // Update functions
        bool increseXp(int amount); // level up check within function
        bool addItem(Artifacts newItem); // Add item into array of items

        // Gameplay Functions
        bool attack(Enemy enemy);
        bool defend();
};

#endif