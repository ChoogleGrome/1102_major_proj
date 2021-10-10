#include <iostream>
#include <string>
//#include "../artifacts/Artifacts.h"
#include "Entity.h"
//#include "Enemy.h"
#include "Player.h"

int main()
{
    //testing the Players functions
    Player player;
    player.hp = 1300;
    player.baseDmg = 3000;
    player.critChance = 200;
    player.shields = 67;
    player.shieldGain = 28;


    std::cout << "the Players base Damage is: " << player.getBaseDmg() << std::endl;
    std::cout << "the Players crit chance is: " << player.getCritChance()<< std::endl;
    std::cout << "the Players currnet hp is: " << player.getCurrentHp() << std::endl;
    std::cout << "the Players max hp is: " << player.getHP() << std::endl;
    std::cout << "the Players level  is: " << player.getLevel() << std::endl;
    std::cout << "the Players increase in sheilds  is: " << player.getShieldGain() << std::endl;
    std::cout << "the Players shields is: " << player.getShields() << std::endl;
    std::cout << "the Players xp is: " << player.getXp() << std::endl;





    return 0;
}
