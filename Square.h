//
// Created by Hannah Selden on 2023-05-06.
//

#ifndef MINESWEEPER_SQUARE_H
#define MINESWEEPER_SQUARE_H

struct Square{
    bool isClear = true;
    bool isVisible = false;
    bool isMarked = false;
    int numAdjacents = 0;
};

#endif //MINESWEEPER_SQUARE_H
