#include "CandyRemover.h"
#include <set>

CandyRemover::CandyRemover(GameBoard& gameBoard) : gameBoard(gameBoard) 
{
    
}

void CandyRemover::checkForMatches(){
    int ROWS = gameBoard.getRows();
    int COLS = gameBoard.getCols();
    std::set<Candy*> candiesToRemove;

    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            if (gameBoard.getCandy(i, j).getType() == gameBoard.getCandy(i + 1, j).getType()) {
                if(gameBoard.getCandy(i, j).getType() == gameBoard.getCandy(i + 2, j).getType())
                {
                    candiesToRemove.insert(&gameBoard.getCandy(i, j));
                    candiesToRemove.insert(&gameBoard.getCandy(i + 1, j));
                    candiesToRemove.insert(&gameBoard.getCandy(i + 2, j));
                }
                if(gameBoard.getCandy(i, j).getType() == gameBoard.getCandy(i, j + 1).getType())
                {
                    candiesToRemove.insert(&gameBoard.getCandy(i, j));
                    candiesToRemove.insert(&gameBoard.getCandy(i + 1, j));
                    candiesToRemove.insert(&gameBoard.getCandy(i, j + 1));
                }
                if(gameBoard.getCandy(i, j).getType() == gameBoard.getCandy(i, j - 1).getType())
                {
                    candiesToRemove.insert(&gameBoard.getCandy(i, j));
                    candiesToRemove.insert(&gameBoard.getCandy(i + 1, j));
                    candiesToRemove.insert(&gameBoard.getCandy(i, j - 1));
                }
                if(gameBoard.getCandy(i, j).getType() == gameBoard.getCandy(i + 1, j + 1).getType())
                {
                    candiesToRemove.insert(&gameBoard.getCandy(i, j));
                    candiesToRemove.insert(&gameBoard.getCandy(i + 1, j));
                    candiesToRemove.insert(&gameBoard.getCandy(i + 1, j + 1));
                }
                if(gameBoard.getCandy(i, j).getType() == gameBoard.getCandy(i + 1, j - 1).getType())
                {
                    candiesToRemove.insert(&gameBoard.getCandy(i, j));
                    candiesToRemove.insert(&gameBoard.getCandy(i + 1, j));
                    candiesToRemove.insert(&gameBoard.getCandy(i + 1, j - 1));
                }
            }
            if (gameBoard.getCandy(i, j).getType() == gameBoard.getCandy(i, j + 1).getType()) {
                if(gameBoard.getCandy(i, j).getType() == gameBoard.getCandy(i, j + 2).getType())
                {
                    candiesToRemove.insert(&gameBoard.getCandy(i, j));
                    candiesToRemove.insert(&gameBoard.getCandy(i, j + 1));
                    candiesToRemove.insert(&gameBoard.getCandy(i, j + 2));
                }
                if(gameBoard.getCandy(i, j).getType() == gameBoard.getCandy(i + 1, j).getType())
                {
                    candiesToRemove.insert(&gameBoard.getCandy(i, j));
                    candiesToRemove.insert(&gameBoard.getCandy(i, j + 1));
                    candiesToRemove.insert(&gameBoard.getCandy(i + 1, j));
                }
                if(gameBoard.getCandy(i, j).getType() == gameBoard.getCandy(i - 1, j).getType())
                {
                    candiesToRemove.insert(&gameBoard.getCandy(i, j));
                    candiesToRemove.insert(&gameBoard.getCandy(i, j + 1));
                    candiesToRemove.insert(&gameBoard.getCandy(i - 1, j));
                }
                if(gameBoard.getCandy(i, j).getType() == gameBoard.getCandy(i + 1, j + 1).getType())
                {
                    candiesToRemove.insert(&gameBoard.getCandy(i, j));
                    candiesToRemove.insert(&gameBoard.getCandy(i, j + 1));
                    candiesToRemove.insert(&gameBoard.getCandy(i + 1, j + 1));
                }
                if(gameBoard.getCandy(i, j).getType() == gameBoard.getCandy(i - 1, j + 1).getType())
                {
                    candiesToRemove.insert(&gameBoard.getCandy(i, j));
                    candiesToRemove.insert(&gameBoard.getCandy(i, j + 1));
                    candiesToRemove.insert(&gameBoard.getCandy(i - 1, j + 1));
                }
            }
        }
    }
    for(auto candy : candiesToRemove) {
        candy->setMatched(true);
    }
}