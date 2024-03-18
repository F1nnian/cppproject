#include "Game.h"
#include <iostream>

Game::Game(InputHandler& inputHandler, Renderer& renderer) : inputHandler(inputHandler), renderer(renderer), gameBoard(16, 8), matchFinder(MatchFinder()), candyCreator(gameBoard,100)
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
        renderer.renderGame(gameBoard.getCandies(), candyCreator.getCandyMap());
        if(inputHandler.selectCandyInput())
        {
            gameBoard.selectCandy(renderer.getScreenWidth(), renderer.getScreenHeight(), renderer.getMenuHeight(), renderer.getTileSize());
        }
        if(matchFinder.checkForMatches(gameBoard.getCandies()))
        {
            matchFinder.removeMatches();
            candyCreator.refillBoard();
        }
    }
}