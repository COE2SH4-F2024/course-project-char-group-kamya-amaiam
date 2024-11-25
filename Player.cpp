#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    currentdir = STOP;

    // more actions to be included
    playerPos.pos->x = mainGameMechsRef->getBoardSizeX() / 2;
    playerPos.pos->y = mainGameMechsRef->getBoardSizeY() / 2;
    playerPos.symbol = '@';

}


Player::~Player()
{
    // delete any heap members here
    //no key word new in the constructor 
    //leave it empty for now 
}

objPos Player::getPlayerPos() const
{
    // return the reference to the playerPos arrray list
    return playerPos;
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
            case 27:
                mainGameMechsRef->setExitTrue();
                
            default:
                break;
        } 
        mainGameMechsRef->clearInput();  
            
}

        }
        // PPA3 input processing logic   
        

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
                if (playerPos.pos->y > 1)  //as soon as the character goes to border it starts again at the bottom 
                {
                    playerPos.pos->y --;
                }
                else
                {
                    playerPos.pos->y = height- 2;
                }
                break;
            case DOWN: 
                if (playerPos.pos->y < height-2)     //as soon as the character goes to border it starts again at the top
                {
                    playerPos.pos->y ++;
                }
                else
                {
                    playerPos.pos->y = 1;
                }
                break;
            case LEFT:
                if (playerPos.pos->x > 1)      //as soon as the character goes to border it starts again at the right
                {
                    playerPos.pos->x --;
                }
                else
                {
                    playerPos.pos->x = width - 2;
                }
                break;
            case RIGHT:
                if (playerPos.pos->x < width-2)  //as soon as the character goes to border it starts again at the left
                {
                    playerPos.pos->x ++;
                }
                else
                {
                    playerPos.pos->x = 1;
                }
                break;
        }
    }
}

// More methods to be added