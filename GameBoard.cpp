//
// Created by Hannah Selden on 2023-05-06.
//

#include "GameBoard.h"
#include <cstdlib>
#include <ctime>

using namespace std;

GameBoard::GameBoard(int rows, int cols) {
    ROWS = rows;
    COLS = cols;
    map = new Square*[ROWS];
    for(int i=0; i<ROWS; i++){
        map[i] = new Square[COLS];
    }
}

GameBoard::~GameBoard() {
    for(int i=0; i<ROWS; i++){
        free(map[i]);
    }
    free(map);
}

void GameBoard::setMines(int numMines, GridLoc coord) {
    srand(time(nullptr));

    for(int i=0; i<numMines; i++){
        int mineX = rand() % ROWS;
        int mineY = rand() % COLS;
        if(!(coord.row-1<=mineX && mineX<=coord.row+1)||!(coord.col-1<=mineY && mineY<=coord.col+1)){
            map[mineX][mineY].isClear = false;
            for (int x=mineX-1; x<=mineX+1; x++) {
                for (int y=mineY-1; y<=mineY+1; y++) {
                    if (x>=0 && x<ROWS && y>=0 && y<COLS && (x!=mineX || y!=mineY)) {
                        map[x][y].numAdjacents++;
                    }
                }
            }
        }
        else{
            i++;
        }
    }
}

int GameBoard::getNumAdjacents(GridLoc coord) {
    return map[coord.row][coord.col].numAdjacents;
}

bool GameBoard::isVisible(GridLoc coord) {
    return map[coord.row][coord.col].isVisible;
}

bool GameBoard::reveal(GridLoc coord) {
    map[coord.row][coord.col].isVisible = true;
    return map[coord.row][coord.col].isClear;
}

bool GameBoard::isMarked(GridLoc coord) {
    return map[coord.row][coord.col].isMarked;
}

void GameBoard::toggleMark(GridLoc coord) {
    map[coord.row][coord.col].isMarked = !(map[coord.row][coord.col].isMarked);
}

void GameBoard::cascade(GridLoc coord) {
    if(coord.row<0 || coord.row>ROWS || coord.col<0 || coord.col>COLS ||
        !map[coord.row][coord.col].isClear ||
        map[coord.row][coord.col].numAdjacents>0||
        map[coord.row][coord.col].isVisible){
        return;
    }
    map[coord.row][coord.col].isVisible = true;

    int direction = -1;
    for (int i=0; i<4; i++) {
        int r = coord.row + (i<2 ? direction : 0);
        int c = coord.col + (i<2 ? 0 : direction);
        if (r>=0 && r<ROWS && c>=0 && c<COLS) {
            cascade(GridLoc {r, c});
        }
        direction *= -1;
    }
}

