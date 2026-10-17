#include "SudokuBoard.hpp"
#include <iostream>
#include <array>

int main() {
    SudokuBoard board;
    board.printBoard();
    board.setCell(0, 0, 5);
    board.setCell(0, 1, 5); // This should fail because 5 is already in the row
    return 0;
}