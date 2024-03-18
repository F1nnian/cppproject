#include "Renderer.h"
#include <iostream>

Renderer::Renderer(int screenWidth, int screenHeight)
{
    this->screenWidth = screenWidth;
    this->screenHeight = screenHeight;
}

int Renderer::getTileSize()
{
    return std::min(screenWidth/8, (screenHeight-50)/16);
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

void Renderer::renderGame(std::vector<std::vector<Candy>> candies, std::map<int,int> candyMap)
{
    BeginDrawing();
    drawGameBoard(candies);
    drawMenu(candyMap);
    EndDrawing();
}

void Renderer::drawGameBoard(std::vector<std::vector<Candy>> candies){
    ClearBackground(RAYWHITE);
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

void Renderer::drawMenu(std::map<int,int> candyMap)
{
    for(int i = 0; i < candyMap.size(); i++)
    {
        DrawRectangle(i*50, 10, menuHeight/2, menuHeight/2, getColor(i+1));
        DrawText(std::to_string(candyMap[i]).c_str(), i*50+3, 10, 25, LIGHTGRAY);
    }
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