#include "SudokuBoard.hpp"
#include <array>
#include <random>
#include <algorithm>

SudokuBoard::SudokuBoard() {
        boardClear();}


bool SudokuBoard::isValidMove(int row, int col, int num) const {
    // Check if the number is within the valid range (1-9)
    if ((num < 1 || num > 9) || (!isInBounds(row, col))) {
        return false; // Invalid number
    }
    if(fixedCells[row][col]) {
        return false; // Cannot change a fixed cell
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
bool SudokuBoard::findEmptyCell(int &row, int &col) const {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (board[i][j] == 0) {
                row = i;
                col = j;
                return true;
            }
        }
    }
    return false;
}
bool SudokuBoard::solve() {
    int row, col;
    if (!findEmptyCell(row, col)) {
        return true; // Puzzle solved
    }

    for (int num = 1; num <= 9; ++num) {
        if (isValidMove(row, col, num)) {
            board[row][col] = num;

            if (solve()) {
                return true;
            }

            board[row][col] = 0; // Backtrack
        }
    }

    return false; // Trigger backtracking
}
void SudokuBoard::boardClear() {
    board = {};
    fixedCells = {};
}
void SudokuBoard::PuzzleCreator() {
    // Clear the board first
    boardClear();
    std::array<int, 9> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(numbers.begin(), numbers.end(), g);

    for (int i=0; i<9; i++){
        board[0][i] = numbers[i]; 
    }
    solve(); // Solve the board to ensure it's a valid Sudoku puzzle
    int level = g() % 3 + 1; // Random difficulty level between 1 and 3
    int cellsToRemove = level * 20 ;
    while (cellsToRemove > 0) {
        int row = g() % 9;
        int col = g() % 9;

        if (board[row][col] != 0) {
            board[row][col] = 0;
            --cellsToRemove;
        }
    }
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (board[i][j] != 0) {
                fixedCells[i][j] = true;
            }
        }
    }
}
bool SudokuBoard::clearCell(int row, int col) {
    if (isInBounds(row, col)) {
        if (!fixedCells[row][col] && board[row][col] != 0) {
            board[row][col] = 0;
            return true;
        }
    }   
    return false; // Cannot clear a fixed cell
}
void SudokuBoard::resetPlayerMoves() {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (!fixedCells[i][j]) {
                board[i][j] = 0;
            }
        }
    }
}
bool SudokuBoard::isCellFixed(int row, int col) const {
    if (isInBounds(row, col)) {
        return fixedCells[row][col];
    }
    return false;
}
int SudokuBoard::getCell(int row, int col) const {
    if (isInBounds(row, col)) {
        return board[row][col];
    }
    return 0;
}
bool SudokuBoard::isInBounds(int row, int col) const {
    return (row >= 0 && row < 9) && (col >= 0 && col < 9);
}
bool SudokuBoard::isSolved() const {
    int row;
    int col;
    return !findEmptyCell(row,col);
}