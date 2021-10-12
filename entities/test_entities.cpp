#include <iostream>
#include <string>
#include "../artifacts/Artifacts.h"
#include "Entity.h"
#include "Enemy.h"
#include "Player.h"
#include "stdlib.h"

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
/*
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
    enemy.defend();
    std::cout << "Enemy shield: " << enemy.shields << std::endl; 

    player.hurt(enemy.damage());

    std::cout << std::endl << std::endl;
    std::cout << "The player took: " << enemy.baseDmg << " damage" << std::endl;

    //Hp still remains the same
    std::cout << "Player Hp: " << player.getCurrentHp() << std::endl;
    std::cout << "Player Shield: " << player.getShields() << std::endl;
*/



    //Quick game test
    int i = 0;

    while (enemy.currentHp >= 0)
    {
        if (i == enemy.moveNum)
        {
            i = 0;
        }

        int userInput = 0;
        std::string enemyMove;

        std::cout << "Player Hp: " << player.currentHp << "\t\t\t" << "Enemy Hp: " << enemy.currentHp << std::endl;
        std::cout << "Player Shield: " << player.shields << "\t\t" << "Enemy Shield: " << enemy.shields << std::endl;


        if (enemy.moveset[i] == 0)
        {
            enemyMove = "Defend";
        } else {
            enemyMove = "Attack";
        }
        std::cout << "Enemy Next Move: " << enemyMove << std::endl;

        std::cout << std::endl << "Press '1' to Attack" << std::endl << "Press '2' to Defend" << std::endl;
        std::cin >> userInput;

        /*
        while (userInput != 1 || userInput != 2)
        {
            std::cout << "Invalid Input, try again" << std::endl;
            std::cout << "Press '1' to Attack" << std::endl << "Press '2' to Defend" << std::endl;
            std::cin >> userInput;
        }
        */

       std::cout << std::endl << "PLAYER TURN" << std::endl << std::endl;

        if (userInput == 1)
        {
            enemy.hurt(player.damage());
            std::cout << "Enemy took " << player.damage() << " damage" << std::endl;
        } else {
            player.defend();
            std::cout << "Player receives " << player.getShieldGain() << " shields" << std::endl;
        }

        std::cout << "Player Hp: " << player.getCurrentHp() << "\t\t\t" << "Enemy Hp: " << enemy.getCurrentHp() << std::endl;
        std::cout << "Player Shield: " << player.getShields() << "\t\t" << "Enemy Shield: " << enemy.getShields() << std::endl;

        std::cout << std::endl << "ENEMY TURN" << std::endl << std::endl;;

        if (enemy.moveset[i] == 1)
        {
            player.hurt(enemy.damage());
            std::cout << "Player took " << enemy.damage() << " damage" << std::endl;
        } else {
            enemy.defend();
            std::cout << "Enemy receives " << enemy.getShieldGain() << " shields" << std::endl;
        }

        std::cout << "Player Hp: " << player.getCurrentHp() << "\t\t\t" << "Enemy Hp: " << enemy.getCurrentHp() << std::endl;
        std::cout << "Player Shield: " << player.getShields() << "\t\t" << "Enemy Shield: " << enemy.getShields() << std::endl;

        std::cout << std::endl << std::endl << std::endl << std::endl;

        i++;
    }
    
    return 0;
}
