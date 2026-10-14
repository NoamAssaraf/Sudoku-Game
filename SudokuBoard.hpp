
#include <array>
class SudokuBoard{
private:
    std::array<std::array<int , 9> , 9> board;
public:
    SudokuBoard();
    void printBoard();
};