#include "Candy.h"
#include <iostream>

Candy::Candy()
{
    std::cout << "Default constructor" << std::endl;
}

Candy::Candy(int row, int col): row(row), col(col)
{
    std::cout << "Row: " << row << " Col: " << col << std::endl;
    type = std::rand() % NUM_COLORS + 1;
    switch (type) {
        case 1: color = RED; break;
        case 2: color = GREEN; break;
        case 3: color = BLUE; break;
        case 4: color = YELLOW; break;
        case 5: color = ORANGE; break;
        case 6: color = PURPLE; break;
        default: color = WHITE; break;
    }
}

void Candy::setSelected(bool selected)
{
    _selected = selected;
}

void Candy::setMatch(bool matched)
{
    type = 0;
}

int Candy::getRow()
{
    return row;
}

int Candy::getCol()
{
    return col;
}

int Candy::getType()
{
    return type;
}

void Candy::swapped(int row, int col)
{
    this->row = row;
    this->col = col;
}

void Candy::draw(int menuHeight, int tileSize)
{
    if(type == 0) color = BLANK;
    Rectangle rect = {col*tileSize, row*tileSize+menuHeight, tileSize, tileSize};
    DrawRectangleRec(rect, color);
    if(_selected) {
        DrawRectangleLinesEx(rect, 2, WHITE);
    }
}