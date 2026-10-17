#include "SudokuBoard.hpp"
#include <iostream>
#include <array>
#include <cstdlib>
#include <thread>
#include <chrono>

int main() {
    SudokuBoard board;
    board.printBoard();
    if(!board.setCell(0, 0, 5)){
        std::cout << "\033[2J\033[1;1H";
        std::cout << "Failed to set cell (0, 0) to 5" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1500));
        std::cout << "\033[2J\033[1;1H";
        board.printBoard();
    }
    else {        
        std::cout << "\033[2J\033[1;1H";
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        board.printBoard();
    }
    if(!board.setCell(0, 1, 5)){
        std::cout << "\033[2J\033[1;1H";
        std::cout << "Failed to set cell (0, 1) to 5" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        std::cout << "\033[2J\033[1;1H";
        board.printBoard();
    }
    else {        
        std::cout << "\033[2J\033[1;1H";
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        board.printBoard();
    }
    return 0;
}