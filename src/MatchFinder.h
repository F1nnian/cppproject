#pragma once
#include "GameBoard.h"
#include <set>
#include "Score.h"
#include <unordered_map>

class MatchFinder
{   
public:
    MatchFinder() = default;
    bool checkForMatches(std::vector<std::vector<Candy>>& candies);
    bool removeMatches(std::vector<std::vector<Candy>>& candies, Score& score);

private:
    std::set<Candy*> candiesToRemove;
    std::unordered_map<int, int> countMap;
};