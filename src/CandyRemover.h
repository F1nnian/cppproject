#pragma once
#include "GameBoard.h"

class CandyRemover
{   
public:
    CandyRemover(GameBoard& gameBoard);
    void checkForMatches();

private:
    GameBoard& gameBoard;
};