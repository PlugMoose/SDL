#include "stdio.h"
#include "stdlib.h"
#include "SDL.h"
#include "SDL2/SDL_image.h"
#include "Common.h"
const int MAP_LAYERS = 5;
const int MAP_WIDTH = 100;
const int MAP_HEIGHT = 70;
const int WIN_WIDTH = 1000;
const int WIN_HEIGHT = 700;
const int SQUARE_WIDTH = 10;
const int SQUARE_HEIGHT = 10;

bool SDL_start(SDL_Window **Window , SDL_Surface **Surface)
{
  bool OutVal = true;
  if (SDL_Init(SDL_INIT_VIDEO) < 0)
  {
    OutVal = false;
    printf ("SDL did't work ERROR:%s\n",SDL_GetError());
  }
  else
  {
    if (IMG_Init(IMG_INIT_PNG) < 0)
    {
      OutVal = false;
      printf ("SDL did't work ERROR:%s\n",SDL_GetError());
    }
    else
    {
      *Window = SDL_CreateWindow("WINDOW_TITLE",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,WIN_WIDTH,WIN_HEIGHT,SDL_WINDOW_SHOWN);
      if (Window == NULL)
      {
        OutVal = false;
        printf("Window == Null:%s",SDL_GetError());
      }
      else
      {
        *Surface = SDL_GetWindowSurface(*Window);
      };
    };
  };
  return OutVal;
};

void SDL_Exit(SDL_Window** Window)
{
  SDL_DestroyWindow(*Window);
  SDL_Quit();
}

int main (int argc, char* args[])
{
  SDL_Window *Window = NULL;
  SDL_Surface *Surface = NULL;
  if (!SDL_start(&Window ,&Surface))
  {
    printf ("SDL did't work ERROR:%s\n",SDL_GetError());
    return -1;
  };



  SDL_UpdateWindowSurface(Window);
  printf ("SDL Working\n");
  SDL_Delay(2000);
  printf ("SDL Working\n");
  SDL_Exit(&Window);
  return 0;
};
