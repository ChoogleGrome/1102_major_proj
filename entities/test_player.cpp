#include <iostream>
#include <string.h>
#include "../artifacts/Artifacts.h"
#include "Entity.h"
#include "Player.h"

int main()
{       
    // Player Details
    Player player;

    {

        std::cout << "Player Max HP: " << player.getHP() << std::endl;
        std::cout << "Player current HP: " << player.getCurrentHp() << std::endl;
        std::cout << "Player Crit Chance: " << player.getCritChance() << std::endl;
        std::cout << "Player Shield Gain: " << player.getShields() << std::endl;
        std::cout << "Player Shields: " << player.getShieldGain() << std::endl;
        std::cout << "Player Damage: " << player.getBaseDmg() << std::endl;
        

    }

    return 0;
}