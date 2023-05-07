cmake_minimum_required(VERSION 3.25)
project(minesweeper)

set(CMAKE_CXX_STANDARD 14)

add_executable(minesweeper
        main.cpp GameBoard.h GameBoard.cpp Square.h)
