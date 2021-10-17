#include <iostream>
#include <string.h>
#include "Artifacts.h"
#include "../entities/Entity.h"
#include "../entities/Player.h"

int main()
{   

    //Testing Player attribute and behaviours
    Player * player = new Player(2);
    Herbs herb1;
    GreenGemStone GGem1;
    GreenGemStone GGem2;
    GreenGemStone GGem3;

    player->addItem(herb1);
    player->addItem(GGem1);
    player->addItem(GGem2);

    player->getItems();

    std::cout << "Num Items: " << player->NumItems << std::endl;

    player->addItem(GGem3);

    player->getItems();

    std::cout << "Num Items: " << player->NumItems << std::endl;

    delete player;

    return 0;
}