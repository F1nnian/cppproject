#pragma once
#include "Renderer.h"
#include "InputHandler.h"

class Game
{   
private:
    InputHandler inputHandler;
    Renderer renderer;

public:
    Game(InputHandler inputHandler, Renderer renderer);
    ~Game();
    void run();
};