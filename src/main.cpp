#include "GameBoard.h"
#include "CandyRemover.h"
#include "InputHandler.h"
#include "CandyCreator.h"

const int screenWidth = 400;
const int screenHeight = 850;


int main() {
    InitWindow(screenWidth, screenHeight, "Candy Crush");
    SetTargetFPS(60);

    GameBoard gameBoard(screenWidth, screenHeight);
    InputHandler inputHandler(gameBoard, screenWidth, screenHeight, gameBoard.getTileSize(), gameBoard.getMenuHeight(), gameBoard.getRows(), gameBoard.getCols());
    CandyRemover candyRemover(gameBoard);
    CandyCreator candyCreator(gameBoard);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        
        gameBoard.draw();

        EndDrawing();

        if(candyRemover.checkForMatches());
        {
            candyRemover.removeMatches();
            candyCreator.refillBoard();
        }

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
