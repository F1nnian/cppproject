#include "Renderer.h"
#include <iostream>

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
    for(std::vector<Candy> row : candies)
    {
        for(Candy candy : row)
        {
            drawCandy(candy.getRow(), candy.getCol(), candy.getType(), candy.isSelected(), tileSize, menuHeight);
        }
    }
}

void Renderer::drawMenu(std::map<int,int> candyMap, int score)
{
    for(int i = 0; i < candyMap.size(); i++)
    {
        DrawRectangle(i*50, 10, menuHeight/2, menuHeight/2, getColor(i+1));
        DrawText(std::to_string(candyMap[i]).c_str(), i*50+3, 10, menuHeight/2, LIGHTGRAY);
    }
    DrawText(std::to_string(score).c_str(), screenWidth-75, 10, menuHeight/2, LIGHTGRAY);
}

Color Renderer::getColor(int number)
{
    return colorMap.find(number)->second;
}

void Renderer::drawCandy(int row, int col, int type, bool isSelected, int tileSize, int menuHeight)
{
    Rectangle rect = {col*tileSize, row*tileSize+menuHeight, tileSize, tileSize};
    DrawRectangleRec(rect, getColor(type));
    if(isSelected) {
        DrawRectangleLinesEx(rect, 2, WHITE);
    }
}

void Renderer::renderGameOver(int score)
{
    BeginDrawing();
    ClearBackground(BLACK);
    DrawText("Game Over", screenWidth/2 - 100, screenHeight/2 - 50, 40, LIGHTGRAY);
    DrawText(("Score: " + std::to_string(score)).c_str(), screenWidth/2 - 100, screenHeight/2, 40, LIGHTGRAY);
    EndDrawing();
}