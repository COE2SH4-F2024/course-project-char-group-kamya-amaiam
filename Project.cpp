#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "Player.h"

using namespace std;



const int speeds[5] = {200000, 175000, 150000, 125000, 100000}; //contols how fast the game is 
// speed levels in seconds: 0.2, 0.175, 0.15, 0.125, 0.1

Player *myPlayer; // global pointer meant to instantiate a player object 
GameMechs *myGM;


//function prototypes
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

    myGM = new GameMechs();
    myPlayer = new Player(myGM);

    myGM->generateFood(myPlayer->getPlayerPos());
    myGM->setFoodPos(-1,-1,'*');

    srand(time(NULL)); //for random number generation
}


void GetInput(void)  //gets input 
{
   char input = myGM->getInput();
   myGM->setInput(input);
}


void RunLogic(void)
{
    if (myGM->getFoodPos().pos->x == -1 && myGM->getFoodPos().pos->y == -1)
    {
        myGM->generateFood(myPlayer->getPlayerPos());
    }

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
   
    int boardX = myGM->getBoardSizeX(); //gets rows value
    int boardY = myGM->getBoardSizeY(); //gets column value


    for (int i = 0; i < boardY; i++) //columns 
    {
        for (int j = 0; j < boardX; j++) //rows
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

                if (!isPrinted && i == foodPos.pos->y && j == foodPos.pos->x) //draws food
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
    MacUILib_Delay(speeds[myGM->getSpeed()]); //delay depends on game speed level
}


void CleanUp(void)
{
    if(myGM->getLoseFlagStatus())
    {
        MacUILib_printf("\n\nGame Over ! you lose.\n");  //losing message 
    } 

    else 
    {
        MacUILib_printf("\n\nThanks for playing!!!\n"); //forced exit message 
    }

    delete myPlayer;
    delete myGM;

    MacUILib_uninit();
}
