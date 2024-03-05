#include "GameBoard.h"
#include <iostream>

GameBoard::GameBoard(int width, int height)
{
    tileSize = std::min(width / COLS, (height - menuHeight) / ROWS);
    initialize();
}

int GameBoard::getRows() {
    return ROWS;
}

int GameBoard::getCols() {
    return COLS;
}

std::vector<std::vector<Candy>> GameBoard::getCandies() {
    return grid;
}

Candy& GameBoard::getCandy(int row, int col) {
    return grid[row][col];
}

int GameBoard::getTileSize() {
    return tileSize;
}

int GameBoard::getMenuHeight() {
    return menuHeight;
}

void GameBoard::initialize()
{
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
           addCandy(i, j);
        }
    }
}

void GameBoard::draw()
{
    ClearBackground(RAYWHITE); // Background color

    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            int posX = j * tileSize;
            int posY = i * tileSize + menuHeight;

            grid[i][j].draw(menuHeight, tileSize);
        }
    }


}

void GameBoard::selectCandy(int row, int col) {
    grid[row][col].setSelected(true);
}

void GameBoard::deselectCandy(int row, int col) {
    grid[row][col].setSelected(false);
}

void GameBoard::swapCandies(int row1, int col1, int row2, int col2)
{
    if (abs(row1 - row2) + abs(col1 - col2) != 1) {
        return;
    }

    grid[row1][col1].swapped(row2, col2);
    grid[row2][col2].swapped(row1, col1);
    std::swap(grid[row1][col1], grid[row2][col2]);

}

void GameBoard::addCandy(int row, int col)
{
    grid[row][col] = Candy(row, col);
}

bool GameBoard::isFull()
{
    for (int j = 0; j < COLS; ++j) {
        if(grid[0][j].getType() == 0)
        {
            return false;
        }
    }
    return true;
}