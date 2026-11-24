#include "SudokuGame.hpp"
#include <iostream>
#include <thread>
#include <chrono>
#include <limits>

    
    void SudokuGame::printBoard() const{
        for (int i = 0; i < 9; ++i) {
            if (i%3 == 0 && i != 0) {
                std::cout << "-------+--------+------" << std::endl;
            }
            for (int j = 0; j < 9; ++j) {
                if (j%3 == 0 && j != 0) {
                    std::cout << " | ";
                }
               if (board.getCell(i, j) == 0) {
                    std::cout << "* ";
                } else {
                    if(board.isCellFixed(i, j)){
                        std::cout << "\033[1;36m" << board.getCell(i, j) << "\033[0m "; 
                    } else {
                        std::cout << "\033[1;32m" << board.getCell(i, j) << "\033[0m "; 
                    }
                }
            }
            std::cout << std::endl;
        }
    }
    void SudokuGame::handleNextMove() {
        int row, col, num;
        std::cout << "Enter row (1-9), column (1-9) and number (1-9) [Type 0 to go back]: ";
        std::cin >> row;
        if (row == 0) {
            return; 
        }
        std::cin >> col >> num;
        row = row - 1;
        col = col - 1;

        if (!board.setCell(row, col, num)) {
            std::cout << "Invalid move! Try again." << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(1500));
            return; // Invalid move
        }
        if(board.isSolved()){
                std::cout << "\033[2J\033[1;1H"; // Clear the console
                printBoard();
                std::cout << "Congratulations! You've solved the puzzle!" << std::endl;
                return; // Exit the function after solving
            }
    }
    bool SudokuGame::handleClearCellInput() {
        int row, col;
        std::cout << "Enter row (1-9), column (1-9) of cell to clear [Type 0 to go back]: ";
        std::cin >> row;
        if (row == 0) {
            return false; // Go back to the main menu
        }
        std::cin >> col;
        row = row - 1;
        col = col - 1;
        if (!board.clearCell(row, col)) {
            std::cout << "Invalid move! Try again." << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(1500));
            return false; // Invalid move
        }
        return true; // Successful clear
    }
    bool SudokuGame::handleReset() {
        std::cout << "Do you want to reset all your moves? (y/n): ";
        char choice;
        std::cin >> choice;
        if (choice == 'y' || choice == 'Y') {
            board.resetPlayerMoves();
            return true; // Reset successful
        }
        return false; // Reset cancelled
    }
    bool SudokuGame::handleSolve(){
        std::cout << "Do you want me to solve the puzzle? (y/n): ";
        char choice;
        std::cin >> choice;
        if (choice == 'y' || choice == 'Y') {
            if(!board.solve()){
                std::cout << "The puzzle cannot be solved! - you have made a mistake." << std::endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(1500));
                if (handleReset()) { 
                    board.solve(); // Try solving again after reset
                }
                else{
                    return false; // User chose not to reset, exit the solve function
                }
            }
            printBoard();
            return true; // Solve successful
        }
        return false; // Solve cancelled
    }
    bool SudokuGame::gameMenu() {
        int userChoice;
        std::cout << "Menu Options:" << std::endl;
        std::cout << "1. Enter a number" << std::endl;
        std::cout << "2. Clear a cell" << std::endl;
        std::cout << "3. Reset all moves" << std::endl;
        std::cout << "4. Solve the puzzle" << std::endl;
        std::cout << "5. Quit" << std::endl;
        std::cin >> userChoice;
        if (userChoice < 1 || userChoice > 5) {
            std::cout << "Invalid choice! Please select a valid option." << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(1500));
            return false; // Invalid choice
        }
        if (userChoice == 1) {
            handleNextMove();
        } else if (userChoice == 2) {
            handleClearCellInput();
        } else if (userChoice == 3) {
            handleReset();
        } else if (userChoice == 4) {
            handleSolve();
        } else if (userChoice == 5) {
            std::cout << "Thanks for playing!" << std::endl;
            isPlaying = false;
        }
        return true; // Valid choice   
    }
    SudokuGame::SudokuGame(){
        board.PuzzleCreator();
        isPlaying = true;
    }
    void SudokuGame::run() {
        while (isPlaying && !board.isSolved()) {
            std::cout << "\033[2J\033[1;1H"; // Clear the console
            printBoard();
            while(!gameMenu());
        }
        return;
    }          