#include "CandyCreator.h"
#include <iostream>

CandyCreator::CandyCreator(GameBoard& gameBoard, int refillCandies) : gameBoard(gameBoard), refillCandies(refillCandies)
{
    for (int i = 0; i < refillCandies; ++i) 
    {
        int randomType = std::rand() % NUM_TYPES;
        candyMap[randomType]++;
    }
}

bool CandyCreator::areCandiesLeft()
{
    for (int i = 0; i < NUM_TYPES; ++i) 
    {
        if(candyMap[i] > 0) return true;
    }
    return false;
}

std::map<int, int> CandyCreator::getCandyMap()
{
    return candyMap;
}

void CandyCreator::refillBoard()
{
    dropCandies();
    while (!gameBoard.isFull())
    {
        for (int j = 0; j < gameBoard.getCols(); ++j) {
            if(gameBoard.getCandy(0, j).getType() == 0)
            {   
                if(!areCandiesLeft()) return;
                createCandy(j);
            }
        }
    }
    std::cout << candyMap[0] << " " << candyMap[1] << " " << candyMap[2] << " " << candyMap[3] << " " << candyMap[4] << " " << candyMap[5] << std::endl;
}

void CandyCreator::dropCandies()
{
    std::cout << "Dropping candies" << std::endl;
    bool swapped = true;
    while(swapped)
    {
        swapped = false;
        for (int i = gameBoard.getRows()-1; i > 0; --i) {
            for (int j = 0; j < gameBoard.getCols(); ++j) {
                if (gameBoard.getCandy(i, j).getType() == 0) {
                    if(gameBoard.getCandy(i-1, j).getType() != 0) {
                        gameBoard.swapCandies(i, j, i-1, j);
                        swapped = true;
                    }
                }
            }
        }
    }
}

void CandyCreator::createCandy(int col)
{
    if(gameBoard.getCandy(0, col).getType() != 0) return;
    int randomType = std::rand() % NUM_TYPES;
    if(candyMap[0] == 0 && candyMap[1] == 0 && candyMap[2] == 0 && candyMap[3] == 0 && candyMap[4] == 0 && candyMap[5] == 0) 
    {
        randomType = -1;
    }
    while(candyMap[randomType] == 0)
    {
        randomType = std::rand() % NUM_TYPES;
    }
    gameBoard.addCandy(0, col, randomType+1);
    candyMap[randomType]--;
    dropCandies();
}