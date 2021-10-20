#include <iostream>
#include <string.h>
#include "Entity.h"
#include "Enemy.h"

int main()
{       
    // Enemy Details
    Enemy *enemy;

    // Set enemy difficulty
    int dmTier = 1;

    // Create enemy grunt
    {
        Grunt grunt;
        enemy = &grunt;
        enemy->init(dmTier);

        std::cout << "Enemy Name: " << enemy->getName() << std::endl;
        std::cout << "Enemy Max HP: " << enemy->getHP() << std::endl;
        std::cout << "Enemy current HP: " << enemy->getCurrentHp() << std::endl;
        std::cout << "Enemy Crit Chance: " << enemy->getCritChance() << std::endl;
        std::cout << "Enemy Shield Gain: " << enemy->getShields() << std::endl;
        std::cout << "Enemy Shield: " << enemy->getShieldGain() << std::endl;
        std::cout << "Enemy Damage: " << enemy->getBaseDmg() << std::endl;

        std::cout << "Enemy moveset" << std::endl;
        for(int i = 0; i < 10; i++){
            std::cout << enemy->showNextMove() << " "; 
        }

        std::cout << std::endl << std::endl << std::endl;
    }

    // Create enemy slime
    {
        Slime slime;
        enemy = &slime;
        enemy->init(dmTier);

        std::cout << "Enemy Name: " << enemy->getName() << std::endl;
        std::cout << "Enemy Max HP: " << enemy->getHP() << std::endl;
        std::cout << "Enemy current HP: " << enemy->getCurrentHp() << std::endl;
        std::cout << "Enemy Crit Chance: " << enemy->getCritChance() << std::endl;
        std::cout << "Enemy Shield Gain: " << enemy->getShields() << std::endl;
        std::cout << "Enemy Shield: " << enemy->getShieldGain() << std::endl;
        std::cout << "Enemy Damage: " << enemy->getBaseDmg() << std::endl;

        std::cout << "Enemy moveset" << std::endl;
        for(int i = 0; i < 10; i++){
            std::cout << enemy->showNextMove() << " "; 
        }

        std::cout << std::endl << std::endl << std::endl;
    }

    // Create enemy assassin
    {
        Assassin assassin;
        enemy = &assassin;
        enemy->init(dmTier);

        std::cout << "Enemy Name: " << enemy->getName() << std::endl;
        std::cout << "Enemy Max HP: " << enemy->getHP() << std::endl;
        std::cout << "Enemy current HP: " << enemy->getCurrentHp() << std::endl;
        std::cout << "Enemy Crit Chance: " << enemy->getCritChance() << std::endl;
        std::cout << "Enemy Shield Gain: " << enemy->getShields() << std::endl;
        std::cout << "Enemy Shield: " << enemy->getShieldGain() << std::endl;
        std::cout << "Enemy Damage: " << enemy->getBaseDmg() << std::endl;

        std::cout << "Enemy moveset" << std::endl;
        for(int i = 0; i < 10; i++){
            std::cout << enemy->showNextMove() << " "; 
        }

        std::cout << std::endl << std::endl << std::endl;
    }

    // Create enemy thief
    {
        Thief thief;
        enemy = &thief;
        enemy->init(dmTier);

        std::cout << "Enemy Name: " << enemy->getName() << std::endl;
        std::cout << "Enemy Max HP: " << enemy->getHP() << std::endl;
        std::cout << "Enemy current HP: " << enemy->getCurrentHp() << std::endl;
        std::cout << "Enemy Crit Chance: " << enemy->getCritChance() << std::endl;
        std::cout << "Enemy Shield Gain: " << enemy->getShields() << std::endl;
        std::cout << "Enemy Shield: " << enemy->getShieldGain() << std::endl;
        std::cout << "Enemy Damage: " << enemy->getBaseDmg() << std::endl;

        std::cout << "Enemy moveset" << std::endl;
        for(int i = 0; i < 10; i++){
            std::cout << enemy->showNextMove() << " "; 
        }

        std::cout << std::endl << std::endl << std::endl;
    }

    // Create enemy tank
    {
        Tank tank;
        enemy = &tank;
        enemy->init(dmTier);

        std::cout << "Enemy Name: " << enemy->getName() << std::endl;
        std::cout << "Enemy Max HP: " << enemy->getHP() << std::endl;
        std::cout << "Enemy current HP: " << enemy->getCurrentHp() << std::endl;
        std::cout << "Enemy Crit Chance: " << enemy->getCritChance() << std::endl;
        std::cout << "Enemy Shield Gain: " << enemy->getShields() << std::endl;
        std::cout << "Enemy Shield: " << enemy->getShieldGain() << std::endl;
        std::cout << "Enemy Damage: " << enemy->getBaseDmg() << std::endl;

        std::cout << "Enemy moveset" << std::endl;
        for(int i = 0; i < 10; i++){
            std::cout << enemy->showNextMove() << " "; 
        }

        std::cout << std::endl << std::endl << std::endl;
    }

    // Create enemy king slime
    {
        KingSlime kingSlime;
        enemy = &kingSlime;
        enemy->init(dmTier);

        std::cout << "Enemy Name: " << enemy->getName() << std::endl;
        std::cout << "Enemy Max HP: " << enemy->getHP() << std::endl;
        std::cout << "Enemy current HP: " << enemy->getCurrentHp() << std::endl;
        std::cout << "Enemy Crit Chance: " << enemy->getCritChance() << std::endl;
        std::cout << "Enemy Shield Gain: " << enemy->getShields() << std::endl;
        std::cout << "Enemy Shield: " << enemy->getShieldGain() << std::endl;
        std::cout << "Enemy Damage: " << enemy->getBaseDmg() << std::endl;

        std::cout << "Enemy moveset" << std::endl;
        for(int i = 0; i < 10; i++){
            std::cout << enemy->showNextMove() << " "; 
        }

        std::cout << std::endl << std::endl << std::endl;
    }

    // Create enemy dragon
    {
        Dragon dragon;
        enemy = &dragon;
        enemy->init(dmTier);

        std::cout << "Enemy Name: " << enemy->getName() << std::endl;
        std::cout << "Enemy Max HP: " << enemy->getHP() << std::endl;
        std::cout << "Enemy current HP: " << enemy->getCurrentHp() << std::endl;
        std::cout << "Enemy Crit Chance: " << enemy->getCritChance() << std::endl;
        std::cout << "Enemy Shield Gain: " << enemy->getShields() << std::endl;
        std::cout << "Enemy Shield: " << enemy->getShieldGain() << std::endl;
        std::cout << "Enemy Damage: " << enemy->getBaseDmg() << std::endl;

        std::cout << "Enemy moveset" << std::endl;
        for(int i = 0; i < 10; i++){
            std::cout << enemy->showNextMove() << " "; 
        }

        std::cout << std::endl << std::endl << std::endl;
    }

    // Create enemy angel
    {
        Angel angel;
        enemy = &angel;
        enemy->init(dmTier);

        std::cout << "Enemy Name: " << enemy->getName() << std::endl;
        std::cout << "Enemy Max HP: " << enemy->getHP() << std::endl;
        std::cout << "Enemy current HP: " << enemy->getCurrentHp() << std::endl;
        std::cout << "Enemy Crit Chance: " << enemy->getCritChance() << std::endl;
        std::cout << "Enemy Shield Gain: " << enemy->getShields() << std::endl;
        std::cout << "Enemy Shield: " << enemy->getShieldGain() << std::endl;
        std::cout << "Enemy Damage: " << enemy->getBaseDmg() << std::endl;

        std::cout << "Enemy moveset" << std::endl;
        for(int i = 0; i < 10; i++){
            std::cout << enemy->showNextMove() << " "; 
        }

        std::cout << std::endl << std::endl << std::endl;
    }
    

    return 0;
}