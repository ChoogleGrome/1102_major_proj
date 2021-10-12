#include <iostream>
#include <string>
#include "../artifacts/Artifacts.h"
#include "Entity.h"
#include "Enemy.h"
#include "Player.h"

int main()
{
    //testing the Players functions
    Player player;
    /*
    player.hp = 100;
    player.baseDmg = 3;
    player.critChance = 0.4;
    player.shields = 0;
    player.shieldGain = 1;
    */
/*

    std::cout << "the Players base Damage is: " << player.getBaseDmg() << std::endl;
    std::cout << "the Players crit chance is: " << player.getCritChance()<< std::endl;
    std::cout << "the Players currnet hp is: " << player.getCurrentHp() << std::endl;
    std::cout << "the Players max hp is: " << player.getHP() << std::endl;
    std::cout << "the Players level  is: " << player.getLevel() << std::endl;
    std::cout << "the Players increase in sheilds  is: " << player.getShieldGain() << std::endl;
    std::cout << "the Players shields is: " << player.getShields() << std::endl;
    std::cout << "the Players xp is: " << player.getXp() << std::endl;

*/
    // creating a basic enemy grunt
    Grunt enemy(1);

    std::cout << "Enemy Name Grunt" << std::endl;
    std::cout << "HP: " << enemy.hp << std::endl;
    std::cout << "Base Damage: " << enemy.baseDmg << std::endl;
    std::cout << "Crit chance: " << enemy.critChance << std::endl;

    //Loop to check the enemy moveset
    std::cout << "Enemy Moveset" << std::endl;
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

    //Test combat
    std::cout << std::endl << "Test player shields" << std::endl;
    std::cout << "Player shield: " << player.getShields() << std::endl;
    player.defend();
    std::cout << "Player shield: " << player.getShields() << std::endl;

    std::cout << std::endl << "Test enemy shields" << std::endl;
    std::cout << "Enemy shield: " << enemy.shields << std::endl; 
    enemy.defend(player);
    std::cout << "Enemy shield: " << enemy.shields << std::endl; 

    enemy.attack(player);

    std::cout << std::endl << std::endl;
    std::cout << "The player took: " << enemy.baseDmg << " damage" << std::endl;

    //Hp still remains the same
    std::cout << "Player Hp: " << player.getCurrentHp() << std::endl;
    std::cout << "Player Shield: " << player.getShields() << std::endl;

    return 0;
}
