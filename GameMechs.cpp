#include "GameMechs.h"
#include "MacUILib.h"


GameMechs::GameMechs()
{
    input = 0;
    exitFlag = false;
    loseFlag = false;
    score = 0;

    boardSizeX = 30;
    boardSizeY = 15;

    speed = 0; //initial speed level

    food.setObjPos(-100,-100,'*'); //initialize it outside the game board 
}


GameMechs::GameMechs(int boardX, int boardY)
{
    input = 0;
    exitFlag = false;
    loseFlag = false;
    score = 0;

    boardSizeX = boardX;
    boardSizeY = boardY;

    speed = 0;

    food.setObjPos(-100,-100,'*');//initialize it outside the game board 
}


GameMechs::~GameMechs()
{
    //nothing on heap for now 
}


bool GameMechs::getExitFlagStatus() const
{
    return exitFlag;
}


bool GameMechs::getLoseFlagStatus() const
{
    return loseFlag;
}
    

char GameMechs::getInput() 
{
    if(MacUILib_hasChar()!=0)
    {
        input = MacUILib_getChar();
    }
    return input;
}


int GameMechs::getScore() const
{
    return score;
}


void GameMechs::incrementScore()
{
    score++;
}


int GameMechs::getBoardSizeX() const
{
    return boardSizeX;
}


int GameMechs::getBoardSizeY() const
{
    return boardSizeY;
}


void GameMechs::setExitTrue()
{
    exitFlag = true;
}


void GameMechs::setLoseFlag()
{
   loseFlag = true; 
}


void GameMechs::setInput(char this_input)
{
    input = this_input;
}


void GameMechs::clearInput()
{
    input = 0;
}


int GameMechs::getSpeed() const
{
    return speed;
}


void GameMechs::setSpeed(char symbol) 
{
    if (symbol == '+') 
    {
        speed++;
        if (speed >= 4) {speed = 4;}
    }

    else 
    {
        speed--;
        if (speed <= 0) {speed = 0;}
    }
}


void GameMechs::generateFood(objPosArrayList* blockoff)
{
    int randX, randY;

    bool uniquePos = false;
    while(!uniquePos)
    {
        randX = rand()%(boardSizeX-2) + 1;
        randY = rand()%(boardSizeY-2) + 1;

        for (int i=0; i<blockoff->getSize(); i++)
        {
            if(randX != blockoff->getElement(i).pos->x && randY != blockoff->getElement(i).pos->y) 
            {
                uniquePos = true;
                food.setObjPos(randX, randY, '*');
            }
        }
    }
}


objPos GameMechs::getFoodPos() const
{
    return food; 
}
