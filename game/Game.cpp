#include "Game.h"
#include "../entities/Enemy.h"
#include "../entities/Player.h"

Game::Game(){
    dimensionTier = 1;  // Determines enemy difficulty
    level = 1;          // To let player know what level they are on
}

Game::~Game(){}