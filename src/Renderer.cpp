#include "Renderer.h"

Renderer::Renderer(int screenWidth, int screenHeight) : screenWidth(screenWidth), screenHeight(screenHeight)
{
}

int Renderer::getTileSize(int rows, int cols)
{
    return std::min(screenWidth / cols, (screenHeight - menuHeight) / rows); // Calculate the size of the tiles based on the screen size, number of rows and columns and the height of the menu
}

int Renderer::getMenuHeight()
{
    return menuHeight;
}

int Renderer::getScreenWidth()
{
    return screenWidth;
}

int Renderer::getScreenHeight()
{
    return screenHeight;
}

void Renderer::init()
{
    InitWindow(screenWidth, screenHeight, "Candy Crush"); // Initialize the window with the specified screen width, screen height and title
    SetTargetFPS(60);                                     // Set the target frames per second
    BeginDrawing();
    ClearBackground(RAYWHITE);
    EndDrawing();
    loadTextures(); // Load the textures for the game
}

// Load the textures for the game
void Renderer::loadTextures()
{
    for (int i = 1; i <= 6; i++) // Load the textures for the candies
    {
        std::string path = "../resources/img/" + std::to_string(i) + ".png";
        textureMap[i] = LoadTexture(path.c_str());
    }
}

//  Render the game board, menu and score
void Renderer::renderGame(std::vector<std::vector<Candy>> candies, std::map<int, int> candyMap, int score)
{
    BeginDrawing();
    drawGameBoard(candies);
    drawMenu(candyMap, score);
    EndDrawing();
}

void Renderer::drawGameBoard(std::vector<std::vector<Candy>> candies)
{
    ClearBackground(BLACK); // Draw the background
    int rows = candies.size();
    int cols = candies[0].size();
    int tileSize = std::min(screenWidth / cols, (screenHeight - menuHeight) / rows);
    DrawRectangle(0, menuHeight, screenWidth, screenHeight - menuHeight, DARKBROWN); // Draw the game board background
    for (std::vector<Candy> row : candies)                                           // Draw the candies on the game board
    {
        for (Candy candy : row)
        {
            Rectangle rect = {candy.getCol() * tileSize, candy.getRow() * tileSize + menuHeight, tileSize - 3, tileSize - 3}; // Calculate the rectangle for the tile
            DrawRectangleRec(rect, BROWN);                                                                                    // Draw the tile outline
            drawCandy(candy.getRow(), candy.getCol(), candy.getType(), candy.isSelected(), tileSize, menuHeight);             // Draw the candy
        }
    }
}

void Renderer::drawCandy(float row, int col, int type, bool isSelected, int tileSize, int menuHeight)
{
    // Calculate the position of the candy
    float candyX = col * tileSize;
    float candyY = row * tileSize + menuHeight;

    Rectangle sourceRect = {0.0f, 0.0f, (float)textureMap[type].width, (float)textureMap[type].height}; // Calculate the source rectangle for the candy texture for resizing
    Rectangle destRect = {candyX, candyY, (float)tileSize, (float)tileSize};                            // Calculate the destination rectangle for the candy texture
    DrawTexturePro(textureMap[type], sourceRect, destRect, Vector2{0, 0}, 0.0f, WHITE);                 // Draw the candy texture

    if (isSelected) // If the candy is selected, draw a border around it
    {
        DrawRectangleLinesEx(destRect, 2, LIGHTGRAY);
    }
}

void Renderer::drawMenu(std::map<int, int> candyMap, int score)
{
    for (int i = 0; i < candyMap.size(); i++)
    {
        drawCandy(0, i, i + 1, false, menuHeight, 0);                                                                         // Draw the candy in the menu
        const char *text = std::to_string(candyMap[i]).c_str();                                                               // Create a string from the number of candies of the current type
        int textWidth = MeasureText(text, menuHeight / 2);                                                                    // Calculate the width of the text so it can be centered inside the candy
        DrawText(text, (i * 2 + 1) * menuHeight / 2 - textWidth / 2, menuHeight / 2 - menuHeight / 4, menuHeight / 2, BLACK); // Draw the text
    }
    const char *scoreText = std::to_string(score).c_str();                                                        // Create a string from the score
    int textWidth = MeasureText(scoreText, menuHeight / 2);                                                       // Calculate the width of the text so it can be centered in the leftover space
    DrawText(scoreText, screenWidth - textWidth - 5, menuHeight / 2 - menuHeight / 4, menuHeight / 2, LIGHTGRAY); // Draw the score
}

Color Renderer::getColor(int number)
{
    return colorMap.find(number)->second;
}

void Renderer::renderGameOver(int score)
{
    BeginDrawing();
    ClearBackground(BLACK);
    drawCenteredText("Game Over", 40, screenHeight / 2 - 150, LIGHTGRAY);                                 // Draw the game over text
    drawCenteredText(("Score: " + std::to_string(score)).c_str(), 40, screenHeight / 2 - 100, LIGHTGRAY); // Draw the score
    drawCenteredText("Press any key", 40, screenHeight / 2 + 100, LIGHTGRAY);                             // Draw the restart text
    drawCenteredText("to restart", 40, screenHeight / 2 + 150, LIGHTGRAY);                                // Draw the restart text
    EndDrawing();
}

// Draw centered text on the screen
void Renderer::drawCenteredText(const char *text, int fontSize, int posY, Color color)
{
    int textWidth = MeasureText(text, fontSize);
    DrawText(text, screenWidth / 2 - textWidth / 2, posY, fontSize, color);
}