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
    Grunt grunt;
    Slime slime;
    Assassin assassin;
    Thief thief;
    Tank tank;
    KingSlime kingSlime;
    Dragon dragon;
    Angel angel;

    int randEnemy = 0;
    Enemy *levelEnemy;
    while (player.getCurrentHp() > 0) {

        // Displaying player Stats
        printw("PLAYER STATS\n\nHP: %i\nShields: %i\nAttack Damage: %i\nCritical Chance: %f\nEXP Level: %i\n\n\n", player.getCurrentHp(), player.getShields(), player.getBaseDmg(), player.getCritChance(), player.getLevel());
        refresh();

        while (true) {

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
                        printw("You have chosen to Recover HP, HP healed by 20. Press anything to continue");
                        refresh();
                        getch();

                        // Add 20 hp to player
                        player.updateHP(20);

                        // Exit code
                        break;
                    
                    // Code for player increasing their base damage
                    } else if (strcmp(check_char.c_str(), "D") == 0) {
                        printw("You have chosen to Increase Damage, Attack Damage increased by 2. Press anything to continue");
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
                
                    // Displaying player Stats after resting ground 
                    printw("PLAYER STATS\n\nHP: %i\nShields: %i\nAttack Damage: %i\nCritical Chance: %f\nEXP Level: %i\nPress anything to continue\n\n", player.getCurrentHp(), player.getShields(), player.getBaseDmg(), player.getCritChance(), player.getLevel());
                    refresh();
                    scanw("%s", check_char.c_str());
                    clear();

                }

                getch();
                clear();
                return 1;
            } else {
                
                // To convert enemy move into a string text
                string enemyMove;
                
                // randMove is for scenario where enemy will have a random moveset
                int randMove = rand() % 10;
                
                // move is used during combat phase
                int move;

                // Create enemy difficulty depening on dimensionTier
                levelEnemy->init(game->dimensionTier);


                // Displaying stats during combat
                printw("PLAYER\n\nHP: %i\nShields: %i\n\n", player.getCurrentHp(), player.getShields());
                refresh();

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
                
                printw("%s\n\nHP: %i\nShields: %i\nNext Move: %s\n", levelEnemy->getName().c_str(), levelEnemy->getHP(), levelEnemy->getShields(), enemyMove.c_str());
                refresh();
            }
            
            
            // printw("PLAYER\nHP: %i\nShields: %i\nAttack Damage: %i\nCritical Chance: %f\nEXP Level: %i\n", player.getCurrentHp(), player.getShields(), player.getBaseDmg(), player.getCritChance(), player.getLevel());
            refresh();
            getch();


            break;
        }
    }

    endwin();
    return 0;
}