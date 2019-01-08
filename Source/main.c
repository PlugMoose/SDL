#include "stdio.h"
#include "SDL.h"
#include "SDL2/SDL_image.h"
#include "FastNoise.h"
const int WIN_WIDTH = 640;
const int WIN_HEIGHT = 400;

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
  return OutVal;
};

void SDL_Exit(SDL_Window **Window)
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
  SDL_FillRect (Surface, NULL, SDL_MapRGB(Surface->format,0xAA,0xFF,0xFF));
  SDL_UpdateWindowSurface(Window);
  printf ("SDL Working\n");
  SDL_Delay(2000);
  printf ("SDL Working\n");
  SDL_Exit(&Window);
  return 0;
};
