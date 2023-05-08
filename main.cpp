//
// Created by Hannah Selden on 2023-05-06.
//
#include "GameBoard.h"
#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
    char selection;
    int inputSuccess = false;
    int size = 0;

    cout << "Welcome to Minesweeper! ";
    /*while(!inputSuccess){
        cout << "\nPlease select grid size:\n\tA) 9x9\tB) 12x12\tC)15x15\n";
        cin >> selection;

        inputSuccess = true;
        switch(selection){
            case 'A': size=9; break;
            case 'B': size=12; break;
            case 'C': size=15; break;
            default: inputSuccess = false; break;
        }
    }*/
    size = 9;
    cout << "Creating game with " << size << "x" << size << " board.";

    auto* board = new GameBoard(9, 9);
    //board->setMines(10);

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
    board->cascade(4,3);

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