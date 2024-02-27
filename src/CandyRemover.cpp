#include "CandyRemover.h"
#include <iostream>

CandyRemover::CandyRemover(GameBoard& gameBoard) : gameBoard(gameBoard) 
{
    checkForMatches();
    removeMatches();
}

bool CandyRemover::checkForMatches()
{
    int ROWS = gameBoard.getRows();
    int COLS = gameBoard.getCols();
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            if(gameBoard.getCandy(i, j).getType() != 0)
            {
                if (i+1 < gameBoard.getRows() && gameBoard.getCandy(i, j).getType() == gameBoard.getCandy(i + 1, j).getType()) {
                    if(i+2 < gameBoard.getRows() && gameBoard.getCandy(i, j).getType() == gameBoard.getCandy(i + 2, j).getType())
                    {
                        candiesToRemove.insert(&gameBoard.getCandy(i, j));
                        candiesToRemove.insert(&gameBoard.getCandy(i + 1, j));
                        candiesToRemove.insert(&gameBoard.getCandy(i + 2, j));
                    }
                    if(j+1 < gameBoard.getCols() && gameBoard.getCandy(i, j).getType() == gameBoard.getCandy(i, j + 1).getType())
                    {
                        candiesToRemove.insert(&gameBoard.getCandy(i, j));
                        candiesToRemove.insert(&gameBoard.getCandy(i + 1, j));
                        candiesToRemove.insert(&gameBoard.getCandy(i, j + 1));
                    }
                    if(j > 1 && gameBoard.getCandy(i, j).getType() == gameBoard.getCandy(i, j - 1).getType())
                    {
                        candiesToRemove.insert(&gameBoard.getCandy(i, j));
                        candiesToRemove.insert(&gameBoard.getCandy(i + 1, j));
                        candiesToRemove.insert(&gameBoard.getCandy(i, j - 1));
                    }
                    if(j+1 < gameBoard.getCols() && gameBoard.getCandy(i, j).getType() == gameBoard.getCandy(i + 1, j + 1).getType())
                    {
                        candiesToRemove.insert(&gameBoard.getCandy(i, j));
                        candiesToRemove.insert(&gameBoard.getCandy(i + 1, j));
                        candiesToRemove.insert(&gameBoard.getCandy(i + 1, j + 1));
                    }
                    if(j > 1 && gameBoard.getCandy(i, j).getType() == gameBoard.getCandy(i + 1, j - 1).getType())
                    {
                        candiesToRemove.insert(&gameBoard.getCandy(i, j));
                        candiesToRemove.insert(&gameBoard.getCandy(i + 1, j));
                        candiesToRemove.insert(&gameBoard.getCandy(i + 1, j - 1));
                    }
                }
                if (j+1 < gameBoard.getCols() && gameBoard.getCandy(i, j).getType() == gameBoard.getCandy(i, j + 1).getType()) {
                    if(j+2 < gameBoard.getCols() && gameBoard.getCandy(i, j).getType() == gameBoard.getCandy(i, j + 2).getType())
                    {
                        candiesToRemove.insert(&gameBoard.getCandy(i, j));
                        candiesToRemove.insert(&gameBoard.getCandy(i, j + 1));
                        candiesToRemove.insert(&gameBoard.getCandy(i, j + 2));
                    }
                    if(i + 1 < gameBoard.getRows() && gameBoard.getCandy(i, j).getType() == gameBoard.getCandy(i + 1, j).getType())
                    {
                        candiesToRemove.insert(&gameBoard.getCandy(i, j));
                        candiesToRemove.insert(&gameBoard.getCandy(i, j + 1));
                        candiesToRemove.insert(&gameBoard.getCandy(i + 1, j));
                    }
                    if(i > 1 && gameBoard.getCandy(i, j).getType() == gameBoard.getCandy(i - 1, j).getType())
                    {
                        candiesToRemove.insert(&gameBoard.getCandy(i, j));
                        candiesToRemove.insert(&gameBoard.getCandy(i, j + 1));
                        candiesToRemove.insert(&gameBoard.getCandy(i - 1, j));
                    }
                    if(i + 1 < gameBoard.getRows() && gameBoard.getCandy(i, j).getType() == gameBoard.getCandy(i + 1, j + 1).getType())
                    {
                        candiesToRemove.insert(&gameBoard.getCandy(i, j));
                        candiesToRemove.insert(&gameBoard.getCandy(i, j + 1));
                        candiesToRemove.insert(&gameBoard.getCandy(i + 1, j + 1));
                    }
                    if(i > 1 && gameBoard.getCandy(i, j).getType() == gameBoard.getCandy(i - 1, j + 1).getType())
                    {
                        candiesToRemove.insert(&gameBoard.getCandy(i, j));
                        candiesToRemove.insert(&gameBoard.getCandy(i, j + 1));
                        candiesToRemove.insert(&gameBoard.getCandy(i - 1, j + 1));
                    }
                }
            }
        }
    }
    return !candiesToRemove.empty();
}

void CandyRemover::removeMatches()
{
    for(auto candy : candiesToRemove) {
        candy->setMatched(true);
    }
    candiesToRemove.clear();
}