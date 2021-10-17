#include <iostream>
#include <string.h>
#include "../artifacts/Artifacts.h"
#include "Entity.h"
#include "Enemy.h"
#include "Player.h"

int main()
{   

    //Testing Player attribute and behaviours
    Player * player = new Player(1);

    player->hp = 100;
    player->baseDmg = 3;
    player->critChance = 0.4;
    player->shields = 0;
    player->shieldGain = 1;

    std::cout << std::endl << "Testing Player" << std::endl;                    // Title
    std::cout << "Players base Damage: " << player->getBaseDmg() << std::endl;   // Base damage check
    std::cout << "Players crit chance: " << player->getCritChance()<< std::endl; // Crit chance check
    std::cout << "Player current HP: " << player->getCurrentHp() << std::endl;   // Current hp check
    std::cout << "Player max HP: " << player->getHP() << std::endl;              // Max hp check
    std::cout << "Player level: " << player->getLevel() << std::endl;            // Level check
    std::cout << "Player shield gains: " << player->getShieldGain() << std::endl;// Shield gains check
    std::cout << "Player shield: " << player->getShields() << std::endl;         // Shield check
    std::cout << "Player xp: " << player->getXp() << std::endl;                  // XP check



    // Testing enemy attribute and behavious
    std::cout << std::endl << std::endl << "Test Enemy" << std::endl;
    Grunt enemy(1);

    std::cout << "Enemy Name: Grunt" << std::endl;
    std::cout << "Enemy HP: " << enemy.hp << std::endl;                         // Hp Check
    std::cout << "Enemy Base Damage: " << enemy.baseDmg << std::endl;           // Base damage check
    std::cout << "Enemy Crit chance: " << enemy.critChance << std::endl;        // Crit chance check

    //Loop to check the enemy moveset
    std::cout << "Enemy Moveset:" << std::endl;
    for(int i = 0; i < enemy.moveNum; i++){
        if (enemy.moveset[i] == 0)
        {
            std::cout << "Defend ";
        } else {
            std::cout << "Attack ";
        }
    }
    std::cout << std::endl;

    //Check if enemy is a boss
    if (enemy.isBoss() == 0)
    {
        std::cout << "This enemy is a normal monster" << std::endl;
    } else {
        std::cout << "This enemy is a boss monster" << std::endl;
    }
    std::cout << "Total XP Drop: " << enemy.xpDrop << std::endl;
    
    return 0;
}