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
                if(i+2 < rows && candies[i][j].getType() == candies[i+1][j].getType() && candies[i][j].getType() == candies[i + 2][j].getType())
                {
                    candiesToRemove.insert(&candies[i][j]);
                    candiesToRemove.insert(&candies[i + 1][j]);
                    candiesToRemove.insert(&candies[i + 2][j]);
                }
                if(j+2 < cols && candies[i][j].getType() == candies[i][j + 1].getType() && candies[i][j].getType() == candies[i][j + 2].getType())
                {
                    candiesToRemove.insert(&candies[i][j]);
                    candiesToRemove.insert(&candies[i][j + 1]);
                    candiesToRemove.insert(&candies[i][j + 2]);
                }
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