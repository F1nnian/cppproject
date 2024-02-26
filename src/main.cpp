#include "GameBoard.h"
#include "CandyRemover.h"
#include "InputHandler.h"

const int screenWidth = 400;
const int screenHeight = 850;


int main() {
    InitWindow(screenWidth, screenHeight, "Candy Crush");
    SetTargetFPS(60);

    GameBoard gameBoard(screenWidth, screenHeight);
    InputHandler inputHandler(gameBoard, screenWidth, screenHeight, gameBoard.getTileSize(), gameBoard.getMenuHeight(), gameBoard.getRows(), gameBoard.getCols());
    CandyRemover candyRemover(gameBoard);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        candyRemover.checkForMatches();
        // gameBoard.update();
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
