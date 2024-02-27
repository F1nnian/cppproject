#pragma once
#include "GameBoard.h"
#include <set>

class MatchFinder
{   
public:
    MatchFinder(GameBoard& gameBoard);
    bool checkForMatches();
    void removeMatches();

private:
    GameBoard& gameBoard;
    std::set<Candy*> candiesToRemove;
};