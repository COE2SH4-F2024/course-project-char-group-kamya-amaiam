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

   
}

void GetInput(void)
{
   char input = myGM->getInput();
   MacUILib_printf("input = %c\n", input);
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
    MacUILib_printf("Press 'esc' to exit.\n\n\n");
    //POSITION STATS
    objPos playerPos = myPlayer -> getPlayerPos();
    MacUILib_printf("player [x, y, symbol] = [%d, %d, %c]\n" , playerPos.pos->x, playerPos.pos->y, playerPos.symbol);
    




    for (int i = 0; i < myGM->getBoardSizeY(); i++)//columns 
    {
 
        for (int j = 0; j < myGM->getBoardSizeX(); j++)//rows
        {
            if  (j == 0 || j == myGM->getBoardSizeX()-1 || i == 0 || i == myGM->getBoardSizeY()-1)
            {
                MacUILib_printf("#");
            } 

            else if (i == playerPos.pos->y && j == playerPos.pos->x)
            {
                MacUILib_printf("%c", playerPos.symbol);
            }

            else
            {
                MacUILib_printf(" ");
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
