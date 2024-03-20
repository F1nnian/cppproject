#pragma once
#include "Renderer.h"
#include "InputHandler.h"
#include "MatchFinder.h"
#include "CandyCreator.h"
#include "GameBoard.h"
#include "Score.h"
#include "AudioRenderer.h"

class Game
{   
public:
    Game(InputHandler& inputHandler, Renderer& renderer, AudioRenderer& audioRenderer);
    void start();
    void run();
private:
    const int ROWS = 16;
    const int COLS = 8;
    const int REFILL_CANDIES = 100;
    InputHandler& inputHandler;
    Renderer& renderer;
    MatchFinder matchFinder;
    CandyCreator candyCreator;
    GameBoard gameBoard;
    Score score;
    AudioRenderer& audioRenderer;
    void gameOver();
    void reset();
};