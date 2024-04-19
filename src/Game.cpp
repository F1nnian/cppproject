// This class is responsible for the game logic. It contains the game board, score, match finder, and candy creator. It also contains methods to start the game, run the game loop, handle game over, and reset the game.

#include "Game.h"

Game::Game(InputHandler &inputHandler, Renderer &renderer, AudioRenderer &audioRenderer) : inputHandler(inputHandler), renderer(renderer), audioRenderer(audioRenderer), gameBoard(ROWS, COLS), score(Score()), matchFinder(MatchFinder()), candyCreator(gameBoard, REFILL_CANDIES)
{
}

void Game::start()
{
    renderer.init();            // Initialize renderer
    audioRenderer.loadSounds(); // Load audio files
    audioRenderer.startMusic(); // Start background music
    run();                      // Start game loop
}

// Run the game loop
void Game::run()
{
    while (!WindowShouldClose())
    {
        audioRenderer.updateMusic();
        if (!matchFinder.checkForPossibleMatches(gameBoard.getCandies())) // Check for possible matches
        {
            gameOver(); // Game over if no possible matches
            break;
        }
        else
        {
            renderer.renderGame(gameBoard.getCandies(), candyCreator.getCandyMap(), score.getScore());
        }
        if (inputHandler.selectCandyInput()) // Player clicks on candy
        {
            if (gameBoard.selectCandy(renderer.getScreenWidth(), renderer.getScreenHeight(), renderer.getMenuHeight(), renderer.getTileSize(gameBoard.getRows(), gameBoard.getCols())))
            {
                audioRenderer.playSelect(); // Play select sound
            }
        }
        if (matchFinder.removeMatches(gameBoard.getCandies(), score)) // Remove matches and update score
        {
            audioRenderer.playMatch();
            candyCreator.refillBoard();
        }
    }
}

// Handle game over
void Game::gameOver()
{
    audioRenderer.playGameOver();
    while (!WindowShouldClose())
    {
        renderer.renderGameOver(score.getScore());
        if (inputHandler.playAgainInput()) // Player presses any key on the keyboard
        {
            reset(); // Reset the game
            break;
        }
    }
}

// Reset the game
void Game::reset()
{
    gameBoard.reset();
    score.reset();
    candyCreator.reset();
    run();
}