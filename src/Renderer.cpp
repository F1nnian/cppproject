#include "Renderer.h"
#include <iostream>

Renderer::Renderer(int screenWidth, int screenHeight)
{
    this->screenWidth = screenWidth;
    this->screenHeight = screenHeight;
}

void Renderer::init()
{
    InitWindow(screenWidth, screenHeight, "Candy Crush");
    SetTargetFPS(60);
    BeginDrawing();
    ClearBackground(RAYWHITE);
    EndDrawing();
}

void Renderer::renderGame(std::vector<std::vector<Candy>> candies)
{
    BeginDrawing();
    ClearBackground(RAYWHITE);
    int rows = candies.size();
    int cols = candies[0].size();
    int tileSize = std::min(screenWidth/cols, (screenHeight-menuHeight)/rows);
    for(std::vector<Candy> row : candies)
    {
        for(Candy candy : row)
        {
            Rectangle rect = {candy.getCol()*tileSize, candy.getRow()*tileSize+menuHeight, tileSize, tileSize};
            DrawRectangleRec(rect, getColor(candy.getType()));
            if(candy.isSelected()) {
                DrawRectangleLinesEx(rect, 2, WHITE);
            }
        }
    }
    
    EndDrawing();
}

Color Renderer::getColor(int number)
{
    return colorMap.find(number)->second;
}