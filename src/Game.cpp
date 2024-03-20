#include "Game.h"

Game::Game(InputHandler& inputHandler, Renderer& renderer) : inputHandler(inputHandler), renderer(renderer), gameBoard(16, 8), score(Score()), matchFinder(MatchFinder()), candyCreator(gameBoard,100), audioRenderer(AudioRenderer())
{
}

void Game::start()
{
    renderer.init();
    audioRenderer.loadSounds();
    audioRenderer.startMusic();
    run();
}

void Game::run()
{
    while (!WindowShouldClose())
    {
        audioRenderer.updateMusic();
        if(!matchFinder.checkForPossibleMatches(gameBoard.getCandies()))
        {
            gameOver();
            break;
        }
        else
        {
            renderer.renderGame(gameBoard.getCandies(), candyCreator.getCandyMap(), score.getScore());
        }
        if(inputHandler.selectCandyInput())
        {
            if(gameBoard.selectCandy(renderer.getScreenWidth(), renderer.getScreenHeight(), renderer.getMenuHeight(), renderer.getTileSize(gameBoard.getRows(), gameBoard.getCols())))
            {
                audioRenderer.playSelect();
            }
        }
        if(matchFinder.removeMatches(gameBoard.getCandies(), score))
        {
            audioRenderer.playMatch();
            candyCreator.refillBoard();
        }
    }
}

void Game::gameOver()
{
    audioRenderer.playGameOver();
    while (!WindowShouldClose())
    {
        renderer.renderGameOver(score.getScore());
    }
}