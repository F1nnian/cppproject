#include "Game.h"
#include "GameBoard.h"
#include "MatchFinder.h"
#include "InputHandler.h"
#include "CandyCreator.h"

const int screenWidth = 400;
const int screenHeight = 850;


int main() {

    Renderer renderer(screenWidth, screenHeight);
    InputHandler inputHandler();
    Game game(inputHandler, renderer);

    InitWindow(screenWidth, screenHeight, "Candy Crush");
    SetTargetFPS(60);

    GameBoard gameBoard(screenWidth, screenHeight);
    MatchFinder matchFinder(gameBoard);
    CandyCreator candyCreator(gameBoard);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        
        gameBoard.draw();

        EndDrawing();

        if(matchFinder.checkForMatches());
        {
            matchFinder.removeMatches();
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
