#include "Game.h"

Game::Game(InputHandler inputHandler, Renderer renderer)
{
    inputHandler = inputHandler;
    renderer = renderer;
}

Game::start()
{
    Renderer.init();
}