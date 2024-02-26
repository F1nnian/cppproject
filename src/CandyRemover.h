#pragma once
#include "GameBoard.h"
#include <set>

class CandyRemover
{   
public:
    CandyRemover(GameBoard& gameBoard);
    bool checkForMatches();
    void removeMatches();

private:
    GameBoard& gameBoard;
    std::set<Candy*> candiesToRemove;
};