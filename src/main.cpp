#include "GameBoard.h"

const int screenWidth = 400;
const int screenHeight = 850;

GameBoard gameBoard(screenWidth, screenHeight);
InputHandler inputHandler = gameBoard.getInputHandler();

int main() {
    InitWindow(screenWidth, screenHeight, "Candy Crush");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        gameBoard.update();
        gameBoard.draw();

        EndDrawing();

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            int mouseX = GetMouseX();
            int mouseY = GetMouseY();
            inputHandler.handleMouseInput(mouseX, mouseY);
        }

    }

    CloseWindow();

    return 0;
}
