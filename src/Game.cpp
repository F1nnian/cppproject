#include "Game.h"
#include <iostream>

Game::Game(InputHandler& inputHandler, Renderer& renderer) : inputHandler(inputHandler), renderer(renderer), gameBoard(16, 8), matchFinder(MatchFinder()), candyCreator(gameBoard)
{
}

void Game::start()
{
    renderer.init();
    run();
}

void Game::run()
{
    while (!WindowShouldClose())
    {
        // std::cout << "Game running" << std::endl;
        renderer.renderGame(gameBoard.getCandies());
        if(matchFinder.checkForMatches(gameBoard.getCandies()))
        {
            matchFinder.removeMatches();
            candyCreator.refillBoard();
        }
    }
}