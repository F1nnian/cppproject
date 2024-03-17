#include "InputHandler.h"
#include <iostream>
#include <raylib.h>

int selectedRow = -1;
int selectedCol = -1;

bool InputHandler::selectCandyInput()
{
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        return true;
    }
    return false;
}

// void InputHandler::handleMouseInput(int mouseX, int mouseY, gameConfig config) {
//     int row = (mouseY - menuHeight) / tileSize;
//     int col = mouseX / tileSize;
//     if(gameBoard.getCandy(row, col).getType() == 0) {
//         return;
//     }

//     if(selectedRow == -1 && selectedCol == -1) {
//         gameBoard.selectCandy(row, col);
//         selectedRow = row;
//         selectedCol = col;
//     } else {
//         gameBoard.deselectCandy(selectedRow, selectedCol);
//         if(abs(row - selectedRow) + abs(col - selectedCol) == 1) {
//             gameBoard.swapCandies(row, col, selectedRow, selectedCol);
//             MatchFinder matchFinder(gameBoard);
//             if(!matchFinder.checkForMatches())
//             {
//                 gameBoard.swapCandies(row, col, selectedRow, selectedCol);
//             }
//             reset();
//         }else {
//             gameBoard.selectCandy(row, col);
//             selectedRow = row;
//             selectedCol = col;
//         }
//     }
// }

// void InputHandler::reset() {
//     selectedRow = -1;
//     selectedCol = -1;
// }