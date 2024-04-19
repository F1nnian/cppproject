// This class is responsible for implementing the game board. It contains a 2D vector of candies, the number of rows and columns, and methods to get and set candies, initialize the board, select candies, deselect candies, swap candies, add candies, check if the board is full, and reset the board.

#include "GameBoard.h"

GameBoard::GameBoard(int ROWS, int COLS) : _ROWS(ROWS), _COLS(COLS)
{
    // Resize the grid to the specified number of rows and columns
    grid.resize(_ROWS);
    for (int i = 0; i < _ROWS; ++i)
    {
        grid[i].resize(_COLS);
    }
    initialize(); // Initialize the board with candies
}

int GameBoard::getRows()
{
    return _ROWS;
}

int GameBoard::getCols()
{
    return _COLS;
}

std::vector<std::vector<Candy>> &GameBoard::getCandies()
{
    return grid;
}

Candy &GameBoard::getCandy(int row, int col)
{
    return grid[row][col];
}

// Initialize the board with candies of random types
void GameBoard::initialize()
{
    for (int i = 0; i < _ROWS; ++i)
    {
        for (int j = 0; j < _COLS; ++j)
        {
            addCandy(i, j);
        }
    }
}

// Select a candy on the board
bool GameBoard::selectCandy(int screenWidth, int screenHeight, int menuHeight, int tileSize)
{
    int mouseX = GetMouseX();
    int mouseY = GetMouseY();
    int row = (mouseY - menuHeight) / tileSize; // Calculate the row of the selected candy
    int col = mouseX / tileSize;                // Calculate the column of the selected candy
    if (grid[row][col].getType() == 0)          // If the selected candy is empty, return false
    {
        return false;
    }

    if (selectedRow == -1 && selectedCol == -1) // If no candy is selected, select the candy
    {
        grid[row][col].setSelected(true);
        selectedRow = row;
        selectedCol = col;
        return true; // Return true to indicate that a candy has been selected
    }
    else // If a candy is already selected, swap the candies if they are adjacent
    {
        deselectCandy(selectedRow, selectedCol);
        if (abs(row - selectedRow) + abs(col - selectedCol) == 1) // Check if the candies are adjacent
        {
            swapCandies(row, col, selectedRow, selectedCol);
            MatchFinder matchFinder;
            if (!matchFinder.checkForMatches(grid)) // If the swap does not result in a match, swap the candies back
            {
                swapCandies(row, col, selectedRow, selectedCol);
            }
            selectedRow = -1; // Deselect the candies
            selectedCol = -1;
            return false; // Return false to indicate that no candy is selected
        }
        else // If the candies are not adjacent, select the new candy
        {
            grid[row][col].setSelected(true);
            selectedRow = row;
            selectedCol = col;
            return true;
        }
    }
}

void GameBoard::deselectCandy(int row, int col)
{
    grid[row][col].setSelected(false);
}

// Swap two candies on the board
void GameBoard::swapCandies(int row1, int col1, int row2, int col2)
{
    if (abs(row1 - row2) + abs(col1 - col2) != 1) // Check if the candies are adjacent
    {
        return;
    }

    grid[row1][col1].swapped(row2, col2);          // Update the row and column of the candy
    grid[row2][col2].swapped(row1, col1);          // Update the row and column of the candy
    std::swap(grid[row1][col1], grid[row2][col2]); // Swap the candies in the grid
}

// Add a candy of a random type to the board
void GameBoard::addCandy(int row, int col)
{
    grid[row][col] = Candy(row, col);
}

// Add a candy of a specific type to the board
void GameBoard::addCandy(int row, int col, int type)
{
    grid[row][col] = Candy(row, col, type);
}

bool GameBoard::isFull()
{
    for (int j = 0; j < _COLS; ++j)
    {
        if (grid[0][j].getType() == 0)
        {
            return false;
        }
    }
    return true;
}

// Reset the board by clearing the grid and initializing it with candies
void GameBoard::reset()
{
    grid.clear();
    grid.resize(_ROWS);
    for (int i = 0; i < _ROWS; ++i)
    {
        grid[i].resize(_COLS);
    }
    initialize();
}