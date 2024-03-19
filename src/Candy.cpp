#include "Candy.h"

Candy::Candy(int row, int col): row(row), col(col)
{
    this->type = std::rand() % NUM_TYPES + 1;
}

Candy::Candy(int row, int col, int type): row(row), col(col), type(type)
{
    this->type = type;
}

int Candy::getNumTypes()
{
    return NUM_TYPES;
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