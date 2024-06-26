#pragma once
#include "raylib.h"
#include <vector>
#include "Candy.h"
#include <map>
#include <iostream>

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
    std::map<int, Texture2D> textureMap;
    Color getColor(int number);
    int menuHeight = 50;
    void drawGameBoard(std::vector<std::vector<Candy>> candies);
    void drawMenu(std::map<int, int> candyMap, int score);
    void drawCandy(float row, int col, int type, bool isSelected, int tileSize, int menuHeight);
    void loadTextures();
    void drawCenteredText(const char *text, int fontSize, int posY, Color color);

public:
    Renderer(int screenWidth, int screenHeight);
    void renderGame(std::vector<std::vector<Candy>> candies, std::map<int, int> candyMap, int score);
    void init();
    int getTileSize(int rows, int cols);
    int getMenuHeight();
    int getScreenWidth();
    int getScreenHeight();
    void renderGameOver(int score);
};
