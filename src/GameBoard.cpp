#include "GameBoard.h"

GameBoard::GameBoard(int ROWS, int COLS) : _ROWS(ROWS), _COLS(COLS)
{
    grid.resize(_ROWS);
    for (int i = 0; i < _ROWS; ++i) {
        grid[i].resize(_COLS);
    }
    initialize();
}

int GameBoard::getRows() {
    return _ROWS;
}

int GameBoard::getCols() {
    return _COLS;
}

std::vector<std::vector<Candy>>& GameBoard::getCandies() {
    return grid;
}

Candy& GameBoard::getCandy(int row, int col) {
    return grid[row][col];
}

void GameBoard::initialize()
{
    for (int i = 0; i < _ROWS; ++i) {
        for (int j = 0; j < _COLS; ++j) {
           addCandy(i, j);
        }
    }
}

bool GameBoard::selectCandy(int screenWidth, int screenHeight, int menuHeight, int tileSize) {
        int mouseX = GetMouseX();
        int mouseY = GetMouseY();
        int row = (mouseY - menuHeight) / tileSize;
        int col = mouseX / tileSize;
        if(grid[row][col].getType() == 0)
        {
            return false;
        }

        if(selectedRow == -1 && selectedCol == -1) {
            grid[row][col].setSelected(true);
            selectedRow = row;
            selectedCol = col;
            return true;
        } else {
            deselectCandy(selectedRow, selectedCol);
            if(abs(row - selectedRow) + abs(col - selectedCol) == 1) {
                swapCandies(row, col, selectedRow, selectedCol);
                MatchFinder matchFinder;
                if(!matchFinder.checkForMatches(grid))
                {
                    swapCandies(row, col, selectedRow, selectedCol);
                }
                selectedRow = -1;
                selectedCol = -1;
                return false;
            }else {
                grid[row][col].setSelected(true);
                selectedRow = row;
                selectedCol = col;
                return true;
            }
        }
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

void GameBoard::addCandy(int row, int col, int type)
{
    grid[row][col] = Candy(row, col, type);
}

bool GameBoard::isFull()
{
    for (int j = 0; j < _COLS; ++j) {
        if(grid[0][j].getType() == 0)
        {
            return false;
        }
    }
    return true;
}