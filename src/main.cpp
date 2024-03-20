#include "Game.h"
#include "GameBoard.h"
#include "InputHandler.h"
#include "Renderer.h"

const int screenWidth = 400;
const int screenHeight = 850;


int main() {
    Renderer renderer(screenWidth, screenHeight);
    AudioRenderer audioRenderer;
    InputHandler inputHandler;
    Game game(inputHandler, renderer, audioRenderer);

    game.start();

    return 0;
}
