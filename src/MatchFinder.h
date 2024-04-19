#pragma once
#include "GameBoard.h"
#include <set>
#include "Score.h"
#include <unordered_map>

class MatchFinder
{
public:
    MatchFinder() = default;
    bool checkForMatches(std::vector<std::vector<Candy>> &candies);
    bool removeMatches(std::vector<std::vector<Candy>> &candies, Score &score);
    bool checkForPossibleMatches(std::vector<std::vector<Candy>> &candies);

private:
    std::set<Candy *> candiesToRemove;
    std::unordered_map<int, int> countMap;
    bool hasMatch(std::vector<std::vector<Candy>> &candies);
};