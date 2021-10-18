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
    Game * game = new Game();
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
        while (true) {
            if (game->level < 10) { // Add fireplace room
                randEnemy = rand() % 300;
                // randEnemy = 266;

                if (randEnemy < 60) {
                    Grunt grunt;
                    levelEnemy = &grunt;
                } else if (randEnemy < 135 && randEnemy >= 60) {
                    Slime slime;
                    levelEnemy = &slime;
                } else if (randEnemy < 175 && randEnemy >= 135) {
                    Assassin assassin;
                    levelEnemy = &assassin;
                } else if (randEnemy < 220 && randEnemy >= 175) {
                    Thief thief;
                    levelEnemy = &thief;
                } else if (randEnemy < 250 && randEnemy >= 220) {
                    Tank tank;
                    levelEnemy = &tank;
                }  else if (randEnemy <= 300 && randEnemy >= 250) {
                    randEnemy = 275; 
                } else {
                    return 1;
                }
            } else {
                randEnemy = rand() % 140;

                if (randEnemy < 50) {
                    KingSlime kingSlime;
                    levelEnemy = &kingSlime;
                } else if (randEnemy < 110 && randEnemy >= 50) {
                    Dragon dragon;
                    levelEnemy = &dragon;
                } else if (randEnemy <= 140 && randEnemy >= 110) {
                    Angel angel;
                    levelEnemy = &angel;
                } else {
                    return 1;
                }
            }

            if (randEnemy >= 250) {
                printw("You have Reached a Resting Ground\nChoose between Recover HP (H) or Increase Damage (D)\n");
                refresh();
                scanw("%s", check_char.c_str());
                check = true;
                while (check) {
                    if (strcmp(check_char.c_str(), "H") == 0) {
                        printw("You have chosen to Recover HP, HP healed by 20. Press anything to continue");
                        player.updateHP(20);
                        break;
                    } else if (strcmp(check_char.c_str(), "D") == 0) {
                        printw("You have chosen to Increase Damage, Attack Damage increased by 2. Press anything to continue");
                        player.updateBaseDmg(2);
                        break;
                    } else {
                        // printw("%s\n", check_char.c_str());
                        printw("Incorrect Input, Try Again\n");
                        printw("Please enter 'H' to Recover HP or 'D' to Increase Damage\n");
                        refresh();
                        scanw("%s", check_char.c_str());
                    }
                }

                getch();
                clear();
                break;
            } else {
                string enemyMove;
                int randMove = rand() % 10;
                int move;
                levelEnemy->init(game->dimensionTier);
                printw("PLAYER\nHP: %i\nShields: %i\nAttack Damage: %i\nCritical Chance: %f\nEXP Level: %i\n", player.getCurrentHp(), player.getShields(), player.getBaseDmg(), player.getCritChance(), player.getLevel());
                
                if (levelEnemy->showNextMove() == 1) { enemyMove = "Attack"; move = 1; }
                else if (levelEnemy->showNextMove() == 0) { enemyMove = "Shield"; move = 0; }
                else if (levelEnemy->showNextMove() == 2 ) { 
                    if (randMove < 5) {
                        enemyMove = "Attack";
                        move = 1;
                    } else {
                        enemyMove = "Defend";
                        move = 0;
                    }
                 }
                
                printw("%s\nHP: %i\nShields: %i\nAttack Damage: %i\nCritical Chance: %f\nNext Move: %s\n", levelEnemy->getName().c_str(), levelEnemy->getHP(), levelEnemy->getBaseDmg(), levelEnemy->getCritChance(), enemyMove.c_str());
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