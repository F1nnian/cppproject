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
    static const int tileSize = 50;
    static const std::map<int, Color> colorMap;
    Color getColor(int number);
    int menuHeight = 50;
public:
    Renderer(int screenWidth, int screenHeight);
    void renderGame(std::vector<std::vector<Candy>> candies);
    void init();
};
