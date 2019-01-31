#include "stdio.h"
#include "stdlib.h"
#include <stdbool.h>
#include "SDL.h"
#include "SDL2/SDL_image.h"
const unsigned char DIRT = 0;
const unsigned char GRASS = 1;
const unsigned char SNOW = 2;
const unsigned char WATER = 3;
const unsigned char TERRIAN_NUMBER = 4;
const unsigned char MAP_LAYERS = 20;
const unsigned int MAP_WIDTH = 1000;
const unsigned int MAP_HEIGHT = 1000;
const unsigned int WIN_WIDTH = 1000;
const unsigned int WIN_HEIGHT = 700;
const unsigned char INITAL_SQUARE_WIDTH = 10;
const unsigned char INITAL_SQUARE_HEIGHT = 10;

bool SDL_start(SDL_Window **Window , SDL_Renderer** Renderer)
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
      printf ("SDL_img did't work ERROR:%s\n",SDL_GetError());
    }
    else
    {
      *Window = SDL_CreateWindow("WINDOW_TITLE",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,WIN_WIDTH,WIN_HEIGHT,SDL_WINDOW_SHOWN);
      if (*Window == NULL)
      {
        OutVal = false;
        printf("Window == Null:%s",SDL_GetError());
      }
      else
      {
        *Renderer = SDL_CreateRenderer(*Window,-1,0);
        if (*Renderer == NULL)
        {
          OutVal = false;
          printf("Renderer == Null:%s",SDL_GetError());
        };
      };
    };
  };
  return OutVal;
};

void SDL_Exit(SDL_Window** Window,SDL_Renderer** Renderer,SDL_Texture*** TextureMap,SDL_Surface** ImageLoader)
{
  for (unsigned char TerrianType = 1;!TerrianType > TERRIAN_NUMBER;TerrianType++)
  {
    SDL_DestroyTexture(*TextureMap[TerrianType]);
  };
  SDL_FreeSurface(*ImageLoader);
  SDL_DestroyRenderer(*Renderer);
  SDL_DestroyWindow(*Window);
  SDL_Quit();
}

int main (int argc, char* args[])
{
  SDL_Window* Window = NULL;
  SDL_Renderer* Renderer = NULL;
  SDL_Surface* ImageLoader = NULL;
  SDL_Texture** TerriansTextures = NULL;
  TerriansTextures = (SDL_Texture**)malloc(TERRIAN_NUMBER*sizeof(SDL_Texture*));
  if (!SDL_start(&Window ,&Renderer)||TerriansTextures == NULL)
  {
    return -1;
  };
  ImageLoader = IMG_Load("./Res/Dirt.png");
  TerriansTextures[1] = SDL_CreateTextureFromSurface(Renderer,ImageLoader);
  ImageLoader = IMG_Load("./Res/Grass.png");
  TerriansTextures[2] = SDL_CreateTextureFromSurface(Renderer,ImageLoader);
  ImageLoader = IMG_Load("./Res/Snow.png");
  TerriansTextures[3] = SDL_CreateTextureFromSurface(Renderer,ImageLoader);
  ImageLoader = IMG_Load("./Res/Water.png");
  TerriansTextures[4] = SDL_CreateTextureFromSurface(Renderer,ImageLoader);



  printf ("SDL Working\n");
  SDL_Delay(2000);
  printf ("SDL Working\n");
  SDL_Exit(&Window,&Renderer,&TerriansTextures,&ImageLoader);
  free(TerriansTextures);
  return 0;
};
