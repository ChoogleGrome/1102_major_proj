#include <iostream>
#include <string.h>
#include "Artifacts.h"
#include "../entities/Entity.h"
#include "../entities/Player.h"

int main()
{   
    // Initialising player
    Player player;

    //Testing Player attribute and behaviours
    srand(time(0));
    
    player.addItem(5);
    std::cout << player.critChance << std::endl;


    return 0;
}