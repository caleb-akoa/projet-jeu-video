#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

#define SENS_HAUT 0
#define SENS_DROIT 1
#define SENS_BAS 2
#define SENS_GAUCHE 3

#define ARRET 0
#define MARCHE 1



typedef struct 
{
	int key[SDLK_LAST];
	int mousex, mousey;
	int mousebutton[8];
	int quit;
}Input;

typedef struct 
{
 	int w,h;
	int xscroll, yscroll, wscroll, hscroll;
 	SDL_Surface *image;	
}Map;


typedef struct
{
   SDL_Surface *sheet;
   int nbimgx, nbimgy;
   int imgw, imgh;
}Spritesheet;


typedef struct 
{
   int imagedepart;
   int nbimage;
   int delay; 
}Animation;

typedef struct
{
	int posx, posy;
   	int sens;
  	int statut;
  	Spritesheet sph;
   	Animation a;

}Sprite;

SDL_Surface* Loadimage(const char* fich);
void initMap(Map* m, const char* fich, int w, int h);
int scrollcenter(Sprite* s, Map* m);
void moveMap(Map* m, int move, Input* in);
void afficher(Map* m);

void updateEvent(Input* in);
void initInput(Input *in);

void initSpriteshet(Spritesheet *sph, const char* fic, int nbimgx, int nbimgy,Uint16 R, Uint16 G, Uint16 B);
void Liberer(Spritesheet* p);
void initSprite(Sprite* s,Spritesheet* sph,int posx,int posy,int imagedepart);
void afficherSprite(SDL_Surface* ecran, Sprite* s, Map* m);
void movesprite(Input* in, Sprite* s, int speed);

#endif // STRUCTS_H_INCLUDED