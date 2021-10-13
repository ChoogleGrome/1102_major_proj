#include <iostream>
#include <string>
#include "../artifacts/Artifacts.h"
#include "Entity.h"
#include "Enemy.h"
#include "Player.h"

int main()
{   
    //Player attribute
    std::cout << std::endl << "Testing Player" << std::endl;

    Player player;
    player.hp = 100;
    player.baseDmg = 3;
    player.critChance = 0.4;
    player.shields = 0;
    player.shieldGain = 1;


    std::cout << "Players base Damage: " << player.getBaseDmg() << std::endl;
    std::cout << "Players crit chance: " << player.getCritChance()<< std::endl;
    std::cout << "Player current HP: " << player.getCurrentHp() << std::endl;
    std::cout << "Player max HP: " << player.getHP() << std::endl;
    std::cout << "Player level: " << player.getLevel() << std::endl;
    std::cout << "Player shield gains: " << player.getShieldGain() << std::endl;
    std::cout << "Player shield: " << player.getShields() << std::endl;
    std::cout << "Player xp: " << player.getXp() << std::endl;

    // creating a basic enemy grunt


    std::cout << std::endl << std::endl << "Test Enemy" << std::endl;
    Grunt enemy(1);

    std::cout << "Enemy Name: Grunt" << std::endl;
    std::cout << "Enemy HP: " << enemy.hp << std::endl;
    std::cout << "Enemy Base Damage: " << enemy.baseDmg << std::endl;
    std::cout << "Enemy Crit chance: " << enemy.critChance << std::endl;

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

    //Check if anime is a boss
    if (enemy.isBoss() == 0)
    {
        std::cout << "This enemy is a normal monster" << std::endl;
    } else {
        std::cout << "This enemy is a boss monster" << std::endl;
    }
    std::cout << "Total XP Drop: " << enemy.xpDrop << std::endl;

    return 0;
}
