#pragma once
#include "Gameboard.h"
#include "Candy.h"
#include <map>


class CandyCreator
{
public:
    CandyCreator(GameBoard& gameboard, int candiesLeft);
    void refillBoard();
    void dropCandies();
    void createCandy(int col);
    bool areCandiesLeft();
    std::map<int, int> getCandyMap();
    void reset();
private:
    GameBoard& gameBoard;
    int refillCandies;
    std::map<int, int> candyMap;
    const int NUM_TYPES = Candy::getNumTypes();
    void createCandyMap();
};
