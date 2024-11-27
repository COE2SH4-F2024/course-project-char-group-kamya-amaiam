#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    currentdir = STOP;

    // more actions to be included
    //playerPosList->getElement(0).pos->x = mainGameMechsRef->getBoardSizeX() / 2;
    //playerPosList->getElement(0).pos->y = mainGameMechsRef->getBoardSizeY() / 2;
    //playerPosList->getElement(0).symbol = '@';

    

    playerPosList->getElement(0).setObjPos(mainGameMechsRef->getBoardSizeX() / 2, mainGameMechsRef->getBoardSizeY() / 2, '@');


    

}



Player::~Player()
{
    delete[] playerPosList;
}

objPosArrayList* Player::getPlayerPos() const
{
    return playerPosList;
}

void Player::updatePlayerDir()
{
    char input = mainGameMechsRef->getInput();
    
    if(input!=0)
    {
        switch(input)
        {                      
        case 'W':  //UP
        case 'w':
            if (currentdir != DOWN && currentdir != UP)
            {
                currentdir = UP;
            }
            break;
        
        case 'A':   //LEFT
        case 'a':
            if (currentdir != RIGHT && currentdir != LEFT)
                {
                    currentdir = LEFT;
                }
            break;

        case 'S':   //DOWN
        case 's':
            if (currentdir != UP && currentdir != DOWN)
            {
                currentdir = DOWN;
            }
            break;

        case 'D':    //RIGHT
        case 'd':
            if (currentdir != LEFT && currentdir != RIGHT)
            {
                currentdir = RIGHT;
            }
            break;
        
        case 'E':   //INCREASES SPEED
        case 'e':
            (mainGameMechsRef->setSpeed('+')); 
            break;

        case 'Q':   //DECREASES SPEED
        case 'q':
            (mainGameMechsRef->setSpeed('-')); 
            break;

        case 27:
            mainGameMechsRef->setExitTrue();
            
        default:
            break;
        } 

    mainGameMechsRef->clearInput();  

    }
    
}


        

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
       if(currentdir != STOP)
    {
        int height = mainGameMechsRef->getBoardSizeY();
        int width = mainGameMechsRef->getBoardSizeX();
        switch (currentdir)
        {
            case UP:
                // [TODO] : Heed the border wraparound!!!
                if (playerPosList->getElement(0).pos->y > 1)  //as soon as the character goes to border it starts again at the bottom 
                {
                    playerPosList->getElement(0).pos->y --;
                }
                else
                {
                    playerPosList->getElement(0).pos->y = height- 2;
                }
                break;
            case DOWN: 
                if (playerPosList->getElement(0).pos->y < height-2)     //as soon as the character goes to border it starts again at the top
                {
                    playerPosList->getElement(0).pos->y ++;
                }
                else
                {
                    playerPosList->getElement(0).pos->y = 1;
                }
                break;
            case LEFT:
                if (playerPosList->getElement(0).pos->x > 1)      //as soon as the character goes to border it starts again at the right
                {
                    playerPosList->getElement(0).pos->x --;
                }
                else
                {
                    playerPosList->getElement(0).pos->x = width - 2;
                }
                break;
            case RIGHT:
                if (playerPosList->getElement(0).pos->x < width-2)  //as soon as the character goes to border it starts again at the left
                {
                    playerPosList->getElement(0).pos->x ++;
                }
                else
                {
                    playerPosList->getElement(0).pos->x = 1;
                }
                break;
        }
    }
}

// More methods to be added