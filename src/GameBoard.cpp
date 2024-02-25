#include "GameBoard.h"
#include <vector>
#include <iostream>

GameBoard::GameBoard(int width, int height) : 
    tileSize(std::min(width / COLS, (height - menuHeight) / ROWS)), 
    inputHandler(width, height, tileSize, menuHeight, ROWS, COLS)
{
    initialize();
}

InputHandler GameBoard::getInputHandler() {
    return inputHandler;
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
            grid[i][j].draw(menuHeight, tileSize);
        }
    }


}

void GameBoard::update()
{
    int row = inputHandler.getSelectedRow();
    int col = inputHandler.getSelectedCol();

    if(selectedCandy == nullptr) {
        if(inputHandler.getSelectedRow() != -1 && inputHandler.getSelectedCol() != -1) {
            selectCandy(row, col);
        }
    } else {
        if(inputHandler.getSelectedRow() != -1 && inputHandler.getSelectedCol() != -1) {
            if(abs(row - selectedCandy->getRow()) + abs(col - selectedCandy->getCol()) == 1) {
                selectedCandy->setSelected(false);
                swapCandies(row, col, selectedCandy->getRow(), selectedCandy->getCol());
                selectedCandy = nullptr;
            }else {
                selectedCandy->setSelected(false);
                selectCandy(row, col);
            }
        }
    }
    inputHandler.reset();
}

void GameBoard::selectCandy(int row, int col) {
    grid[row][col].setSelected(true);
    selectedCandy = &grid[row][col];
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