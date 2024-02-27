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
    if(gameBoard.getCandy(1, col).getType() != 0) return;
    gameBoard.addCandy(1, col);
    dropCandies();
}