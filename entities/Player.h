// DYLAN
#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include "../artifacts/Artifacts.h"
#include "Enemy.h"

struct Enemy;

class Player : public Entity {
    public:
        Artifacts items[10] = {
            Herbs(),
            StrangeElixir(),
            Whetstone(),
            HiddenBlade(),
            SpareBattery(),
            BookOnMonsters(),
            ExpiredMilk(),
            BlueGemStone(),
            GreenGemStone(),
            RedGemStone()
        };   // Artifact/items that the player will gather

        int NumItems;       // Number of items
        int xp;             // every 100 xp level up
        int level;          // start lvl 1

        // Constructor
        Player();
        // Player(int size);

        // Update functions
        void increseXp(int amount); // level up check within function
        bool addItem(int index);    // Add item into array of items

        // Gameplay Functions
        void defend();

        // Deconstructor
        ~Player();
};

#endif