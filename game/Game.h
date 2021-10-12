// AQUIF
#ifndef GAME_H
#define GAME_H

#include "../entities/Entity.h"
#include "../entities/Player.h"

class Game {
    public:
        int dimensionTier;
        int level;
        Player main_player;

        Game();
        ~Game();
};

#endif

