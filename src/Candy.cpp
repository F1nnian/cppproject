// This class implements the candy. It contains information about its position, type, and whether it is selected or matched. It also contains methods to set and get these attributes.

#include "Candy.h"

// Constructor with random type
Candy::Candy(int row, int col) : row(row), col(col)
{
    this->type = std::rand() % NUM_TYPES + 1; // Randomly assign a type to the candy
}

// Constructor with specific type
Candy::Candy(int row, int col, int type) : row(row), col(col), type(type)
{
    this->type = type; // Assign a specific type to the candy
}

// Get the number of candy types
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

// Set the position of the candy
void Candy::swapped(int row, int col)
{
    this->row = row;
    this->col = col;
}