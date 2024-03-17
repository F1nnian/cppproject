#include "Candy.h"
#include <iostream>

Candy::Candy(int row, int col): row(row), col(col)
{
    this->type = std::rand() % NUM_COLORS + 1;
    // switch (type) {
    //     case 1: color = RED; break;
    //     case 2: color = GREEN; break;
    //     case 3: color = BLUE; break;
    //     case 4: color = YELLOW; break;
    //     case 5: color = ORANGE; break;
    //     case 6: color = PURPLE; break;
    //     default: color = WHITE; break;
    // }
}

void Candy::setSelected(bool selected)
{
    this->selected = selected;
}

void Candy::setMatched(bool matched)
{
    // color = matched ? BLANK : color;
    this->type = 0;
}

int Candy::getRow()
{
    return row;
}

int Candy::getCol()
{
    return col;
}

int Candy::getType() const
{
    return type;
}

bool Candy::isSelected()
{
    return selected;
}

void Candy::swapped(int row, int col)
{
    this->row = row;
    this->col = col;
}