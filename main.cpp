#include "artifacts/Artifacts.h"
#include "entities/Entity.h"
#include "entities/Player.h"
#include "entities/Enemy.h"
#include "game/Game.h"

#include <iostream>
#include <string.h>
#include <cctype>
#include <ncurses.h>

using namespace std;

int main(void) {
    /////////////////////////////////////////////////////// INIT ///////////////////////////////////////////////////////
    
    // Initialising game
    Game * game = new Game;
    initscr();
    srand(time(0));

    //////////////////////////////////////////////// INTRO SCREEN START ////////////////////////////////////////////////
    // Game Instruction Print
    printw("Welcome to Madrage: Dungeon Deluxe NEW Edition\n");
    printw("This game is your typical Dungeon Crawler. The Game works in Dimension Tiers, starting at Tier 1.\n");
    printw("Each Dimension Tier has 10 Levels, with the final level being a Boss\n");
    printw("You, The Player, collect items after each Enemy killed, and gain experience\n");
    printw("Exp gain upgrades your hp, whereas items can upgrade any of your stats\n");
    printw("Enter 'Y' without quotations when ready to contiue\n");
    refresh();
    
    // Get Check Input
    string check_char;
    scanw("%s", check_char.c_str());

    // Check if input is "Y", otherwise, loop error message
    bool check = true;
    while (check) {

        // If input is "Y" exit the while loop
        if (strcmp(check_char.c_str(), "Y") == 0) {
            break;

        // Show text for when input is incorrect
        } else {
            printw("Incorrect Input, Try Again\n");
            printw("Enter 'Y' without quotations when ready to contiue\n");
            refresh();
            scanw("%s", check_char.c_str());
        }
    }

    // Clear window for next stage
    clear();
    //////////////////////////////////////////////// INTRO SCREEN END //////////////////////////////////////////////////

    // Initialising player
    Player player;

    // Setting the random number generator
    int randEnemy = 0;

    // Initialising enemy
    Enemy *levelEnemy;

    // Loop this program while player hp is above 0
    while (player.getCurrentHp() > 0) {
        while (true) {

            // Initialising all the enemies
            Grunt grunt;
            Slime slime;
            Assassin assassin;
            Thief thief;
            Tank tank;
            KingSlime kingSlime;
            Dragon dragon;
            Angel angel;

            // If the game room is level 10, increase dimensionTier by 1 and reset game level to 1
            if (game->level > 10) {
                game->dimensionTier++;
                game->level = 1;
            }

            // For regular monsters, level 1-9
            if (game->level < 10) {
                randEnemy = rand() % 300;
                //randEnemy = 280;

                // Set nevel enemy to grunt
                if (randEnemy < 60) {
                    levelEnemy = &grunt;

                // Set level enemy to slime
                } else if (randEnemy < 135 && randEnemy >= 60) {
                    levelEnemy = &slime;

                // Set level enemy to assasin
                } else if (randEnemy < 175 && randEnemy >= 135) {
                    levelEnemy = &assassin;

                // Set level enemy to thief
                } else if (randEnemy < 220 && randEnemy >= 175) {
                    levelEnemy = &thief;

                // Set level enemy to tank
                } else if (randEnemy < 250 && randEnemy >= 220) {
                    levelEnemy = &tank;

                // This will go to the campfire, gain hp or attack
                }  else if (randEnemy <= 300 && randEnemy >= 250) {
                    randEnemy = 275; 
                
                // Debugging purposes
                } else {
                    return 1;
                }

            // Determine boss on level 10
            } else {
                randEnemy = rand() % 140;
                
                // Set level enemy to king slime
                if (randEnemy < 50) {
                    levelEnemy = &kingSlime;

                // Set level enemy to dragon
                } else if (randEnemy < 110 && randEnemy >= 50) {
                    levelEnemy = &dragon;

                // Set level enemy to angel
                } else if (randEnemy <= 140 && randEnemy >= 110) {
                    levelEnemy = &angel;
                
                // Debugging purposes
                } else {
                    return 1;
                }
            }

            // Play out campfire scenario, where player can either gain hp or increase base attack damage
            if (randEnemy >= 250) {

                // Display text option for player
                printw("You have Reached a Resting Ground\nChoose between Recover HP (H) or Increase Damage (D)\n");
                refresh();
                scanw("%s", check_char.c_str());

                // Initialise the loop
                check = true;
                while (check) {

                    // Code for player restoring hp
                    if (strcmp(check_char.c_str(), "H") == 0) {
                        printw("You have chosen to Recover HP, HP healed by 20. Press anything to continue\n");
                        refresh();
                        getch();
                        clear();

                        // Add 20 hp to player
                        player.updateHP(20);
                        game->level++;

                        // Exit code
                        break;
                    
                    // Code for player increasing their base damage
                    } else if (strcmp(check_char.c_str(), "D") == 0) {
                        printw("You have chosen to Increase Damage, Attack Damage increased by 2. Press anything to continue\n");
                        refresh();
                        getch();
                        clear();

                        // Add 2 damage to player
                        player.updateBaseDmg(2);
                        game->level++;

                        // Exit code
                        break;

                    // Code for incorrect input
                    } else {
                        clear();
                        printw("Incorrect Input, Try Again\n");
                        printw("Please enter 'H' to Recover HP or 'D' to Increase Damage\n");
                        refresh();
                        scanw("%s", check_char.c_str());
                    }
                }

                // Displaying player Stats after resting ground 
                printw("PLAYER STATS\n\nHP: %i\nShields: %i\nAttack Damage: %i\nCritical Chance: %f\nPress anything to continue\n\n", player.getCurrentHp(), player.getShields(), player.getBaseDmg(), player.getCritChance());
                refresh();
                getch();
                clear();
                break;

            /////// Combat ///////
            } else {
                // To convert enemy move into a string text
                string enemyMove;
                
                // randMove is for scenario where enemy will have a random moveset
                int randMove = rand() % 10;
                
                // move is used during combat phase
                int move;
                int damageAmount;

                levelEnemy->init(game->dimensionTier);
                
                // Loop for combat
                while (true) {

                    // Finish combat if enemy hp = 0
                    if (levelEnemy->getCurrentHp() <= 0) { break; } 

                    // Go to end of program for end of game code when player hp = 0
                    else if(player.getCurrentHp() <= 0) { goto end; }
                    
                    // Set player shield to 0 every turn
                    player.updateShieldAmount(0);

                    // Random move generator for enemy with moveset = 2
                    randMove = rand() % 10;

                    // If nextMove is = 1, attack
                    if (levelEnemy->showNextMove() == 1) { enemyMove = "Attack"; move = 1; }
                    // If nextMove is = 0, defend
                    else if (levelEnemy->showNextMove() == 0) { enemyMove = "Defend"; move = 0; }
                    

                    // For enemies with moveset number = 2, hidden move
                    else if (levelEnemy->showNextMove() == 2 ) { 

                        // If randMove is greater than 5, show hidden move but it will attack this turn
                        if (randMove < 5) {
                            enemyMove = "Hidden Move";
                            move = 1;
                        
                        // If randMove is lower than 5, show hidden move but it will defend this turn
                        } else {
                            enemyMove = "Hidden Move";
                            move = 0;
                        }
                    }

                    // Displaying stats during combat
                    printw("Level %i, Dimension %i\n\n", game->level, game->dimensionTier);
                    printw("PLAYER STATS\nHP: %i\nShields: %i\nAttack Damage: %i\nCritical Chance: %f\n\n", player.getCurrentHp(), player.getShields(), player.getBaseDmg(), player.getCritChance());
                    printw("%s\nHP: %i\nShields: %i\nNext Move: %s\n", levelEnemy->getName().c_str(), levelEnemy->getCurrentHp(), levelEnemy->getShields(), enemyMove.c_str());
                    printw("\nWould you like to Attack (A) or Shield (S)\n");
                    refresh();
                    scanw("%s", check_char.c_str());

                    // Setting check to true for the combat loop
                    check = true;

                    // Check for player input to determine their move
                    while(check) {

                        // If input is A, player will attack
                        if (strcmp(check_char.c_str(), "A") == 0) {

                            // Getting player damage amount, crit may apply
                            damageAmount = player.damage();

                            // Displaying player attack damage
                            printw("Press any button to continue\nYou have chosen to Attack for %i damage\n", damageAmount);

                            // Apply attack damage to enemy
                            levelEnemy->hurt(damageAmount);
                            refresh();
                            getch();
                            check = false;
                        
                        // If player input S, player will defend
                        } else if (strcmp(check_char.c_str(), "S") == 0) {

                            // Player increasing their sheild
                            player.defend();

                            // Display amount of shield the player have gained
                            printw("Press any button to continue\nYou have chosen to Shield for %i damage\n", player.getShieldGain());

                            refresh();
                            getch();
                            check = false;

                        // Code for incorrect input
                        } else {
                            printw("Incorrect Input, Try Again\n");
                            printw("Please enter 'A' to Attack HP or 'S' to Shield\n");
                            refresh();
                            scanw("%s", check_char.c_str());
                        }
                    }

                    // If ememy hp is zero or below, exit the while loop
                    if (levelEnemy->getCurrentHp() <= 0) { break; } 
                    // If player hp is zero or below, go to end of program
                    else if(player.getCurrentHp() <= 0) { goto end; }

                    /* This code determines enemy move
                       If Enemy move = 1 the enemy will attack the player*/
                    if (move == 1) { 

                        // Get enemy damage amount, crit may apply
                        damageAmount = levelEnemy->damage();

                        // Deal damage to player
                        player.hurt(damageAmount);

                        // Show amount of damage dealt to player
                        printw("Enemy Attacked for %i damage", damageAmount); 

                    // If enemy move = 0, the enemy will shield
                    } else if (move == 0 ) { 

                        // Enemy gain shield
                        levelEnemy->defend();

                        // Show how much the enemy have shielded for
                        printw("Enemy shielded for %i damage", levelEnemy->getShieldGain());
                    }
                    // This is when the enemy survies clear screen
                    refresh();
                    getch();
                    clear();
                }

                // Enemy dies clear screen
                refresh();
                clear();
                
                // Setting rand artifact to a random number from 0-9, this will determine the random artifact
                int randArtifact = (rand() % 10);

                // Show results when the enemy is defeated
                if (levelEnemy->getCurrentHp() <= 0) {
                    printw("You have defeated the Enemy, Congrats!\n");

                    // Gain a random artifact
                    printw("You receieved a %s\n", player.items[randArtifact].name.c_str());   
                    player.addItem(randArtifact);
                    
                    // Display what artifacts the player currently have
                    printw("\n\t\t\tArtifacts:\n");
                    for (int i = 0; i < 10; i++) {
                        printw("%i | %s (%s) \n", player.items[i].amount, player.items[i].name.c_str(), player.items[i].desc.c_str());
                    }

                    // Increment game level, this determines the number of rooms left till the boss
                    game->level++;

                    printw("\nTo Continue, press 'C', to end this run, press 'E'\n");
                    refresh();
                    scanw("%s", check_char.c_str());

                    check = true;
                    while(check) {
                        if (strcmp(check_char.c_str(), "C") == 0) { check = false; } 
                        else if (strcmp(check_char.c_str(), "E") == 0) {
                            goto end;

                        // Code for incorrect input
                        } else {
                            printw("Incorrect Input, Try Again\n");
                            printw("Please enter 'C' to Continue or 'E' to End\n");
                            refresh();
                            scanw("%s", check_char.c_str());
                        }
                    }

                    // Clear terminal screen
                    clear();

                // If player hp is zero or less display text
                } else if (player.getCurrentHp() <= 0) {
                    printw("You have died\nPress Any Key to Continue\n");
                    getch();
                    clear();
                    goto end;
                }
            }
        }
    }

    // Game Over message, either by player quitting the game or in game death
    end: 
        printw("Thank you for playing Madrage: Dungeon Deluxe NEW Edition. Press Any Key to exit\n");
        refresh();
        getch();


    // delete levelEnemy;
    delete game;
    endwin();
    return 0;
}