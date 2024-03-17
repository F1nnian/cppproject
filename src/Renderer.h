#pragma once
#include "raylib.h"
#include <vector>
#include "Candy.h"
#include <map>

class Renderer
{
private:
    int screenWidth;
    int screenHeight;
    const std::map<int, Color> colorMap = {
        {0, BLANK},
        {1, RED},
        {2, GREEN},
        {3, BLUE},
        {4, YELLOW},
        {5, ORANGE},
        {6, PURPLE},
    };
    Color getColor(int number);
    int menuHeight = 50;
public:
    Renderer(int screenWidth, int screenHeight);
    void renderGame(std::vector<std::vector<Candy>> candies);
    void init();
    int getTileSize();
};
