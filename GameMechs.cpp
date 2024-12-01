#include "GameMechs.h"
#include "MacUILib.h"


GameMechs::GameMechs()  //default constructor 
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


GameMechs::GameMechs(int boardX, int boardY) //other constructor 
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


GameMechs::~GameMechs() //we do not need destructor 
{
    //nothing on heap for now 
}


bool GameMechs::getExitFlagStatus() const //returns exit flag
{
    return exitFlag;
}


bool GameMechs::getLoseFlagStatus() const //returns losing status 
{
    return loseFlag;
}
    

char GameMechs::getInput()  //receives inputs 
{
    if(MacUILib_hasChar()!=0)
    {
        input = MacUILib_getChar();
    }
    return input;
}


int GameMechs::getScore() const //returns scores 
{
    return score;
}


void GameMechs::incrementScore() //increment sscore 
{
    score++;
}


int GameMechs::getBoardSizeX() const //returns board's row size 
{
    return boardSizeX;
}


int GameMechs::getBoardSizeY() const //returns boards column size 
{
    return boardSizeY;
}


void GameMechs::setExitTrue()  //stes the exit statustrue 
{
    exitFlag = true;
}


void GameMechs::setLoseFlag() //sets loseflag as true 
{
   loseFlag = true; 
}


void GameMechs::setInput(char this_input) //stes input 
{
    input = this_input;
}


void GameMechs::clearInput() // resets input
{
    input = 0;
}


int GameMechs::getSpeed() const //returns speed 
{
    return speed;
}


void GameMechs::setSpeed(char symbol) //speed management function 
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


void GameMechs::setFoodPos(int x, int y, char symbol) //sets food 
{
    food.setObjPos(x, y, symbol);
}


objPos GameMechs::getFoodPos() const //returns food 
{
    return food; 
}


void GameMechs::generateFood(objPosArrayList* blockoff) //generate food at randomlocations 
{
    int randX, randY;

    bool uniquePos = false;
    while(!uniquePos)
    {
        randX = rand()%(boardSizeX-2) + 1;  //generates random co-ordinates 
        randY = rand()%(boardSizeY-2) + 1;

        for (int i=0; i<blockoff->getSize(); i++) //makes sure it dosent generate on the sanke body 
        {
            if(randX != blockoff->getElement(i).pos->x && randY != blockoff->getElement(i).pos->y) 
            {
                uniquePos = true;
                setFoodPos(randX, randY, '*');
            }
        }
    }
}
