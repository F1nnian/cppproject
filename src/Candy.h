#pragma once
#include <cstdlib> 
#include <raylib.h>

class Candy
{
public:
    Candy() = default;
    Candy(int row, int col);
    void setSelected(bool selected);       // SRP: Handles only setting the selected state
    int getRow();
    int getCol();
    void swapped(int row, int col);        // SRP: Handles only swapping the candy
    void draw(int menuHeight, int tileSize);
    bool isAdjacentTo(const Candy& other); // SRP: Handles only adjacency checking
    // Other candy methods
private:
    static const int NUM_COLORS = 4;
    Color color;
    bool _selected = false;
    int row;
    int col;
    // Other properties
};
