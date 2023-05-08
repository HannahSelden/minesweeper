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
    int inputSuccess = false;
    int size = 0;

    cout << "Welcome to Minesweeper! ";
    while(!inputSuccess){
        cout << "\nPlease select grid size:\n\tA) 9x9\tB) 12x12\tC)15x15\n";
        cin >> selection;
        cout << "\nMake an initial move. Write X value, enter, Y value\n";
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
    board->setMines(10, selX, selY);

    for(int i=0; i<9; i++){
        cout << "\n";
        for(int j=0; j<9; j++){
            if(board->isVisible(i,j)){
                cout << "| |";
            }
            else{
                cout << "|#|";
            }
        }
    }
    board->cascade(selX,selY);

    cout << "\n\n\n";

    for(int i=0; i<9; i++){
        cout << "\n";
        for(int j=0; j<9; j++){
            if(board->isVisible(i,j)){
                cout << "| |";
            }
            else{
                cout << "|#|";
            }
        }
    }

    cout << "\n\n\n";

    for(int i=0; i<9; i++){
        cout << "\n";
        for(int j=0; j<9; j++){
            if(board->reveal(i,j)){
                cout << "|" << board->getNumAdjacents(i, j) << "|";
            }
            else {
                cout << "|X|";
            }
        }
    }

    free(board);
    return EXIT_SUCCESS;
}