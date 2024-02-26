#include "CandyCreator.h"
#include <iostream>

CandyCreator::CandyCreator(GameBoard& gameboard) : gameBoard(gameboard)
{
    refillBoard();
}

void CandyCreator::refillBoard()
{
    dropCandies();
}

void CandyCreator::dropCandies()
{
    bool swapped = true;
    while(swapped)
    {
        swapped = false;
        std::cout << "Dropping candies" << std::endl;
        for (int i = gameBoard.getRows()-1; i > 0; --i) {
            std::cout << "Row: " << i << std::endl;
            for (int j = 0; j < gameBoard.getCols(); ++j) {
                if (gameBoard.getCandy(i, j).getType() == 0) {
                    std::cout << "Empty space found at: " << i << ", " << j << std::endl;
                    if(gameBoard.getCandy(i-1, j).getType() != 0) {
                        std::cout << "Swapping candies" << std::endl;
                        gameBoard.swapCandies(i, j, i-1, j);
                        // swapped = true;
                    }
                }
            }
        }
    }
}