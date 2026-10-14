cmake_minimum_required(VERSION 3.10)
project(SudokuGame)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(SudokuGame main.cpp SudokuBoard.cpp)