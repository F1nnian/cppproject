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