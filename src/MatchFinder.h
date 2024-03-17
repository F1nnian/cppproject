#pragma once
#include "GameBoard.h"
#include <set>

class MatchFinder
{   
public:
    MatchFinder();
    bool checkForMatches(std::vector<std::vector<Candy>>& candies);
    void removeMatches();

private:
    std::set<Candy*> candiesToRemove;
};