#include "Renderer.h"

Renderer::Renderer(int screenWidth, int screenHeight)
{
    this->screenWidth = screenWidth;
    this->screenHeight = screenHeight;
}

int Renderer::getTileSize(int rows, int cols)
{
    return std::min(screenWidth/cols, (screenHeight-menuHeight)/rows);
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
    InitWindow(screenWidth, screenHeight, "Candy Crush");
    SetTargetFPS(60);
    BeginDrawing();
    ClearBackground(RAYWHITE);
    EndDrawing();
    loadTextures();
}

void Renderer::loadTextures()
{
    for(int i = 1; i <= 6; i++)
    {
        std::string path = "../resources/img/" + std::to_string(i) + ".png";
        textureMap[i] = LoadTexture(path.c_str());
    }
}


void Renderer::renderGame(std::vector<std::vector<Candy>> candies, std::map<int,int> candyMap, int score)
{
    BeginDrawing();
    drawGameBoard(candies);
    drawMenu(candyMap, score);
    EndDrawing();
}

void Renderer::drawGameBoard(std::vector<std::vector<Candy>> candies){
    ClearBackground(BLACK);
    int rows = candies.size();
    int cols = candies[0].size();
    int tileSize = std::min(screenWidth/cols, (screenHeight-menuHeight)/rows);
    DrawRectangle(0, menuHeight, screenWidth, screenHeight-menuHeight, DARKBROWN);
    for(std::vector<Candy> row : candies)
    {
        for(Candy candy : row)
        {
            Rectangle rect = {candy.getCol()*tileSize, candy.getRow()*tileSize+menuHeight, tileSize-3, tileSize-3};
            DrawRectangleRec(rect, BROWN);
            drawCandy(candy.getRow(), candy.getCol(), candy.getType(), candy.isSelected(), tileSize, menuHeight);

        }
    }
}

void Renderer::drawMenu(std::map<int,int> candyMap, int score)
{
    for(int i = 0; i < candyMap.size(); i++)
    {
        drawCandy(0, i, i+1, false, menuHeight, 0);
        DrawText(std::to_string(candyMap[i]).c_str(), i*50+17.5, 10, menuHeight/2, BLACK);
    }
    DrawText(std::to_string(score).c_str(), screenWidth-75, 10, menuHeight/2, LIGHTGRAY);
}

Color Renderer::getColor(int number)
{
    return colorMap.find(number)->second;
}

void Renderer::drawCandy(float row, int col, int type, bool isSelected, int tileSize, int menuHeight) {
    float candyX = col * tileSize;
    float candyY = row * tileSize + menuHeight;

    Rectangle sourceRect = { 0.0f, 0.0f, (float)textureMap[type].width, (float)textureMap[type].height };
    
    Rectangle destRect = { candyX, candyY, (float)tileSize, (float)tileSize };

    DrawTexturePro(textureMap[type], sourceRect, destRect, Vector2{0, 0}, 0.0f, WHITE);

    if (isSelected) {
        DrawRectangleLinesEx(destRect, 2, LIGHTGRAY);
    }
}


void Renderer::renderGameOver(int score)
{
    BeginDrawing();
    ClearBackground(BLACK);
    drawCenteredText("Game Over", 40, screenHeight/2-150, LIGHTGRAY);
    drawCenteredText(("Score: " + std::to_string(score)).c_str(), 40, screenHeight/2-100, LIGHTGRAY);
    drawCenteredText("Press any key", 40, screenHeight/2+100, LIGHTGRAY);
    drawCenteredText("to restart", 40, screenHeight/2+150, LIGHTGRAY);
    EndDrawing();
}

void Renderer::drawCenteredText(const char* text, int fontSize, int posY, Color color)
{
    int textWidth = MeasureText(text, fontSize);
    DrawText(text, screenWidth/2 - textWidth/2, posY, fontSize, color);
}