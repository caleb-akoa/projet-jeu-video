#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

typedef struct 
{
	int key[SDLK_LAST];
	int mousex, mousey;
	int mousebutton[8];
	int quit;
} Input;

void updateEvent(Input* in);
void initInput(Input *in);
#endif // INPUT_H_INCLUDED