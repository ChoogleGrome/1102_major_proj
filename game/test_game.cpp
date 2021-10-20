#include <iostream>
#include <string>
#include <stdlib.h>
#include "../artifacts/Artifacts.h"
#include "../entities/Entity.h"
#include "../entities/Enemy.h"
#include "../entities/Player.h"

int main()
{
    //Creating player
    Player player;

    // creating a basic enemy grunt
    Enemy *enemy;
    Grunt grunt;
    enemy = &grunt;
    enemy->init(1);

    //Quick game test
    int i = 0;
    int userInput = 0;

    while (enemy->currentHp >= 0)
    {

        std::string enemyMove;

        std::cout << "Player Hp: " << player.getCurrentHp() << "\t\t\t" << "Enemy Hp: " << enemy->getCurrentHp() << std::endl;
        std::cout << "Player Shield: " << player.getShields() << "\t\t" << "Enemy Shield: " << enemy->getShields() << std::endl;


        if (enemy->showNextMove() == 0)
        {
            enemyMove = "Defend";
        } else {
            enemyMove = "Attack";
        }
        std::cout << "Enemy Next Move: " << enemyMove << std::endl;

        std::cout << std::endl << "Press '1' to Attack" << std::endl << "Press '2' to Defend" << std::endl;
        std::cin >> userInput;


        //Loop when user input an invalid input
        while (userInput != 1 & userInput != 2)
        {
            //Clear buffer
            std::cin.clear();
            fflush(stdin);

            if (userInput == -1){
                std::cout << "Ending Test" << std::endl;
                return 0;
            }

            //Showing incorrect input
            std::cout << std::endl << "Invalid Input, try again" << std::endl;
            std::cout << "Press '1' to Attack" << std::endl << "Press '2' to Defend" << std::endl;
            std::cin >> userInput;
        }        

       std::cout << std::endl << "PLAYER TURN" << std::endl << std::endl;

        if (userInput == 1)
        {
            enemy->hurt(player.damage());
            std::cout << "Enemy took " << player.damage() << " damage" << std::endl;
        } else if (userInput == 2){
            player.defend();
            std::cout << "Player receives " << player.getShieldGain() << " shields" << std::endl;
        }

        std::cout << "Player Hp: " << player.getCurrentHp() << "\t\t\t" << "Enemy Hp: " << enemy->getCurrentHp() << std::endl;
        std::cout << "Player Shield: " << player.getShields() << "\t\t" << "Enemy Shield: " << enemy->getShields() << std::endl;

        std::cout << std::endl << "ENEMY TURN" << std::endl << std::endl;;

        if (enemyMove == "Attack")
        {
            player.hurt(enemy->damage());
            std::cout << "Player took " << enemy->damage() << " damage" << std::endl;
        } else {
            enemy->defend();
            std::cout << "Enemy receives " << enemy->getShieldGain() << " shields" << std::endl;
        }

        std::cout << "Player Hp: " << player.getCurrentHp() << "\t\t\t" << "Enemy Hp: " << enemy->getCurrentHp() << std::endl;
        std::cout << "Player Shield: " << player.getShields() << "\t\t" << "Enemy Shield: " << enemy->getShields() << std::endl;

        std::cout << std::endl << std::endl << std::endl << std::endl;

        i++;
    }
    
    return 0;
}