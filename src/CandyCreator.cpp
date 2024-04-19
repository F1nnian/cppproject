// This class is responsible for creating and refilling candies on the game board. It contains a map of candy types and their quantities, and methods to create candies, check if candies are left, refill the board, and reset the candy map.

#include "CandyCreator.h"

CandyCreator::CandyCreator(GameBoard &gameBoard, int refillCandies) : gameBoard(gameBoard), refillCandies(refillCandies)
{
    createCandyMap();
}

// Create a map of candy types and their quantities (for refilling the board)
void CandyCreator::createCandyMap()
{
    for (int i = 0; i < refillCandies; ++i)
    {
        int randomType = std::rand() % NUM_TYPES;
        candyMap[randomType]++;
    }
}

bool CandyCreator::areCandiesLeft()
{
    for (int i = 0; i < NUM_TYPES; ++i)
    {
        if (candyMap[i] > 0)
            return true;
    }
    return false;
}

std::map<int, int> CandyCreator::getCandyMap()
{
    return candyMap;
}

// Refill the board if there are empty spaces
void CandyCreator::refillBoard()
{
    dropCandies(); // Drop candies to the bottom of the board
    while (!gameBoard.isFull())
    {
        for (int j = 0; j < gameBoard.getCols(); ++j)
        {
            if (gameBoard.getCandy(0, j).getType() == 0)
            {
                if (!areCandiesLeft())
                    return;
                createCandy(j); // Create a new candy at the top of the board
            }
        }
    }
}

// Drop candies to the bottom of the board
void CandyCreator::dropCandies()
{
    bool swapped = true;
    while (swapped)
    {
        swapped = false;
        for (int i = gameBoard.getRows() - 1; i > 0; --i)
        {
            for (int j = 0; j < gameBoard.getCols(); ++j)
            {
                if (gameBoard.getCandy(i, j).getType() == 0)
                {
                    if (gameBoard.getCandy(i - 1, j).getType() != 0)
                    {
                        gameBoard.swapCandies(i, j, i - 1, j);
                        swapped = true;
                    }
                }
            }
        }
    }
}

// Create a new candy at the top of the board from candy map (refill candies)
void CandyCreator::createCandy(int col)
{
    if (gameBoard.getCandy(0, col).getType() != 0) // If the top candy is not empty,
        return;
    int randomType = std::rand() % NUM_TYPES; // Randomly select a candy type
    // If there are no candies of a certain type left, set the type to -1
    if (candyMap[0] == 0 && candyMap[1] == 0 && candyMap[2] == 0 && candyMap[3] == 0 && candyMap[4] == 0 && candyMap[5] == 0)
    {
        randomType = -1;
    }
    // If there are no candies of the selected type left, select a different type
    while (candyMap[randomType] == 0)
    {
        randomType = std::rand() % NUM_TYPES;
    }
    gameBoard.addCandy(0, col, randomType + 1);
    candyMap[randomType]--; // Decrease the quantity of the selected candy type
    dropCandies();          // Drop candies to the bottom of the board
}

void CandyCreator::reset()
{
    candyMap.clear();
    createCandyMap();
}