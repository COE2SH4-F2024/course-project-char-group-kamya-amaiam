#include "objPos.h"

objPos::objPos()  //default constructor 
{
    pos = new Pos;
    pos->x = 0;
    pos->y = 0;
    symbol = 0; //NULL
}

objPos::objPos(int xPos, int yPos, char sym) //manual constructor 
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
    delete pos;//deallocate memory 
    pos = nullptr;
}

objPos::objPos (const objPos& a) //explicitly copies from existing pos
{
    pos = new Pos;
    pos->x=a.pos->x;
    pos->y=a.pos->y;
    symbol = a.symbol;
}

objPos& objPos::operator = (const objPos& a)
{
    if (this == &a) return *this;

    delete pos;
    pos = new Pos;
    pos->x = a.pos->x;
    pos->y = a.pos->y;
    symbol = a.symbol;

    return *this;
}


void objPos::setObjPos(objPos o) //sets default object position 
{
    pos->x = o.pos->x;
    pos->y = o.pos->y;
    symbol = o.symbol;
}

void objPos::setObjPos(int xPos, int yPos, char sym) //sets object position manually 
{
    pos->x = xPos;
    pos->y = yPos;
    symbol = sym;
}

objPos objPos::getObjPos() const //gets onject position 
{
    objPos returnPos;
    returnPos.pos->x = pos->x;
    returnPos.pos->y = pos->y;
    returnPos.symbol = symbol;
    
    return returnPos;
}

char objPos::getSymbol() const //returns symbol 
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
