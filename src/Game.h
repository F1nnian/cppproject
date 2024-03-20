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
    Game(InputHandler& inputHandler, Renderer& renderer);
    void start();
    void run();
private:
    InputHandler& inputHandler;
    Renderer& renderer;
    MatchFinder matchFinder;
    CandyCreator candyCreator;
    GameBoard gameBoard;
    Score score;
    AudioRenderer audioRenderer;
    void gameOver();
};