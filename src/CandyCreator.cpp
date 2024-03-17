#include "CandyCreator.h"
#include <iostream>

CandyCreator::CandyCreator(GameBoard& gameBoard) : gameBoard(gameBoard)
{
}

void CandyCreator::refillBoard()
{
    dropCandies();
    while (!gameBoard.isFull())
    {
        for (int j = 0; j < gameBoard.getCols(); ++j) {
            if(gameBoard.getCandy(0, j).getType() == 0)
            {
                createCandy(j);
            }
        }
    }
    
}

void CandyCreator::dropCandies()
{
    bool swapped = true;
    while(swapped)
    {
        swapped = false;
        for (int i = gameBoard.getRows()-1; i > 0; --i) {
            for (int j = 0; j < gameBoard.getCols(); ++j) {
                if (gameBoard.getCandy(i, j).getType() == 0) {
                    if(gameBoard.getCandy(i-1, j).getType() != 0) {
                        gameBoard.swapCandies(i, j, i-1, j);
                        swapped = true;
                    }
                }
            }
        }
    }
}

void CandyCreator::createCandy(int col)
{
    if(gameBoard.getCandy(0, col).getType() != 0) return;
    gameBoard.addCandy(0, col);
    dropCandies();
}