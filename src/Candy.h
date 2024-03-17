#pragma once
#include <cstdlib> 
#include <raylib.h>

class Candy
{
public:
    Candy() = default;
    Candy(int row, int col);
    void setSelected(bool selected);      
    int getRow();
    int getCol();
    int getType() const;
    void swapped(int row, int col);  
    void setMatched(bool matched);         
    bool isSelected();                      
private:
    static const int NUM_COLORS = 6;
    // Color color;
    bool selected = false;
    int row;
    int col;
    int type;
    bool matched = false;
};
