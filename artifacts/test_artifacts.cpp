#include <iostream>
#include <string.h>
#include "Artifacts.h"
#include "../entities/Entity.h"
#include "../entities/Player.h"

int main()
{   
    Player player;

    //Testing Player attribute and behaviours
    srand(time(0));
    
    
    // for (int j = 0; j < 100; j++)
    // {
    //     int randNum = (rand() % 10);
    //     player.addItem(randNum);

    //     std::cout << player.NumItems << std::endl;

    //     for (int i = 0; i < 10; i++) {
    //         std::cout << player.items[i].name << "\t\t" << player.items[i].amount << std::endl;
    //     }
    // }

    player.addItem(5);
    std::cout << player.critChance << std::endl;


    return 0;
}