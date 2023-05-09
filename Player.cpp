//
// Created by Hannah Selden on 2023-05-09.
//

#include <string>
#include "Player.h"

using namespace std;

Player::Player(string name, int highscore) {
    NAME = name;
    HIGHSCORE = highscore;
}

Player::~Player() = default;

bool Player::takeTurn(GameBoard *board) {
    return false;
}


