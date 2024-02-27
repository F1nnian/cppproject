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
                        std::cout << "test1" << std::endl;
                    }
                    if(j+1 < gameBoard.getCols() && gameBoard.getCandy(i, j).getType() == gameBoard.getCandy(i, j + 1).getType())
                    {
                        candiesToRemove.insert(&gameBoard.getCandy(i, j));
                        candiesToRemove.insert(&gameBoard.getCandy(i + 1, j));
                        candiesToRemove.insert(&gameBoard.getCandy(i, j + 1));
                        std::cout << "test2" << std::endl;
                    }
                    if(j > 1 && gameBoard.getCandy(i, j).getType() == gameBoard.getCandy(i, j - 1).getType())
                    {
                        candiesToRemove.insert(&gameBoard.getCandy(i, j));
                        candiesToRemove.insert(&gameBoard.getCandy(i + 1, j));
                        candiesToRemove.insert(&gameBoard.getCandy(i, j - 1));
                        std::cout << "test3" << std::endl;
                    }
                    if(j+1 < gameBoard.getCols() && gameBoard.getCandy(i, j).getType() == gameBoard.getCandy(i + 1, j + 1).getType())
                    {
                        candiesToRemove.insert(&gameBoard.getCandy(i, j));
                        candiesToRemove.insert(&gameBoard.getCandy(i + 1, j));
                        candiesToRemove.insert(&gameBoard.getCandy(i + 1, j + 1));
                        std::cout << "test4" << std::endl;
                    }
                    if(j > 1 && gameBoard.getCandy(i, j).getType() == gameBoard.getCandy(i + 1, j - 1).getType())
                    {
                        candiesToRemove.insert(&gameBoard.getCandy(i, j));
                        candiesToRemove.insert(&gameBoard.getCandy(i + 1, j));
                        candiesToRemove.insert(&gameBoard.getCandy(i + 1, j - 1));
                        std::cout << "test5" << std::endl;
                    }
                }
                if (j+1 < gameBoard.getCols() && gameBoard.getCandy(i, j).getType() == gameBoard.getCandy(i, j + 1).getType()) {
                    if(j+2 < gameBoard.getCols() && gameBoard.getCandy(i, j).getType() == gameBoard.getCandy(i, j + 2).getType())
                    {
                        candiesToRemove.insert(&gameBoard.getCandy(i, j));
                        candiesToRemove.insert(&gameBoard.getCandy(i, j + 1));
                        candiesToRemove.insert(&gameBoard.getCandy(i, j + 2));
                        std::cout << "candy found at: " << i << ", " << j << " and " << i << ", " << j + 1 << " and " << i << ", " << j + 2 << std::endl;
                        std::cout << "test6" << std::endl;
                    }
                    if(i + 1 < gameBoard.getRows() && gameBoard.getCandy(i, j).getType() == gameBoard.getCandy(i + 1, j).getType())
                    {
                        candiesToRemove.insert(&gameBoard.getCandy(i, j));
                        candiesToRemove.insert(&gameBoard.getCandy(i, j + 1));
                        candiesToRemove.insert(&gameBoard.getCandy(i + 1, j));
                        std::cout << "test7" << std::endl;
                    }
                    if(i > 1 && gameBoard.getCandy(i, j).getType() == gameBoard.getCandy(i - 1, j).getType())
                    {
                        candiesToRemove.insert(&gameBoard.getCandy(i, j));
                        candiesToRemove.insert(&gameBoard.getCandy(i, j + 1));
                        candiesToRemove.insert(&gameBoard.getCandy(i - 1, j));
                        std::cout << "test8" << std::endl;
                    }
                    if(i + 1 < gameBoard.getRows() && gameBoard.getCandy(i, j).getType() == gameBoard.getCandy(i + 1, j + 1).getType())
                    {
                        candiesToRemove.insert(&gameBoard.getCandy(i, j));
                        candiesToRemove.insert(&gameBoard.getCandy(i, j + 1));
                        candiesToRemove.insert(&gameBoard.getCandy(i + 1, j + 1));
                        std::cout << "test9" << std::endl;
                    }
                    if(i > 1 && gameBoard.getCandy(i, j).getType() == gameBoard.getCandy(i - 1, j + 1).getType())
                    {
                        candiesToRemove.insert(&gameBoard.getCandy(i, j));
                        candiesToRemove.insert(&gameBoard.getCandy(i, j + 1));
                        candiesToRemove.insert(&gameBoard.getCandy(i - 1, j + 1));
                        std::cout << "test10" << std::endl;
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
        std::cout << "Type: " << candy->getType() << std::endl;
        candy->setMatched(true);
    }
    candiesToRemove.clear();
}