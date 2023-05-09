//
// Created by Hannah Selden on 2023-05-06.
//

#ifndef MINESWEEPER_GAMEBOARD_H
#define MINESWEEPER_GAMEBOARD_H

#include "Square.h"
#include "GridLoc.h"

class GameBoard {
    private:
        int ROWS;
        int COLS;
        Square **map;

    public:
        GameBoard(int rows, int cols);
        ~GameBoard();
        void setMines(int numMines, GridLoc coord);
        int getNumAdjacents(GridLoc coord);
        bool isVisible(GridLoc coord);
        bool reveal(GridLoc coord);
        bool isMarked(GridLoc coord);
        void toggleMark(GridLoc coord);
        void cascade(GridLoc coord);
};


#endif //MINESWEEPER_GAMEBOARD_H
