 //#include "scrolling.h"
  #include "structs.h"

int main(int argc, char *argv[])
{
   
  SDL_Surface *ecran=NULL;
  Map m;
  Input in;
  Sprite s;
  Spritesheet sph;
   
  SDL_Init(SDL_INIT_VIDEO );
   
  ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE);

  SDL_WM_SetCaption("Caleb Essaie !", NULL);
  initSpriteshet(&sph, "pecheur.bmp", 4, 4, 255, 127, 0);
  initInput(&in);
  initMap(&m, "back.png", 800, 600);
  initSprite(&s, &sph, 100, 500, 0);
  while(!in.quit && !in.key[SDLK_ESCAPE])
  {
    updateEvent(&in);
    if(scrollcenter(&s, &m))
      moveMap(&m,1,&in);
    movesprite(&in, &s, 1);
    afficher(&m);  
    afficherSprite(ecran,&s,&m);   
    SDL_Flip(ecran);                 
  }
  SDL_Quit();
  //Liberer(&s.sheet);
}