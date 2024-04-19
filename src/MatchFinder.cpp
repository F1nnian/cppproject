#include "MatchFinder.h"

bool MatchFinder::checkForMatches(std::vector<std::vector<Candy>> &candies)
{
    int rows = candies.size();
    int cols = candies[0].size();

    bool validMatchFound = false;

    for (int i = 0; i < rows; ++i)
    {
        int count = 1;
        for (int j = 1; j < cols; ++j)
        {
            if (candies[i][j].getType() == candies[i][j - 1].getType() && candies[i][j].getType() != 0)
            {
                ++count;
                if (count >= 3)
                {
                    if (count == 3)
                    {
                        candiesToRemove.insert({&candies[i][j - 2], &candies[i][j - 1]});
                    }
                    candiesToRemove.insert({&candies[i][j], &candies[i][j - 1]});
                    validMatchFound = true;
                }
            }
            else
            {
                if (count >= 3)
                {
                    countMap[count]++;
                }
                count = 1;
            }
        }
        if (count >= 3)
        {
            countMap[count]++;
        }
    }

    for (int j = 0; j < cols; ++j)
    {
        int count = 1;
        for (int i = 1; i < rows; ++i)
        {
            if (candies[i][j].getType() == candies[i - 1][j].getType() && candies[i][j].getType() != 0)
            {
                ++count;
                if (count >= 3)
                {
                    if (count == 3)
                    {
                        candiesToRemove.insert({&candies[i - 2][j], &candies[i - 1][j]});
                    }
                    candiesToRemove.insert({&candies[i][j], &candies[i - 1][j]});
                    validMatchFound = true;
                }
            }
            else
            {
                if (count >= 3)
                {
                    countMap[count]++;
                }
                count = 1;
            }
        }
        if (count >= 3)
        {
            countMap[count]++;
        }
    }

    return validMatchFound;
}

bool MatchFinder::removeMatches(std::vector<std::vector<Candy>> &candies, Score &score)
{
    if (!checkForMatches(candies))
    {
        return false;
    }
    else
    {
        for (auto candy : candiesToRemove)
        {
            candy->setMatched(true);
        }
        candiesToRemove.clear();
        for (auto &pair : countMap)
        {
            for (int i = 0; i < pair.second; i++)
            {
                score.addScore(pair.first);
            }
        }
        countMap.clear();
    }
    return true;
}

bool MatchFinder::checkForPossibleMatches(std::vector<std::vector<Candy>> &candies)
{
    int rows = candies.size();
    int cols = candies[0].size();
    bool possibleMatchFound = false;

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (j < cols - 1)
            {
                std::vector<std::vector<Candy>> tempCandies = candies;
                if (candies[i][j].getType() != 0 && candies[i][j + 1].getType() != 0)
                {
                    std::swap(tempCandies[i][j], tempCandies[i][j + 1]);
                    if (hasMatch(tempCandies))
                    {
                        possibleMatchFound = true;
                        break;
                    }
                }
            }
            if (i < rows - 1)
            {
                std::vector<std::vector<Candy>> tempCandies = candies;
                if (candies[i][j].getType() != 0 && candies[i + 1][j].getType() != 0)
                {
                    std::swap(tempCandies[i][j], tempCandies[i + 1][j]);
                    if (hasMatch(tempCandies))
                    {
                        possibleMatchFound = true;
                        break;
                    }
                }
            }
        }
        if (possibleMatchFound)
        {
            break;
        }
    }

    return possibleMatchFound;
}

bool MatchFinder::hasMatch(std::vector<std::vector<Candy>> &candies)
{
    int rows = candies.size();
    int cols = candies[0].size();
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols - 2; ++j)
        {
            if (candies[i][j].getType() != 0 && candies[i][j].getType() == candies[i][j + 1].getType() && candies[i][j].getType() == candies[i][j + 2].getType())
            {
                return true;
            }
        }
    }
    for (int j = 0; j < cols; ++j)
    {
        for (int i = 0; i < rows - 2; ++i)
        {
            if (candies[i][j].getType() != 0 && candies[i][j].getType() == candies[i + 1][j].getType() && candies[i][j].getType() == candies[i + 2][j].getType())
            {
                return true;
            }
        }
    }
    return false; // No matches found
}