#include "Player.h"



Player::Player(GameMechs* thisGMRef) 
{
    mainGameMechsRef = thisGMRef;
    currentdir = STOP;

    playerPosList = new objPosArrayList(); //creates initial snake body list 

    objPos headPos (mainGameMechsRef->getBoardSizeX()/2, mainGameMechsRef->getBoardSizeY() / 2, '@'); //initializes snake position
    playerPosList->insertHead(headPos);
}


Player::~Player()
{
    delete playerPosList;
}


objPosArrayList* Player::getPlayerPos() const
{
    return playerPosList;  //returns the snake array list 
}


void Player::updatePlayerDir()  //tracks player direction 
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
            
            case 'f':
                mainGameMechsRef->generateFood(getPlayerPos());
                break;
            
            case 27:
                mainGameMechsRef->setExitTrue();
                break;
                
            default:
                break;
        } 

    mainGameMechsRef->clearInput();  

    }   
}


void Player::movePlayer()
{
    // Finite State Machine logic
    if(currentdir != STOP)
    {
        int height = mainGameMechsRef->getBoardSizeY();
        int width = mainGameMechsRef->getBoardSizeX();

        //get the current head position
        objPos temphead = getPlayerPos()->getHeadElement();
        switch (currentdir)
        {
            case UP:
                if (temphead.pos->y > 1)  //as soon as the character goes to border it starts again at the bottom 
                {
                    temphead.pos->y --;
                }
                else
                {
                    temphead.pos->y = height- 2;
                }
                break;


            case DOWN: 
                if (temphead.pos->y < height-2)     //as soon as the character goes to border it starts again at the top
                {
                    temphead.pos->y ++;
                }
                else
                {
                    temphead.pos->y = 1;
                }
                break;


            case LEFT:
                if (temphead.pos->x > 1)      //as soon as the character goes to border it starts again at the right
                {
                    temphead.pos->x --;
                }
                else
                {
                    temphead.pos->x = width - 2;
                }
                break;


            case RIGHT:
                if (temphead.pos->x < width-2)  //as soon as the character goes to border it starts again at the left
                {
                    temphead.pos->x ++;
                }
                else
                {
                    temphead.pos->x = 1;
                }
                break;
        }

        //inserts the new head
        getPlayerPos()->insertHead(temphead);

        //check for collision
        if (checkSelfCollision()) 
        {
            mainGameMechsRef->setLoseFlag();
            mainGameMechsRef->setExitTrue();
        }

        else //no self collision
        {
            //checks for food consumption 
            if (checkFoodConsumption())
            {
                increasePlayerLength();
            }
            else
            {
                getPlayerPos()->removeTail();
            }

        }
        
    }
    
}


bool Player::checkFoodConsumption()
{
    //get the player head
    objPos head = getPlayerPos()->getHeadElement();

    //get food position 
    objPos food = mainGameMechsRef->getFoodPos();

    //checks for collision
    if (head.pos->x == food.pos->x && head.pos->y == food.pos->y)
    {
        return true; //food consumed 
    }

    return false; //if no food consumed 

}


void Player::increasePlayerLength() 
{
    mainGameMechsRef->generateFood(getPlayerPos()); //generates new food 
    mainGameMechsRef->incrementScore(); //update the score 
}


bool Player::checkSelfCollision() //returns true if collision will occur
{
    objPos head = getPlayerPos()->getHeadElement();

    for (int i = 1; i < getPlayerPos()->getSize(); i++)
    {
        if (head.pos->x == getPlayerPos()->getElement(i).pos->x && head.pos->y == getPlayerPos()->getElement(i).pos->y) 
        {
            return true;
        }

    }

    return false; //if head element doesnt collide with any body elements, then no collision will occur
}
