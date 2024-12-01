#include "objPos.h"

objPos::objPos()     //default constructor for initilizsing the object positions 
{
    pos = new Pos;
    pos->x = 0;
    pos->y = 0;
    symbol = 0; //NULL
}

objPos::objPos(int xPos, int yPos, char sym)  //another constructor to initialize object manually 
{
    pos = new Pos;
    pos->x = xPos;
    pos->y = yPos;
    symbol = sym;
}

// Respect the rule of six / minimum four
// [TODO] Implement the missing special member functions to meet the minimum four rule



objPos::~objPos() //destructor 
{
    delete pos;   // Deallocate memory
    pos = nullptr; 
}

objPos& objPos::operator=(const objPos& b)
{
    if (this == &other) // Protect against self-assignment
        return *this;

    // Clean up existing resources
    delete pos;

    // Allocate new memory and copy values
    pos = new Pos;
    pos->x = b.pos->x;
    pos->y = b.pos->y;
    symbol = b.symbol;

    return *this;
}

objPos::objPos(const objPos& a)
{
    pos = new Pos; // Allocate new memory for the position
    pos->x = a.pos->x;
    pos->y = a.pos->y;
    symbol = a.symbol; // Copy the symbol
}


void objPos::setObjPos(objPos o) // sets the object position
{
    pos->x = o.pos->x;
    pos->y = o.pos->y;
    symbol = o.symbol;
}

void objPos::setObjPos(int xPos, int yPos, char sym)
{
    pos->x = xPos;
    pos->y = yPos;
    symbol = sym;
}

objPos objPos::getObjPos() const
{
    objPos returnPos;
    returnPos.pos->x = pos->x;
    returnPos.pos->y = pos->y;
    returnPos.symbol = symbol;
    
    return returnPos;
}

char objPos::getSymbol() const
{
    return symbol;
}

bool objPos::isPosEqual(const objPos* refPos) const
{
    return (refPos->pos->x == pos->x && refPos->pos->y == pos->y);
}

char objPos::getSymbolIfPosEqual(const objPos* refPos) const
{
    if(isPosEqual(refPos))
        return symbol;
    else
        return 0;
}
