#include "Game.h"

Game::Game(InputHandler& inputHandler, Renderer& renderer, AudioRenderer& audioRenderer) : inputHandler(inputHandler), renderer(renderer), audioRenderer(audioRenderer), gameBoard(ROWS, COLS), score(Score()), matchFinder(MatchFinder()), candyCreator(gameBoard, REFILL_CANDIES)
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
        if(inputHandler.playAgainInput())
        {
            reset();
            break;
        }
    }
}

void Game::reset()
{
    gameBoard.reset();
    score.reset();
    candyCreator.reset();
    run();
}