#pragma once
#include <algorithm>
#include "Candy.h"
#include <cstdlib> 
#include <ctime>
#include <raylib.h>

class GameBoard
{
public:
    GameBoard(int width, int height);
    void initialize(); // SRP: Handles only the initialization of the board
    void update();     // SRP: Handles only the update of the board state
    void draw();       // SRP: Handles only drawing the board
    void swapCandies(int row1, int col1, int row2, int col2);
    void selectCandy(int row, int col);
    void deselectCandy(int row, int col);
    int getRows();
    int getCols();
    int getTileSize();
    int getMenuHeight();
    Candy& getCandy(int row, int col);
    void addCandy(int row, int col);
    bool isFull();
private:
    static const int ROWS = 16;
    static const int COLS = 8;
    int tileSize;
    static const int menuHeight = 50;
    Candy grid[ROWS][COLS];
    Candy *selectedCandy = nullptr;
};