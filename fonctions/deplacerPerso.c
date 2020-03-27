 #include "structs.h"


void initSpriteshet(Spritesheet *sph, const char* fic, int nbimgx, int nbimgy,Uint16 R, Uint16 G, Uint16 B)
{
   sph->nbimgx = nbimgx;
   sph->nbimgy = nbimgy;
   sph->sheet = Loadimage(fic);
   SDL_SetColorKey(sph->sheet, SDL_SRCCOLORKEY, SDL_MapRGB((sph->sheet)->format, 255, 0, 0));
   sph->imgw = sph->sheet->w / sph->nbimgx;
   sph->imgh = sph->sheet->h / sph->nbimgy;
}

void rectangleSprite(Spritesheet* sph, SDL_Rect *src, int image)
{
    src->w = (Uint16)sph->imgw;
    src->h = (Uint16)sph->imgh;
    src->x = (Uint16)((image % sph->nbimgx) * sph->imgw);
    src->y = (Uint16)((image / sph->nbimgx) * sph->imgh);
}

void initAnimation(Animation *a, int imagedepart, int nbimage, int delay)
{
   a->imagedepart = imagedepart;
   a->nbimage = nbimage;
   a->delay = delay;
}

int mouvementanim(Animation *a)
{
  return a->imagedepart + (SDL_GetTicks()/a->delay) % a->nbimage;
}

void initSprite(Sprite* s,Spritesheet* sph,int posx,int posy,int imagedepart)
{
   	s->posx = posx;
  	s->posy = posy;
   	s->sph = *sph;
   	s->sens = SENS_DROIT;
  	s->statut = ARRET;
   	initAnimation(&s->a, imagedepart, 1, 1);
}

void afficherSprite(SDL_Surface* ecran, Sprite* s, Map* m)
{  
    int image;
    SDL_Rect src, dest;
    image = mouvementanim(&s->a);
    rectangleSprite(&s->sph, &src,image);
    dest = src;
    dest.x = s->posx - m->xscroll;
    dest.y = s->posy - m->yscroll;
	SDL_BlitSurface(s->sph.sheet, &src ,ecran, &dest);
}

void movesprite(Input* in, Sprite* s, int speed)
{
	int i;
	int move = 0;
	int delay = 120;
	if(in->key[SDLK_LEFT])
	{
		move = 1;
        s->sens = SENS_GAUCHE;
        s->posx -= speed;
	}
	if(in->key[SDLK_RIGHT])
	{
		move = 1;
		s->sens = SENS_DROIT;
		s->posx += speed;
	}
	if(move)
	{
		s->statut = MARCHE;
		initAnimation(&s->a, s->sens * s->sph.nbimgx, 4, delay);
	}	
	if(s->sens == MARCHE && !move)
	{
		s->sens = ARRET;
		initAnimation(&s->a, s->a.imagedepart, 1, 1);
	}
}