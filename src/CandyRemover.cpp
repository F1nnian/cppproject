#include "CandyRemover.h"

CandyRemover::CandyRemover(GameBoard& gameBoard) : gameBoard(gameBoard) 
{
    
}

void CandyRemover::checkForMatches(){
    int ROWS = gameBoard.getRows();
    int COLS = gameBoard.getCols();

    

    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            if (i < ROWS - 2 && gameBoard.getCandy(i, j).getType() == gameBoard.getCandy(i + 1, j).getType() && gameBoard.getCandy(i, j).getType() == gameBoard.getCandy(i + 2, j).getType()) {
                gameBoard.getCandy(i, j).setMatch(true);
                gameBoard.getCandy(i + 1, j).setMatch(true);
                gameBoard.getCandy(i + 2, j).setMatch(true);
            }
            if (j < COLS - 2 && gameBoard.getCandy(i, j).getType() == gameBoard.getCandy(i, j + 1).getType() && gameBoard.getCandy(i, j).getType() == gameBoard.getCandy(i, j + 2).getType()) {
                gameBoard.getCandy(i, j).setMatch(true);
                gameBoard.getCandy(i, j + 1).setMatch(true);
                gameBoard.getCandy(i, j + 2).setMatch(true);
            }
        }
    }
}