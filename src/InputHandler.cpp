// This class is responsible for handling user input in the game. It contains methods to select candies and play again.

#include "InputHandler.h"

int selectedRow = -1;
int selectedCol = -1;

// Check if the user clicked left mouse button to select a candy
bool InputHandler::selectCandyInput()
{
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        return true;
    }
    return false;
}

// Check if user clicked any key on the keyboard to play again
bool InputHandler::playAgainInput()
{
    for (int key = 0; key < KEY_KB_MENU; key++)
    {
        if (IsKeyDown(key))
        {
            return true;
        }
    }
    return false;
}