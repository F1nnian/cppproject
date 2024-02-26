#pragma once
#include "Gameboard.h"

class CandyCreator
{
public:
    CandyCreator(GameBoard& gameboard);
    void refillBoard();
    void dropCandies();

private:
    GameBoard& gameBoard;
};
