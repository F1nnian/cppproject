#include "InputHandler.h"

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

bool InputHandler::playAgainInput()
{
    for (int key = 0; key < KEY_KB_MENU; key++) {
            if (IsKeyDown(key)) {
                return true;
            }
        }
    return false;
}