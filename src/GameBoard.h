#pragma once
#include <algorithm>
#include "Candy.h"
#include <cstdlib> 
#include <ctime>
#include <raylib.h>
#include <vector>

class GameBoard
{
public:
    
    GameBoard(int ROWS, int COLS);
    void initialize();
    void swapCandies(int row1, int col1, int row2, int col2);
    void selectCandy(int row, int col);
    void deselectCandy(int row, int col);
    int getRows();
    int getCols();
    std::vector<std::vector<Candy>>& getCandies();
    Candy& getCandy(int row, int col);
    void addCandy(int row, int col);
    bool isFull();
private:
    const int _ROWS;
    const int _COLS;
    std::vector<std::vector<Candy>> grid;
    Candy *selectedCandy = nullptr;
};