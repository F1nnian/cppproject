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
            grid[i][j] = Candy(i, j);
        }
    }
}

void GameBoard::draw()
{
    // Clear the screen
    ClearBackground(RAYWHITE); // Background color

    // Calculate cell width and height

    // Draw candies on the grid
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            // Calculate position of the current cell
            int posX = j * tileSize;
            int posY = i * tileSize + menuHeight;

            // Draw candy at the position (posX, posY)
            // Assuming Candy class has a method draw(int x, int y) to draw the candy
            // std::cout << grid[i][j].getType() << std::endl;
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

    std::swap(grid[row1][col1], grid[row2][col2]);
    grid[row1][col1].swapped(row1, col1);
    grid[row2][col2].swapped(row2, col2);
}