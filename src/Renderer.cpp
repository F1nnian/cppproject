#include "Renderer.h"

Renderer::Renderer(int screenWidth, int screenHeight)
{
    screenWidth = screenWidth;
    screenHeight = screenHeight;
    const std::map<int, Color> colorMap = {
        {0, BLANK},
        {1, RED},
        {2, GREEN},
        {3, BLUE},
        {4, YELLOW},
        {5, ORANGE},
        {6, PURPLE},
    };
    init();
}

void Renderer::init()
{
    InitWindow(screenWidth, screenHeight, "Candy Crush");
    SetTargetFPS(60);
}

void Renderer::renderGame(std::vector<std::vector<Candy>> candies)
{
    BeginDrawing();
    ClearBackground(RAYWHITE);
    int rows = candies.size();
    int cols = candies[0].size();
    for(std::vector<Candy> row : candies)
    {
        for(Candy candy : row)
        {
            Rectangle rect = {candy.getCol()*tileSize, candy.getCol()*tileSize+menuHeight, tileSize, tileSize};
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