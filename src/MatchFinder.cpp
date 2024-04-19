// This class implements the match finder. It contains methods to check for matches, remove matches, and check for possible matches in the game board.

#include "MatchFinder.h"

// Check for matches in the game board and store the matched candies in candiesToRemove while also storing the amount of matches of each length (3,4,5...) in countMap
bool MatchFinder::checkForMatches(std::vector<std::vector<Candy>> &candies)
{
    int rows = candies.size();
    int cols = candies[0].size();

    bool validMatchFound = false; // Flag to check if a match was found

    // Check for horizontal matches
    for (int i = 0; i < rows; ++i)
    {
        int count = 1;
        // Iterate through each column and increment the count if the current candy type is the same as the previous candy type
        for (int j = 1; j < cols; ++j)
        {
            if (candies[i][j].getType() == candies[i][j - 1].getType() && candies[i][j].getType() != 0) // If the current candy type is the same as the previous candy type and not empty
            {
                ++count;
                if (count >= 3) // If the amount of consecutive candies of the same type is greater than or equal to 3
                {
                    if (count == 3) // If the count is 3, add the previous two candies to the candiesToRemove set
                    {
                        candiesToRemove.insert({&candies[i][j - 2], &candies[i][j - 1]});
                    }
                    candiesToRemove.insert({&candies[i][j], &candies[i][j - 1]}); // Add the current candy and the previous candy to the candiesToRemove set
                    validMatchFound = true;
                }
            }
            else // If the current candy type is different from the previous candy type
            {
                if (count >= 3) // If the amount of consecutive candies of the same type is greater than or equal to 3
                {
                    countMap[count]++; // Increment the count of matches of the current length
                }
                count = 1; // Reset the count
            }
        }
        // Check if the last candy in the row is part of a match
        if (count >= 3)
        {
            countMap[count]++;
        }
    }

    // Check for vertical matches by the same logic as horizontal matches
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

// Remove the matched candies from the game board and update the score while returning a boolean indicating if any matches were found
bool MatchFinder::removeMatches(std::vector<std::vector<Candy>> &candies, Score &score)
{
    if (!checkForMatches(candies)) // If no matches were found
    {
        return false;
    }
    else
    {
        for (auto candy : candiesToRemove) // Iterate through the matched candies and set them as matched
        {
            candy->setMatched(true);
        }
        candiesToRemove.clear();    // Clear the matched candies set
        for (auto &pair : countMap) // Iterate through the count map and update the score based on the amount of matches of each length
        {
            for (int i = 0; i < pair.second; i++)
            {
                score.addScore(pair.first);
            }
        }
        countMap.clear(); // Clear the count map
    }
    return true;
}

// Check for possible matches in the game board by swapping adjacent candies and checking if a match can be made
bool MatchFinder::checkForPossibleMatches(std::vector<std::vector<Candy>> &candies)
{
    int rows = candies.size();
    int cols = candies[0].size();
    bool possibleMatchFound = false;

    // Iterate through each candy and swap it with its adjacent candies to check for possible matches
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (j < cols - 1)
            {
                std::vector<std::vector<Candy>> tempCandies = candies;
                if (candies[i][j].getType() != 0 && candies[i][j + 1].getType() != 0) // If the candies are not empty
                {
                    std::swap(tempCandies[i][j], tempCandies[i][j + 1]); // Swap the candies
                    if (hasMatch(tempCandies))                           // If a match can be made by swapping the candies
                    {
                        possibleMatchFound = true;
                        break;
                    }
                }
            }
            if (i < rows - 1)
            {
                std::vector<std::vector<Candy>> tempCandies = candies;
                if (candies[i][j].getType() != 0 && candies[i + 1][j].getType() != 0) // If the candies are not empty
                {
                    std::swap(tempCandies[i][j], tempCandies[i + 1][j]); // Swap the candies
                    if (hasMatch(tempCandies))                           // If a match can be made by swapping the candies
                    {
                        possibleMatchFound = true;
                        break;
                    }
                }
            }
        }
        if (possibleMatchFound) // If a possible match was found, break out of the loop
        {
            break;
        }
    }

    return possibleMatchFound;
}

// Check if a match is present in the passed grid of candies in a simpler way than checkForMatches
bool MatchFinder::hasMatch(std::vector<std::vector<Candy>> &candies)
{
    int rows = candies.size();
    int cols = candies[0].size();
    // Check for pairs of three consecutive candies of the same type in rows and columns
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