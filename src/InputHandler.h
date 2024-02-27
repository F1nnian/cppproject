#pragma once
#include "GameBoard.h"
#include "CandyRemover.h"

class InputHandler 
{
public:
    InputHandler(GameBoard& gameBoard, int width, int height, int tileSize, int menuHeight, int ROWS, int COLS);
    void handleMouseInput(int mouseX, int mouseY);
    int getSelectedRow();
    int getSelectedCol();
    void reset();
private:
    GameBoard& gameBoard;
    int width;
    int height;
    int tileSize;
    int menuHeight;
    int ROWS;
    int COLS;
};
