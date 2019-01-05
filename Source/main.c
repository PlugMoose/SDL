#include "stdio.h"
#include "SDL.h"
const int WIN_WIDTH = 640;
const int WIN_HEIGHT = 400;
SDL_Window* g_window = NULL;
SDL_Surface* g_surface = NULL;

bool SDL_start()
{
  bool OutVal = true;
  if (SDL_Init(SDL_INIT_VIDEO) < 0)
  {
    OutVal = false;
    printf ("SDL did't work ERROR:%s\n",SDL_GetError());
  }
  else
  {
    g_window = SDL_CreateWindow("WINDOW_TITLE",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,WIN_WIDTH,WIN_HEIGHT,SDL_WINDOW_SHOWN);
    if (g_window == NULL)
    {
      OutVal = false;
      printf("g_window == Null:%s",SDL_GetError());
    }
    else
    {
      g_surface = SDL_GetWindowSurface(g_window);
    };
  };
  return OutVal;
};

void SDL_Exit(void)
{
  SDL_DestroyWindow(g_window);
  SDL_Quit();
}

int main (int argc, char* args[])
{
  int INPUT;
  if (!SDL_start())
  {
      printf ("SDL did't work ERROR:%s\n",SDL_GetError());
      return -1;
  };
  /*
  if (SDL_Init (SDL_INIT_VIDEO) < 0)
  {
      printf ("SDL did't work ERROR:%s\n",SDL_GetError());
      return -1;
  };
  g_window = SDL_CreateWindow("WINDOW_TITLE",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,WIN_WIDTH,WIN_HEIGHT,SDL_WINDOW_SHOWN);
  if (g_window == NULL)
  {
    printf ("SDL_CreateWindow did't work ERROR:%s\n",SDL_GetError());
    return (-2);
  };
  g_surface = SDL_GetWindowSurface(g_window);
  *//*non modular code for start*/
  SDL_FillRect (g_surface , NULL, SDL_MapRGB(g_surface->format,0xAA,0xFF,0xFF) );
  SDL_UpdateWindowSurface(g_window);
  SDL_Delay(2000);
  printf ("SDL Working\n");
  scanf("%d",&INPUT);
  printf ("SDL Working\n");
  return 0;
};
