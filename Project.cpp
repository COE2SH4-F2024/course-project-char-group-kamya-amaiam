#include <iostream>
#include "MacUILib.h"
#include "objPos.h"

#include "Player.h"

using namespace std;


const int speeds[5] = {200000, 175000, 150000, 125000, 100000}; // in seconds: 0.2, 0.175, 0.15, 0.125, 0.1



Player *myPlayer; // global pointer meant to instantiate a player object 
GameMechs *myGM;



void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(myGM->getExitFlagStatus()==false)
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();

    myGM=new GameMechs();
    myPlayer = new Player(myGM);

    myGM->generateFood(myPlayer->getPlayerPos());

    srand(time(NULL));

}

void GetInput(void)
{
   char input = myGM->getInput();
   myGM->setInput(input);
}

void RunLogic(void)
{
    myPlayer->updatePlayerDir();
    myPlayer->movePlayer();

    
}

void DrawScreen(void)
{
    MacUILib_clearScreen();  
    
    //GAME STATS
    MacUILib_printf("Press 'Q' to decrease speed and 'E' to increase speed.\nCurrent Speed Level: %d\n\n", (myGM->getSpeed()+1));
    MacUILib_printf("Press 'esc' to exit.\n\n");
    MacUILib_printf("Score: %d\n\n\n", myGM->getScore());
    //POSITION STATS
    objPosArrayList* playerPos = myPlayer->getPlayerPos(); 
    objPos foodPos = myGM->getFoodPos();
    //MacUILib_printf("player [x, y, symbol] = [%d, %d, %c]\n" , playerPos->getElement(0).pos->x, playerPos.getElement(0).pos->y, playerPos->getElement(0).symbol);
    
    int boardX = myGM->getBoardSizeX(); //gets rows value
    int boardY = myGM->getBoardSizeY(); //gets column value



    for (int i = 0; i < boardY; i++)//columns 
    {
 
        for (int j = 0; j < boardX; j++)//rows
        {
            if  (j == 0 || j == boardX-1 || i == 0 || i == boardY-1) //draws border 
            {
                MacUILib_printf("#");
            } 
            else 
            {
                bool isPrinted = false;
                for (int k = 0; k < playerPos->getSize(); k++)
                {
                    if (i == playerPos->getElement(k).pos->y && j == playerPos->getElement(k).pos->x) //draws player 
                        {
                            MacUILib_printf("%c", playerPos->getElement(k).symbol);
                            isPrinted = true;
                            break;
                        }

                }
                if (!isPrinted && i == foodPos.pos->y && j == foodPos.pos->x)
                {
                    MacUILib_printf("%c", foodPos.symbol);
                }

                // If neither snake nor food, print an empty space
                if (!isPrinted && !(i == foodPos.pos->y && j == foodPos.pos->x))
                {
                    MacUILib_printf(" ");
                }

            }

        }
         MacUILib_printf("\n");
          
    }
    
}

void LoopDelay(void)
{
    MacUILib_Delay(speeds[myGM->getSpeed()]); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();   

    if(myGM->getLoseFlagStatus())
    {
        MacUILib_printf("Game Over ! you lose.\n");
    } 
    else 
    {
        MacUILib_printf("Thanks for playing!!\n");
    }
    delete myPlayer;
    delete myGM;

    MacUILib_uninit();
}
