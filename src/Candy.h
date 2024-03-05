#pragma once
#include <cstdlib> 
#include <raylib.h>

class Candy
{
public:
    Candy();
    Candy(int row, int col);
    void setSelected(bool selected);      
    int getRow();
    int getCol();
    int getType();
    void swapped(int row, int col);       
    void draw(int menuHeight, int tileSize);
    bool isAdjacentTo(const Candy& other); 
    void setMatched(bool matched);         
    bool isSelected();                      
private:
    static const int NUM_COLORS = 6;
    Color color;
    bool selected = false;
    int row;
    int col;
    int type;
    bool matched = false;
};
