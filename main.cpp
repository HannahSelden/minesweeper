//
// Created by Hannah Selden on 2023-05-06.
//
#include "GameBoard.h"
#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
    char selection;
    int selX;
    int selY;
    int size = 0;
    int inputSuccess = false;

    cout << "Welcome to Minesweeper! ";
    while(!inputSuccess){
        cout << "\nPlease select grid size:\n\tA) 9x9\tB) 12x12\tC)15x15\n";
        cin >> selection;
        cout << "\nMake an initial move. Enter X value, then Y value\n";
        cin >> selX;
        cin >> selY;

        inputSuccess = true;
        switch(selection){
            case 'A': size=9; break;
            case 'B': size=12; break;
            case 'C': size=15; break;
            default: inputSuccess = false; break;
        }
        if(selX>=size || selY>=size){
            inputSuccess = false;
        }
    }
    size = 9;
    cout << "Creating game with " << size << "x" << size << " board.";

    auto* board = new GameBoard(size, size);
    board->setMines(10, GridLoc {selX, selY});



    free(board);
    return EXIT_SUCCESS;
}