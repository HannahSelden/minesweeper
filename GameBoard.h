//
// Created by Hannah Selden on 2023-05-06.
//

#ifndef MINESWEEPER_GAMEBOARD_H
#define MINESWEEPER_GAMEBOARD_H

#include "Square.h"

class GameBoard {
    private:
        int ROWS;
        int COLS;
        Square **map;

    public:
        GameBoard(int rows, int cols);
        ~GameBoard();
        void setMines(int numMines);
        int getNumAdjacents(int row, int col);
        bool isVisible(int row, int col);
        bool reveal(int row, int col);
        bool isMarked(int row, int col);
        void toggleMark(int row, int col);
        void cascade(int row, int col);


};


#endif //MINESWEEPER_GAMEBOARD_H
