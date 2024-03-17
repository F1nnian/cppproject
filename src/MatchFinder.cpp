#include "MatchFinder.h"
#include <iostream>

MatchFinder::MatchFinder()
{
}

bool MatchFinder::checkForMatches(std::vector<std::vector<Candy>>& candies)
{
    int rows = candies.size();
    int cols = candies[0].size();
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if(candies[i][j].getType() != 0)
            {
                if(i+2 < rows && candies[i][j].getType() == candies[i+1][j].getType() == candies[i + 2][j].getType())
                {
                    candiesToRemove.insert(&candies[i][j]);
                    candiesToRemove.insert(&candies[i + 1][j]);
                    candiesToRemove.insert(&candies[i + 2][j]);
                }
                if(j+2 < cols && candies[i][j].getType() == candies[i][j + 1].getType() == candies[i][j + 2].getType())
                {
                    candiesToRemove.insert(&candies[i][j]);
                    candiesToRemove.insert(&candies[i][j + 1]);
                    candiesToRemove.insert(&candies[i][j + 2]);
                }
                // if (j+1 < cols && candies[i][j].getType() == candies[i][j + 1].getType()) {
                //     if(j+2 < cols && candies[i][j].getType() == candies[i][j + 2].getType())
                //     {
                //         candiesToRemove.insert(&candies[i][j]);
                //         candiesToRemove.insert(&candies[i][j + 1]);
                //         candiesToRemove.insert(&candies[i][j + 2]);
                //     }
                // }
            //     if (i+1 < gameBoard.getRows() && gameBoard.getCandy(i, j).getType() == gameBoard.getCandy(i + 1, j).getType()) {
            //         if(i+2 < gameBoard.getRows() && gameBoard.getCandy(i, j).getType() == gameBoard.getCandy(i + 2, j).getType())
            //         {
            //             candiesToRemove.insert(&gameBoard.getCandy(i, j));
            //             candiesToRemove.insert(&gameBoard.getCandy(i + 1, j));
            //             candiesToRemove.insert(&gameBoard.getCandy(i + 2, j));
            //         }
            //         if(j+1 < gameBoard.getCols() && gameBoard.getCandy(i, j).getType() == gameBoard.getCandy(i, j + 1).getType())
            //         {
            //             candiesToRemove.insert(&gameBoard.getCandy(i, j));
            //             candiesToRemove.insert(&gameBoard.getCandy(i + 1, j));
            //             candiesToRemove.insert(&gameBoard.getCandy(i, j + 1));
            //         }
            //         if(j > 1 && gameBoard.getCandy(i, j).getType() == gameBoard.getCandy(i, j - 1).getType())
            //         {
            //             candiesToRemove.insert(&gameBoard.getCandy(i, j));
            //             candiesToRemove.insert(&gameBoard.getCandy(i + 1, j));
            //             candiesToRemove.insert(&gameBoard.getCandy(i, j - 1));
            //         }
            //         if(j+1 < gameBoard.getCols() && gameBoard.getCandy(i, j).getType() == gameBoard.getCandy(i + 1, j + 1).getType())
            //         {
            //             candiesToRemove.insert(&gameBoard.getCandy(i, j));
            //             candiesToRemove.insert(&gameBoard.getCandy(i + 1, j));
            //             candiesToRemove.insert(&gameBoard.getCandy(i + 1, j + 1));
            //         }
            //         if(j > 1 && gameBoard.getCandy(i, j).getType() == gameBoard.getCandy(i + 1, j - 1).getType())
            //         {
            //             candiesToRemove.insert(&gameBoard.getCandy(i, j));
            //             candiesToRemove.insert(&gameBoard.getCandy(i + 1, j));
            //             candiesToRemove.insert(&gameBoard.getCandy(i + 1, j - 1));
            //         }
            //     }
            //     if (j+1 < gameBoard.getCols() && gameBoard.getCandy(i, j).getType() == gameBoard.getCandy(i, j + 1).getType()) {
            //         if(j+2 < gameBoard.getCols() && gameBoard.getCandy(i, j).getType() == gameBoard.getCandy(i, j + 2).getType())
            //         {
            //             candiesToRemove.insert(&gameBoard.getCandy(i, j));
            //             candiesToRemove.insert(&gameBoard.getCandy(i, j + 1));
            //             candiesToRemove.insert(&gameBoard.getCandy(i, j + 2));
            //         }
            //         if(i + 1 < gameBoard.getRows() && gameBoard.getCandy(i, j).getType() == gameBoard.getCandy(i + 1, j).getType())
            //         {
            //             candiesToRemove.insert(&gameBoard.getCandy(i, j));
            //             candiesToRemove.insert(&gameBoard.getCandy(i, j + 1));
            //             candiesToRemove.insert(&gameBoard.getCandy(i + 1, j));
            //         }
            //         if(i > 1 && gameBoard.getCandy(i, j).getType() == gameBoard.getCandy(i - 1, j).getType())
            //         {
            //             candiesToRemove.insert(&gameBoard.getCandy(i, j));
            //             candiesToRemove.insert(&gameBoard.getCandy(i, j + 1));
            //             candiesToRemove.insert(&gameBoard.getCandy(i - 1, j));
            //         }
            //         if(i + 1 < gameBoard.getRows() && gameBoard.getCandy(i, j).getType() == gameBoard.getCandy(i + 1, j + 1).getType())
            //         {
            //             candiesToRemove.insert(&gameBoard.getCandy(i, j));
            //             candiesToRemove.insert(&gameBoard.getCandy(i, j + 1));
            //             candiesToRemove.insert(&gameBoard.getCandy(i + 1, j + 1));
            //         }
            //         if(i > 1 && gameBoard.getCandy(i, j).getType() == gameBoard.getCandy(i - 1, j + 1).getType())
            //         {
            //             candiesToRemove.insert(&gameBoard.getCandy(i, j));
            //             candiesToRemove.insert(&gameBoard.getCandy(i, j + 1));
            //             candiesToRemove.insert(&gameBoard.getCandy(i - 1, j + 1));
            //         }
            //     }
            // }
            }
        }
    }
    return !candiesToRemove.empty();
}

void MatchFinder::removeMatches()
{
    for(auto candy : candiesToRemove) {
        candy->setMatched(true);
    }
    candiesToRemove.clear();
}