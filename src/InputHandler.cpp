#include "InputHandler.h"
#include <iostream>

int selectedRow = -1;
int selectedCol = -1;

InputHandler::InputHandler(int width, int height, int tileSize, int menuHeight, int ROWS, int COLS) 
{
    this->width = width;
    this->height = height;
    this->tileSize = tileSize;
    this->menuHeight = menuHeight;
    this->ROWS = ROWS;
    this->COLS = COLS;
    // this->gameBoardPtr = gameBoardPtr;
}

int InputHandler::getSelectedRow() {
    return selectedRow;
}

int InputHandler::getSelectedCol() {
    return selectedCol;
}

void InputHandler::handleMouseInput(int mouseX, int mouseY) {
    // Convert mouse coordinates to grid indices
    std::cout << "MouseX: " << mouseX << " MouseY: " << mouseY << std::endl;
    int row = (mouseY - menuHeight) / tileSize;
    int col = mouseX / tileSize;

    selectedRow = row;
    selectedCol = col;
}

void InputHandler::reset() {
    selectedRow = -1;
    selectedCol = -1;
}