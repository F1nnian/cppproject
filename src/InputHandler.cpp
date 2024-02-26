#include "InputHandler.h"
#include <iostream>

int selectedRow = -1;
int selectedCol = -1;

InputHandler::InputHandler(GameBoard& gameboard, int width, int height, int tileSize, int menuHeight, int ROWS, int COLS) :
    gameBoard(gameboard),
    width(width),
    height(height),
    tileSize(tileSize),
    menuHeight(menuHeight),
    ROWS(ROWS),
    COLS(COLS)
{

}

void InputHandler::handleMouseInput(int mouseX, int mouseY) {
    int row = (mouseY - menuHeight) / tileSize;
    int col = mouseX / tileSize;

    if(selectedRow == -1 && selectedCol == -1) {
        gameBoard.selectCandy(row, col);
        selectedRow = row;
        selectedCol = col;
    } else {
        gameBoard.deselectCandy(selectedRow, selectedCol);
        if(abs(row - selectedRow) + abs(col - selectedCol) == 1) {
            gameBoard.swapCandies(row, col, selectedRow, selectedCol);
            reset();
        }else {
            gameBoard.selectCandy(row, col);
            selectedRow = row;
            selectedCol = col;
        }
    }

}

void InputHandler::reset() {
    selectedRow = -1;
    selectedCol = -1;
}