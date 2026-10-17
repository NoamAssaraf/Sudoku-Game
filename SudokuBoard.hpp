
#include <array>
class SudokuBoard{
private:
    std::array<std::array<int , 9> , 9> board;
public:
    SudokuBoard();
    void printBoard();
    bool isValidMove(int row, int col, int num) const;
    bool setCell(int row, int col, int num);
    bool findEmptyCell(int &row, int &col) const;
    bool solve();
    void boardClear();
    void PuzzleCreator();
};