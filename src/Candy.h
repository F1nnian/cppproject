#pragma once
#include <cstdlib>
#include <raylib.h>

class Candy
{
public:
    Candy() = default;
    Candy(int row, int col);
    Candy(int row, int col, int type);
    void setSelected(bool selected);
    int getRow();
    int getCol();
    int getType() const;
    void swapped(int row, int col);
    void setMatched(bool matched);
    bool isSelected();
    static int getNumTypes();

private:
    static const int NUM_TYPES = 6;
    bool selected = false;
    int row;
    int col;
    int type;
    bool matched = false;
};
