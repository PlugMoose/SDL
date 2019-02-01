#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "SDL.h"
#include "SDL2/SDL_image.h"
#include <math.h>
const unsigned char DIRT = 0;
const unsigned char GRASS = 1;
const unsigned char SNOW = 2;
const unsigned char WATER = 3;
const unsigned char TERRIAN_NUMBER = 4;
const unsigned char TILE_WIDTH = 32;
const unsigned char TILE_HEIGHT = 32;
const unsigned int WIN_WIDTH = 1000;
const unsigned int WIN_HEIGHT = 700;

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
  int spacer;
  int Scale = 1;
  SDL_Window* Window = NULL;
  SDL_Renderer* Renderer = NULL;
  SDL_Surface* ImageLoader = NULL;
  SDL_Texture** TerriansTextures = NULL;
  FILE* MapReader;
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
  MapReader = fopen("./Res/map.txt","r");
  if (MapReader == NULL)
  {
    printf ("please check Res for map.txt");
    return -2;
  };
  char Size[5];
  unsigned int MapWidth = 0;
  unsigned int MapHeight = 0;
  fscanf (MapReader,"%s",Size);
  MapHeight = (Size[0] - '0')*10;
  MapHeight += (Size[1] - '0'+1);
  MapWidth = (Size[2] - '0')*10;
  MapWidth += (Size[3] - '0'+1);
  SDL_Rect TileA;
  TileA.x = 0;
  TileA.y = 0;
  TileA.w = 32;
  TileA.h = 32;
  SDL_Rect TileB;
  TileB.x = TILE_WIDTH*3/4;
  TileB.y = TILE_HEIGHT/2;
  TileB.w = 32;
  TileB.h = 32;
  SDL_Rect TileC;
  unsigned int** Map;
  Map = malloc((MapHeight+1)*(sizeof(unsigned int*)));
  for (unsigned char HeightLayer = 1;(HeightLayer < MapHeight+1);HeightLayer++)
  {
    printf ("Decleration:HeightLayer:%d\n",HeightLayer);
    Map[HeightLayer] = malloc((MapWidth+1)*(sizeof(unsigned int)));
  };
  printf("Map Built");
  char* Parser;
  Parser = malloc((MapWidth+1)*sizeof(char));
  for (unsigned char HeightLayer = 0;(HeightLayer < MapHeight);HeightLayer++)
  {
    printf ("\nAssginment:HeightLayer:%d\n",HeightLayer);
    fscanf(MapReader,"%s",Parser);
    printf("%s",Parser);
    for (unsigned char x = 0;x < MapWidth;x++)
    {
      Map[HeightLayer][x+1] = Parser[x] - '0';
      printf("Assginment:MapValues:%d::%d::%d\n",Map[HeightLayer][x+1],HeightLayer,x);
    };
  };
  SDL_SetRenderDrawColor(Renderer, 168, 230, 255, 255);
  SDL_RenderClear(Renderer);
  fclose(MapReader);
  TileC = TileA;
  for (unsigned char HeightLayer = 1;(HeightLayer < MapHeight);HeightLayer= HeightLayer + 2)
  {
    for (unsigned char x = 1;(x < MapWidth);x = x + 1)
    {
      TileC.x = TileC.x + (TILE_WIDTH*Scale)*1.5;
      if (!( x >  MapWidth || x < 1 || HeightLayer > MapHeight || HeightLayer < 1 ))
      {
        printf("\nHeightLayer=%d\nx=%d\nMap=%d",HeightLayer,x,Map[HeightLayer][x]);
        SDL_RenderCopy(Renderer, TerriansTextures[Map[HeightLayer][x]+1], NULL, &TileC);
      };
    };
    TileC.x = TileA.x;
    TileC.y = TileC.y + TILE_HEIGHT*Scale;
  };
  SDL_RenderPresent(Renderer);
  SDL_Delay(3000);
  TileC = TileB;
  for (unsigned char HeightLayer = 2;(HeightLayer < MapHeight+1);HeightLayer= HeightLayer + 2)
  {
    for (unsigned char x = 1;(x < MapWidth);x = x + 1)
    {
      TileC.x = TileC.x + (TILE_WIDTH*Scale)*1.5;
      if (!( x >  MapWidth || x < 1 || HeightLayer > MapHeight || HeightLayer < 1 ))
      {
        printf("\nHeightLayer=%d:x=%d:Map=%d",HeightLayer,x,Map[HeightLayer][x]);
        SDL_RenderCopy(Renderer, TerriansTextures[Map[HeightLayer][x]+1], NULL, &TileC);
      };
    };
    TileC.x = TileB.x;
    TileC.y = TileC.y + (TILE_HEIGHT*Scale);
  };
  printf("%d",Map[10][10]);
  SDL_RenderPresent(Renderer);
  printf ("\nSDL 1Working\n");
  SDL_Delay(10000);
  SDL_Exit(&Window,&Renderer,&TerriansTextures,&ImageLoader);
  //spacer = 2;
  free(Map);
  free(Parser);
  free(TerriansTextures);
  printf ("SDL2 Working\n");
  return 0;
};
