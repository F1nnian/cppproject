#include "MatchFinder.h"
#include <iostream>

bool MatchFinder::checkForMatches(std::vector<std::vector<Candy>>& candies)
{
    int rows = candies.size();
    int cols = candies[0].size();

    bool validMatchFound = false; // Flag to track if a valid match is found

    // Count horizontal pairs and mark for removal
    for (int i = 0; i < rows; ++i) {
        int count = 1; // Initialize count for each row
        for (int j = 1; j < cols; ++j) {
            if (candies[i][j].getType() == candies[i][j - 1].getType() && candies[i][j].getType() != 0) {
                ++count;
                if (count >= 3) {
                    // Only add to candiesToRemove when a valid match is found
                    if (count == 3) {
                        candiesToRemove.insert({&candies[i][j - 2], &candies[i][j - 1]});
                    }
                    candiesToRemove.insert({&candies[i][j], &candies[i][j - 1]});
                    validMatchFound = true;
                }
            } else {
                if (count >= 3) {
                    countMap[count]++;
                }
                count = 1; // Reset count for the next series of candies
            }
        }
        if (count >= 3) {
            countMap[count]++; // Increment count for the last candy type in this row
        }
    }

    // Count vertical pairs and mark for removal
    for (int j = 0; j < cols; ++j) {
        int count = 1; // Initialize count for each column
        for (int i = 1; i < rows; ++i) {
            if (candies[i][j].getType() == candies[i - 1][j].getType() && candies[i][j].getType() != 0) {
                ++count;
                if (count >= 3) {
                    // Only add to candiesToRemove when a valid match is found
                    if (count == 3) {
                        candiesToRemove.insert({&candies[i - 2][j], &candies[i - 1][j]});
                    }
                    candiesToRemove.insert({&candies[i][j], &candies[i - 1][j]});
                    validMatchFound = true;
                }
            } else {
                if (count >= 3) {
                    countMap[count]++;
                }
                count = 1; // Reset count for the next series of candies
            }
        }
        if (count >= 3) {
            countMap[count]++; // Increment count for the last candy type in this column
        }
    }

    return validMatchFound; // Return true if at least one valid match is found
}

bool MatchFinder::removeMatches(std::vector<std::vector<Candy>>& candies, Score& score)
{
    if(!checkForMatches(candies)) 
    {
        return false;
    }
    else
    {
        for(auto candy : candiesToRemove) {
            candy->setMatched(true);
        }
        candiesToRemove.clear();
        for (auto& pair : countMap) {
            std::cout << "Removing " << pair.second << " pairs of " << pair.first << " candies" << std::endl;
            for(int i = 0; i < pair.second; i++)
            {
                score.addScore(pair.first);
            }
        }
        countMap.clear();
    }
    return true;
}

bool MatchFinder::checkForPossibleMatches(std::vector<std::vector<Candy>>& candies) {
    int rows = candies.size();
    int cols = candies[0].size();
    bool possibleMatchFound = false;

    // Iterate through each cell on the board
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            // Check swapping with the right neighbor
            if (j < cols - 1) {
                std::vector<std::vector<Candy>> tempCandies = candies;
                std::swap(tempCandies[i][j], tempCandies[i][j + 1]);
                if (hasMatch(tempCandies)) {
                    possibleMatchFound = true;
                    break;
                }
            }
            // Check swapping with the bottom neighbor
            if (i < rows - 1) {
                std::vector<std::vector<Candy>> tempCandies = candies;
                std::swap(tempCandies[i][j], tempCandies[i + 1][j]);
                if (hasMatch(tempCandies)) {
                    possibleMatchFound = true;
                    break;
                }
            }
        }
        if (possibleMatchFound) {
            break;
        }
    }

    return possibleMatchFound;
}

bool MatchFinder::hasMatch(std::vector<std::vector<Candy>>& candies) {
    int rows = candies.size();
    int cols = candies[0].size();

    // Check horizontal matches
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols - 2; ++j) {
            if (candies[i][j].getType() != 0 && candies[i][j].getType() == candies[i][j + 1].getType() && candies[i][j].getType() == candies[i][j + 2].getType()) {
                return true; // Horizontal match found
            }
        }
    }

    // Check vertical matches
    for (int j = 0; j < cols; ++j) {
        for (int i = 0; i < rows - 2; ++i) {
            if (candies[i][j].getType() != 0 && candies[i][j].getType() == candies[i + 1][j].getType() && candies[i][j].getType() == candies[i + 2][j].getType()) {
                return true; // Vertical match found
            }
        }
    }

    return false; // No matches found
}