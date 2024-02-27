#pragma once
#include "Gameboard.h"

class CandyCreator
{
public:
    CandyCreator(GameBoard& gameboard);
    void refillBoard();
    void dropCandies();
    void createCandy(int col);
private:
    GameBoard& gameBoard;
};
