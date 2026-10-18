#include "SudokuBoard.hpp"
#include <iostream>
#include <array>
#include <cstdlib>
#include <thread>
#include <chrono>

int main() {
    SudokuBoard board;
    board.PuzzleCreator();
    while (true) {
        std::cout << "\033[2J\033[1;1H"; // Clear the console
        board.printBoard();
        int row, col, num;
        std::cout << "Enter row (1-9), column (1-9) and number (1-9) [Type 0 to quit]: ";
        std::cin >> row;
        if (row == 0) {
            std::cout << "Thanks for playing!" << std::endl;
            break; // פקודה ששוברת את לולאת ה-while ומוציאה אותנו מהמשחק
        }
        std::cin >> col >> num;
        row = row - 1;
        col = col - 1;

        if (!board.setCell(row, col, num)) {
            std::cout << "Invalid move! Try again." << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(1500));
        }
        else{
            int dummyRow, dummyCol;
            if(!board.findEmptyCell(dummyRow, dummyCol)){
                std::cout << "\033[2J\033[1;1H"; // Clear the console
                board.printBoard();
                std::cout << "Congratulations! You've solved the puzzle!" << std::endl;
                break;
            }
        }
    }       
    return 0;
}