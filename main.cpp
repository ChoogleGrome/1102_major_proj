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
        if (strcmp(check_char.c_str(), "Y") == 0) {
            break;
        } else {
            // printw("%s\n", check_char.c_str());
            printw("Incorrect Input, Try Again\n");
            printw("Enter 'Y' without quotations when ready to contiue\n");
            refresh();
            scanw("%s", check_char.c_str());
        }
    }

    // Clear window for next stage
    clear();
    //////////////////////////////////////////////// INTRO SCREEN END //////////////////////////////////////////////////

    Player player;

    int randEnemy = 0;
    Enemy *levelEnemy;
    while (player.getCurrentHp() > 0) {

        // Displaying player Stats
        // printw("PLAYER STATS\n\nHP: %i\nShields: %i\nAttack Damage: %i\nCritical Chance: %f\nEXP Level: %i\n\n\n", player.getCurrentHp(), player.getShields(), player.getBaseDmg(), player.getCritChance(), player.getLevel());
        // refresh();

        while (true) {
            Grunt grunt;
            Slime slime;
            Assassin assassin;
            Thief thief;
            Tank tank;
            KingSlime kingSlime;
            Dragon dragon;
            Angel angel;

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
                
                // 
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
                
                // 
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


                check = true;
                while (check) {

                    // Code for player restoring hp
                    if (strcmp(check_char.c_str(), "H") == 0) {
                        printw("You have chosen to Recover HP, HP healed by 20. Press anything to continue\n");
                        refresh();
                        getch();

                        // Add 20 hp to player
                        player.updateHP(20);

                        // Exit code
                        break;
                    
                    // Code for player increasing their base damage
                    } else if (strcmp(check_char.c_str(), "D") == 0) {
                        printw("You have chosen to Increase Damage, Attack Damage increased by 2. Press anything to continue\n");
                        refresh();
                        getch();

                        // Add 2 damage to player
                        player.updateBaseDmg(2);

                        // Exit code
                        break;

                    // Code for incorrect input
                    } else {
                        // printw("%s\n", check_char.c_str());
                        printw("Incorrect Input, Try Again\n");
                        printw("Please enter 'H' to Recover HP or 'D' to Increase Damage\n");
                        refresh();
                        scanw("%s", check_char.c_str());
                    }

                    game->level++;
                
                    // Displaying player Stats after resting ground 
                    printw("PLAYER STATS\n\nHP: %i\nShields: %i\nAttack Damage: %i\nCritical Chance: %f\nEXP Level: %i\nPress anything to continue\n\n", player.getCurrentHp(), player.getShields(), player.getBaseDmg(), player.getCritChance(), player.getLevel());
                    refresh();
                    getch();
                    clear();
                }

                clear();
                break;
            } else {
                
                // To convert enemy move into a string text
                string enemyMove;
                
                // randMove is for scenario where enemy will have a random moveset
                int randMove = rand() % 10;
                
                // move is used during combat phase
                int move;
                int damageAmount;

                // Create enemy difficulty depening on dimensionTier
                levelEnemy->init(game->dimensionTier);
                
                while (true) {
                    if (levelEnemy->getCurrentHp() <= 0) { break; } 
                    else if(player.getCurrentHp() <= 0) { goto end; }
                    
                    player.updateShieldAmount(0);
                    randMove = rand() % 10;
                    if (levelEnemy->showNextMove() == 1) { enemyMove = "Attack"; move = 1; }
                    else if (levelEnemy->showNextMove() == 0) { enemyMove = "Defend"; move = 0; }
                    
                    // For enemies with moveset number = 2, hidden move
                    else if (levelEnemy->showNextMove() == 2 ) { 
                        if (randMove < 5) {
                            enemyMove = "Hidden Move";
                            move = 1;
                        } else {
                            enemyMove = "Hidden Move";
                            move = 0;
                        }
                    }

                    // Displaying stats during combat
                    printw("Level %i, Dimension %i\n\n", game->level, game->dimensionTier);
                    // printw("PLAYER\n\nHP: %i\nShields: %i\n\n", player.getCurrentHp(), player.getShields());
                    printw("PLAYER STATS\nHP: %i\nShields: %i\nAttack Damage: %i\nCritical Chance: %f\nEXP Level: %i\n\n", player.getCurrentHp(), player.getShields(), player.getBaseDmg(), player.getCritChance(), player.getLevel());
                    printw("%s\nHP: %i\nShields: %i\nNext Move: %s\n", levelEnemy->getName().c_str(), levelEnemy->getCurrentHp(), levelEnemy->getShields(), enemyMove.c_str());
                    printw("Would you like to Attack (A) or Shield (S)\n");
                    refresh();
                    scanw("%s", check_char.c_str());
                    check = true;
                    while(check) {
                        if (strcmp(check_char.c_str(), "A") == 0) {
                            printw("You have chosen to Attack. Press any button to continue\n");
                            damageAmount = player.damage();
                            printw("Attacked for %i damage\n", damageAmount);
                            levelEnemy->hurt(damageAmount);
                            refresh();
                            getch();
                            check = false;
                        
                        // Code for player increasing their base damage
                        } else if (strcmp(check_char.c_str(), "S") == 0) {
                            printw("You have chosen to Shield. Press any button to continue\n");
                            player.defend();
                            printw("You shielded for %i damage\n", player.getShieldGain());
                            refresh();
                            getch();
                            check = false;

                        // Code for incorrect input
                        } else {
                            // printw("%s\n", check_char.c_str());
                            printw("Incorrect Input, Try Again\n");
                            printw("Please enter 'A' to Attack HP or 'S' to Shield\n");
                            refresh();
                            scanw("%s", check_char.c_str());
                        }

                        
                    }

                    if (move == 1) { 
                        damageAmount = levelEnemy->damage();
                        player.hurt(damageAmount);
                        printw("Enemy Attacked for %i damage", damageAmount); 
                    } else if (move == 0 ) { 
                        levelEnemy->defend();
                        printw("Enemy shielded for %i damage", levelEnemy->getShieldGain());
                    }

                    refresh();
                    getch();
                    clear();

                    if (levelEnemy->getCurrentHp() <= 0) { break; } 
                    else if(player.getCurrentHp() <= 0) { goto end; }
                }

                int randArtifact = (rand() % 10);
                if (levelEnemy->getCurrentHp() <= 0) {
                    printw("You have defeated the Enemy, Congrats!\n");
                    printw("You have receieved a %s\n", player.items[randArtifact].name.c_str());   

                    player.addItem(randArtifact);
                    
                    printw("Artifacts:\n");
                    for (int i = 0; i < 10; i++) {
                        printw("%i | %s (%s) \n", player.items[i].amount, player.items[i].name.c_str(), player.items[i].desc.c_str());
                    }
                    game->level++;

                    printw("To Continue, press 'C', to end this run, press 'E'\n");
                    refresh();
                    scanw("%s", check_char.c_str());

                    check = true;
                    while(check) {
                        if (strcmp(check_char.c_str(), "C") == 0) { check = false; } 
                        else if (strcmp(check_char.c_str(), "E") == 0) {
                            goto end;
                        } else {
                            // printw("%s\n", check_char.c_str());
                            printw("Incorrect Input, Try Again\n");
                            printw("Please enter 'C' to Continue or 'E' to End\n");
                            refresh();
                            scanw("%s", check_char.c_str());
                        }
                    }
                    clear();
                } else if (player.getCurrentHp() <= 0) {
                    printw("You have died\nPress Any Key to Continue\n");
                    getch();
                    clear();
                    goto end;
                }
            }

            // printw("PLAYER\nHP: %i\nShields: %i\nAttack Damage: %i\nCritical Chance: %f\nEXP Level: %i\n", player.getCurrentHp(), player.getShields(), player.getBaseDmg(), player.getCritChance(), player.getLevel());
        }
    }

    // Death Stuff
    end: 
        printw("Thank you for playing Madrage: Dungeon Deluxe NEW Edition. Press Any Key to exit\n");
        refresh();
        getch();


    // delete levelEnemy;
    delete game;
    endwin();
    return 0;
}