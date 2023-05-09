//
// Created by Hannah Selden on 2023-05-09.
//

#ifndef MINESWEEPER_PLAYER_H
#define MINESWEEPER_PLAYER_H

#include <string>
#include "GameBoard.h"

class Player {
    private:
        std::string NAME;
        int HIGHSCORE;

    public:
        Player(std::string name, int highscore=0);
        ~Player();
        bool takeTurn(GameBoard* board);
};

#endif //MINESWEEPER_PLAYER_H
