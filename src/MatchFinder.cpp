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

    //  // Map to store candy types and their counts

    // int rows = candies.size();
    // int cols = candies[0].size();
    // // Count horizontal pairs and mark for removal
    // for (int i = 0; i < rows; ++i) 
    // {
    //     int count = 1; // Initialize count for each row
    //     for (int j = 1; j < cols; ++j) 
    //     {
    //         if (candies[i][j].getType() == candies[i][j - 1].getType() && candies[i][j].getType() != 0) 
    //         {
    //             ++count;
    //             if (count >= 3) {
    //                 candiesToRemove.insert(&candies[i][j-2]);
    //                 candiesToRemove.insert(&candies[i][j-1]);
    //                 candiesToRemove.insert(&candies[i][j]);
    //             }
    //         } 
    //         else 
    //         {
    //             if(count >= 3) 
    //             {
    //                 countMap[count]++;
    //             }
    //             count = 1; // Reset count for the next series of candies
    //         }
    //     }
    // }

    // // Count vertical pairs and mark for removal
    // for (int j = 0; j < cols; ++j) 
    // {
    //     int count = 1; // Initialize count for each column
    //     for (int i = 1; i < rows; ++i) 
    //     {
    //         if (candies[i][j].getType() == candies[i - 1][j].getType() && candies[i][j].getType() != 0) 
    //         {
    //             ++count;
    //             if (count >= 3) {
    //                 candiesToRemove.insert(&candies[i-1][j]);
    //                 candiesToRemove.insert(&candies[i-2][j]);
    //                 candiesToRemove.insert(&candies[i][j]);
    //             }
    //         } 
    //         else 
    //         {
    //             if(count >= 3) 
    //             {
    //                 countMap[count]++;
    //             }
    //             count = 1; // Reset count for the next series of candies
    //         }
    //     }
    // }

    // // Output the count of pairs for each length
    // if(!countMap.empty())
    // {

    // std::cout << countMap.size() << " unique pairs of candies found" << std::endl;
    // }
    // for (auto& pair : countMap) {
    //     std::cout << "Pairs of " << pair.first << " candies: " << pair.second << std::endl;
    // }
    // return !candiesToRemove.empty();
// }

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