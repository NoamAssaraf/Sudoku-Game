#include "SudokuBoard.hpp"
#include <array>
#include <iostream>

SudokuBoard::SudokuBoard() {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            board[i][j] = 0;
        }
    }
}

void SudokuBoard::printBoard() {
    for (int i = 0; i < 9; ++i) {
        if (i%3 == 0 && i != 0) {
            std::cout << "--------+-------+------" << std::endl;
        }
        for (int j = 0; j < 9; ++j) {
            if (j%3 == 0 && j != 0) {
                std::cout << " | ";
            }
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
}