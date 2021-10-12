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
    player.hp = 100;
    player.baseDmg = 3;
    player.critChance = 0.4;
    player.shields = 0;
    player.shieldGain = 1;

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
    Grunt a(1);

    std::cout << "The Grunts HP is: " << a.hp << std::endl;
    std::cout << "The Grunst Base Damage is:" << a.baseDmg << std::endl;
    std::cout << "The Grunt crit chance is: " << a.critChance << std::endl;
    for(int i = 0; i < a.moveNum; i++){
        std::cout << "" << a.moveset[i];
    }
    std::cout << std::endl;
    std::cout << " This enmey is a : " << a.isBoss() << std::endl;
    std::cout << "The Grunt drops " << a.xpDrop << "Experience points" <<  std::endl;

    player.defend();

    std::cout << "The player now has :" << player.getShields() << " Sheild" << std::endl;

    a.defend(player);

    std::cout << "The Grunts Shields are now: " << a.shields << std::endl; 

    a.attack(player);



    std::cout << "The player took: " << a.baseDmg << " damage, it now has: " << player.shields << " Shield/s" << std::endl;


//    std::cout << "The player took: " << a.baseDmg << " damage, it now has: " << player.currentHp << "hp" << std::endl;


    return 0;
}
