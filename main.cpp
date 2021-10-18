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
            printw("%s\n", check_char.c_str());
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
    if (game->level < 10) {
        randEnemy = rand() % 250;
        randEnemy = 32;

        if (randEnemy < 60) {
            Grunt grunt(game->dimensionTier);
            levelEnemy = &grunt;
        } else if (randEnemy < 135 && randEnemy >= 60) {
            Slime *levelEnemy = new Slime(game->dimensionTier);
        } else if (randEnemy < 175 && randEnemy >= 135) {
            Assassin *levelEnemy = new Assassin(game->dimensionTier);
        } else if (randEnemy < 220 && randEnemy >= 175) {
            Theif *levelEnemy = new Theif(game->dimensionTier);
        } else if (randEnemy <= 250 && randEnemy >= 220) {
            Tank *levelEnemy = new Tank(game->dimensionTier);
        } else {
            return 1;
        }
    } else {
        randEnemy = rand() % 140;

        if (randEnemy < 50) {
            KingSlime *levelEnemy = new KingSlime(game->dimensionTier);
        } else if (randEnemy < 110 && randEnemy >= 50) {
            Dragon *levelEnemy = new Dragon(game->dimensionTier);
        } else if (randEnemy <= 140 && randEnemy >= 110) {
            Angel *levelEnemy = new Angel(game->dimensionTier);
        } else {
            return 1;
        }
    }
    
    printw("%s", (levelEnemy->getName()).c_str());
    refresh();
    getch();

    endwin();
    return 0;
}