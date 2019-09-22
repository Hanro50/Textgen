
#include <stdlib.h>
#include <stdio.h>
#include <wchar.h>
#include <locale.h>
#include "Screencode.h"
#include "External_code.h"
void player(wchar_t Scr[xlim][ylim], int direction); //Start of basic gamecode

//Start thread
int main( )
    {
    wchar_t Scr[xlim][ylim]; //Screen buffer variable
    char ckey = 65; //User input
    int iLdir = 0; //Last direction integer
    Scrclr(Scr); //Clears the screen buffer

    while (0==0)
    {
        Scrdraw(Scr); //Draws the screen
        usleep(40000);//Framerate variable (Running at 12.5 fps)
        changemode(1); //External code initializer

        if ( kbhit() != 0 ) //Provided by external library (Credit in library doc)
        {
            ckey = getchar();

        }

        switch(ckey) //Detect the direction of travel
        {
        case 68:
        case 100: //d
            player(Scr, 0);
            iLdir = 0 ;
            break;
        case 87:
        case 119: //w
            player(Scr, 3);
            iLdir = 3 ;
            break;
        case 65:
        case 97: //a
            player(Scr, 2);
            iLdir = 2 ;
            break;
        case 83:
        case 115: //s
            player(Scr, 1);
            iLdir = 1 ;
            break;
        default:
            player(Scr, iLdir);
        }



        usleep(40000);//Framerate variable (Running at 12.5 fps)
    }


    return 0;
}
//Start of basic game code
void player(wchar_t Scr[xlim][ylim], int direction)
{
    static int x = (xlim/2); //Keeps track of player x cord
    static int y = (ylim/2); //Keeps track of player y cord

    switch(direction) //Controls direction of player
    {
    case 0: //Right
        if (x<xlim-2)
            Scr[++x][y]='*'; //Player trail
        else if (x<xlim-1) //Screen loop function
        {
            x=1;  //Resets to opposite max edge
            Scr[x][y]='*'; //Player trail
        }
        break;
    case 1: //Down
        if (y<ylim-2)
            Scr[x][++y]='*'; //Player trail
        else if (y<ylim-1)
        {
            y=1; //Resets to opposite max edge
            Scr[x][y]='*'; //Player trail
        }
        break;
    case 2: //Left
        if (x>1)
            Scr[--x][y]='*'; //Player trail
        else if (x>0)
        {
            x=xlim-2; //Resets to opposite max edge
            Scr[x][y]='*'; //Player trail
        }
        break;
    case 3: //Up
        if (y>1)
            Scr[x][--y]='*'; //Player trail
        else if (y>0)
        {
            y=ylim-2; //Resets to opposite max edge
            Scr[x][y]='*'; //Player trail
        }
        break;
    }
}



