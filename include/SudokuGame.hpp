#pragma once

#include "SudokuBoard.hpp"

class SudokuGame {
private:
    SudokuBoard board;
    bool isPlaying;
    void printBoard()const;
    void handleNextMove();
    bool handleClearCellInput();
    bool handleReset();
    bool handleSolve();
    bool gameMenu() ;
public:
    SudokuGame();
    void run();
};