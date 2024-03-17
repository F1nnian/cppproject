#include "Game.h"
#include "GameBoard.h"
#include "MatchFinder.h"
#include "InputHandler.h"
#include "CandyCreator.h"
#include "Renderer.h"
#include <iostream>
#include <limits>

const int screenWidth = 400;
const int screenHeight = 850;


int main() {
    Renderer renderer(screenWidth, screenHeight);
    InputHandler inputHandler;
    Game game(inputHandler, renderer);

    game.start();

    return 0;
}
