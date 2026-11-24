#pragma once

#include <array>
class SudokuBoard{
private:
    std::array<std::array<int ,9>,9> board;
    std::array<std::array<bool ,9>,9> fixedCells;
    bool findEmptyCell(int &row, int &col) const;
    bool isInBounds(int row, int col) const;

public:
    SudokuBoard();
    bool isValidMove(int row, int col, int num) const;
    bool setCell(int row, int col, int num);
    bool solve();
    void boardClear();
    void PuzzleCreator();
    bool clearCell(int row, int col);
    void resetPlayerMoves();
    bool isCellFixed(int row, int col) const;
    int getCell(int row, int col) const;
    bool isSolved() const;

};