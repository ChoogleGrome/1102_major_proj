#include <iostream>
#include <string.h>
#include "../artifacts/Artifacts.h"
#include "Entity.h"
#include "Enemy.h"
#include "Player.h"

int main()
{   
    // Enemy Details
    Enemy *enemy;
    Grunt grunt;
    enemy = &grunt;
    enemy->init(1);

    std::cout << "Enemy Name: " << enemy->getName() << std::endl;
    std::cout << "Enemy HP: " << enemy->getHP() << std::endl;

    std::cout << "Enemy moveset" << std::endl;
    for(int i = 0; i < 10; i++){
        std::cout << enemy->showNextMove() << std::endl; 
    }

    Player player;
    std::cout << player.getCurrentHp() << std::endl;

    std::cout << enemy->getName() << std::endl;
    std::cout << enemy->getHP() << std::endl;

    std::cout << enemy->showNextMove() << std::endl; 
    std::cout << enemy->showNextMove() << std::endl; 
    std::cout << enemy->showNextMove() << std::endl; 
    std::cout << enemy->showNextMove() << std::endl; 
    std::cout << enemy->showNextMove() << std::endl; 
    std::cout << enemy->showNextMove() << std::endl; 
}