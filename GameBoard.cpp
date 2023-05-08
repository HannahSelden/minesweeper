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

void GameBoard::setMines(int numMines, int row, int col) {
    srand(time(nullptr));

    for(int i=0; i<numMines; i++){
        int mineX = rand() % ROWS;
        int mineY = rand() % COLS;
        if(!(row-1<=mineX && mineX<=row+1)||!(col-1<=mineY && mineY<=col+1)){
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

int GameBoard::getNumAdjacents(int row, int col) {
    return map[row][col].numAdjacents;
}

bool GameBoard::isVisible(int row, int col) {
    return map[row][col].isVisible;
}

bool GameBoard::reveal(int row, int col) {
    map[row][col].isVisible = true;
    return map[row][col].isClear;
}

bool GameBoard::isMarked(int row, int col) {
    return map[row][col].isMarked;
}

void GameBoard::toggleMark(int row, int col) {
    map[row][col].isMarked = !(map[row][col].isMarked);
}

void GameBoard::cascade(int row, int col) {
    if(row<0 || row>ROWS || col<0 || col>COLS ||
        !map[row][col].isClear || map[row][col].numAdjacents>0|| map[row][col].isVisible){
        return;
    }
    map[row][col].isVisible = true;

    for (int r=row-1; r<=row+1; r++) {
        for (int c=col-1; c<=col+1; c++) {
            if (r>=0 && r<ROWS && c>=0 && c<COLS && (r!=row || c!=col)) {
                cascade(r, c);
            }
        }
    }
}

