#include "Renderer.h"

Renderer::Renderer(int screenWidth, int screenHeight)
{
    InitWindow(screenWidth, screenHeight, "Candy Crush");
    SetTargetFPS(60);
}