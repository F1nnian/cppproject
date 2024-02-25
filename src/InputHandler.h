#pragma once

class InputHandler 
{
public:
    InputHandler(int width, int height, int tileSize, int menuHeight, int ROWS, int COLS);
    void handleMouseInput(int mouseX, int mouseY);
    int getSelectedRow();
    int getSelectedCol();
    void reset();
private:
    int width;
    int height;
    int tileSize;
    int menuHeight;
    int ROWS;
    int COLS;
};
