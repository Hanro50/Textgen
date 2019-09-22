#ifndef SCREENCODE_H_INCLUDED
#define SCREENCODE_H_INCLUDED

#define xlim 80
#define ylim 22

#include <stdio.h>
#include <stdlib.h>

//Unicode can be annoying...

void Scrdraw(wchar_t Scr[xlim][ylim]);//Screen drawing
void Scrclr(wchar_t Scr[xlim][ylim]);

#endif // SCREENCODE_H_INCLUDED
