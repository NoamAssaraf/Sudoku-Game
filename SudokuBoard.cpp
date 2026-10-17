#include "SudokuBoard.hpp"
#include <array>
#include <iostream>
#include <cstdlib>
#include <thread>
#include <chrono>

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
            std::cout << "-------+--------+------" << std::endl;
        }
        for (int j = 0; j < 9; ++j) {
            if (j%3 == 0 && j != 0) {
                std::cout << " | ";
            }
            if (board[i][j] == 0) {
                std::cout << "* ";
            } else {
                std::cout << board[i][j] << " ";
            }
        }
        std::cout << std::endl;

    }
}

bool SudokuBoard::isValidMove(int row, int col, int num) const {
    // Check if the number is within the valid range (1-9)
    if (num < 1 || num > 9) {
        return false; // Invalid number
    }
    // Check if the number is already in the row
    for (int j = 0; j < 9; ++j) {
        if (board[row][j] == num) {
            return false;
        }
    }

    // Check if the number is already in the column
    for (int i = 0; i < 9; ++i) {
        if (board[i][col] == num) {
            return false;
        }
    }

    // Check if the number is already in the 3x3 subgrid
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }

    return true;
}

bool SudokuBoard::setCell(int row, int col, int num) {
    if (isValidMove(row, col, num)) {
        board[row][col] = num;
        return true;
    } else {
        return false;
    }
}
