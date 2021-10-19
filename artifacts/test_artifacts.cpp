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
    int randNum = (rand() % 10) - 1;

    player.addItem(randNum);

    std::cout << player.NumItems << std::endl;

    for (int i = 0; i < 10; i++) {
        std::cout << player.items[i].name << " " << player.items[i].amount << std::endl;
    }

    return 0;
}