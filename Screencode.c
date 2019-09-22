/*
Developer notes:

Clearing the terminal was a nightmare on Linux.
"Clear" didn't work consistently when it decided to work at all
"Reset" is to slow and made the whole thing lag way to much
Doing printf("\033c"); for some reason made the terminal stop using unicode at all
"system("printf \"\\033c\"");" is the only thing that works...
*/


#include "Screencode.h"
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>

void trmclr(); //Terminal clear code. Separated from rest of code to increase ease of porting code

void Scrdraw(wchar_t Scr[xlim][ylim])
{
    int x, y;

    setlocale(LC_ALL, ""); //This is just here cause this entire thing was a nightmare to get working
    trmclr(); //Previously mentioned command

    for (y=0;y<(ylim);y++)
    {
        for (x=0;x<(xlim);x++)
        {
            wprintf(L"%lc", Scr[x][y]); //Draws the screen by using the Scr array as a reference for what should be on the screen
        }
        //wprintf(L"%lc", 0x0085);
        wprintf(L"\n");
    }
}

void Scrclr(wchar_t Scr[xlim][ylim])
{
    int x, y;
    for (y=0;y<(ylim);y++)
    {
        for (x=0;x<(xlim);x++)
        {
            //Box corners - First draws the box boarders
            if       ((x == 0) && (y == 0))
            {
                Scr[x][y] = 0x256D;
            }
            else if  ((x == 0) && (y == ylim-1))
            {
                Scr[x][y] = 0x2570;
            }
            else if  ((x == xlim-1) && (y == 0))
            {
                Scr[x][y] = 0x256E;
            }
            else if  ((x == xlim-1) && (y == ylim-1))
            {
                Scr[x][y] = 0x256F;
            }
            //Box borders
            else if ((x == xlim-1) || (x == 0))
            {
                Scr[x][y] = 0x2502;
            }
            else if ((y == ylim-1) || (y == 0))
            {
                Scr[x][y] = 0x2500;
            }
            else
            {
                Scr[x][y] = 0x0020; //This is just unicode for space...at some point normal letters stopped working
            }
        }
    }
}

void trmclr()
{
    system("printf \"\\033c\""); //Optimized for Linux Terminal for now. Will need to be changed for windows.
}
