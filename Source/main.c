#include "stdio.h"
#include "stdlib.h"
#include "SDL.h"
#include "SDL2/SDL_image.h"
#include "FastNoise.h"
#include "Shapes.h"
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

void SDL_Exit(SDL_Window** Window)
{
  SDL_DestroyWindow(*Window);
  SDL_Quit();
}

/*
SDL_Rect* ConversionDrawMap(SDL_Rect** Map,unsigned short Radius,Point Center)
{
SDl_Rect* DrawMap[(WIN_WIDTH/SQUARE_WIDTH)*(WIN_HEIGHT/SQUARE_HEIGHT)];
SDL_Rect
unsigned int Offset;
unsigned int RowOffset;
unsigned int ColumnOffset;
for (unsigned int Column = Center.x;!(Column < );Column++)
{
Offset = Column*(WIN_HEIGHT/SQUARE_HEIGHT);
for (unsigned int Row = Center.y;!(Row < WIN_HEIGHT/SQUARE_HEIGHT);Row++)
{
if ((Column+ColumnOffset)<0 || (Column+ColumnOffset)>(WIN_HEIGHT/SQUARE_HEIGHT) ||(Row+RowOffset)<0 || (Row+RowOffset)>(WIN_WIDTH/SQUARE_WIDTH))
{
DrawMap[Offset+Row] = NULL
}
else
{
DrawMap[Offset+Row] = Map[Column+ColumnOffset][Row+RowOffset];
}
RowOffset = RowOffset + 1;
};
ColumnOffset + 1
};
return DrawMap
};
*/

int main (int argc, char* args[])
{
  FastNoise NoiseMap;
  NoiseMap.SetNoiseType(FastNoise::SimplexFractal);
  NoiseMap.SetFractalOctaves(5);
  SDL_Window *Window = NULL;
  SDL_Surface *Surface = NULL;
  if (!SDL_start(&Window ,&Surface))
  {
    printf ("SDL did't work ERROR:%s\n",SDL_GetError());
    return -1;
  };
  Uint32  Sea = SDL_MapRGB(Surface->format,0xFF,0xAA,0xFF);
  Uint32  Forest = SDL_MapRGB(Surface->format,0xFF,0xBB,0xFF);
  Uint32  Foothill = SDL_MapRGB(Surface->format,0xFF,0xCC,0xFF);
  Uint32  Mountain = SDL_MapRGB(Surface->format,0xFF,0xDD,0xFF);
  Uint32 Colour;

  bool*** Map;
  Map = (bool***)malloc(MAP_LAYERS*sizeof(bool**));
  for (unsigned char Layers = 1;Layers < MAP_LAYERS;Layers++)
  {
    Map[Layers] = (bool**)malloc(MAP_WIDTH*sizeof(bool*));
    for (unsigned char Column = 1;Column < MAP_WIDTH;Column++)
    {
      Map[Layers][Column] = (bool*)malloc(MAP_HEIGHT*sizeof(bool));
      for (unsigned char Row = 1;Row < MAP_HEIGHT;Row++)
      {
        Map[Layers][Column][Row] = false;
      };
    };
  };

  SDL_Rect DrawMap;

  for (unsigned char Column = 1;Column < MAP_WIDTH-1;Column++)
  {
    for (unsigned char Row = 1;Row < MAP_HEIGHT-1;Row++)
    {
      DrawMap.x = ((Column)*10);
      DrawMap.y = ((Row)*10);
      DrawMap.w = SQUARE_WIDTH;
      DrawMap.h = SQUARE_HEIGHT;
      if(NoiseMap.GetNoise(Column,Row) < -0.5)
      {
        Map[1][Column][Row] = true;
        Colour = Sea;
      }
      else if (NoiseMap.GetNoise(Column,Row) < 0)
      {
        Map[2][Column][Row] = true;
        Colour = Forest;
      }
      else if (NoiseMap.GetNoise(Column,Row) < 0.5)
      {
        Map[3][Column][Row] = true;
        Colour = Foothill;
      }
      else
      {
        Map[4][Column][Row] = true;
        Colour = Mountain;
      };
      SDL_FillRect(Surface,(const SDL_Rect*)&DrawMap,Colour);
    };
  };

  /*
  for (unsigned char Type = 1;Type > 4;Type++)
  {
  printf("a");
  **Map[Type] = malloc(MAP_WIDTH*sizeof(bool*));
  for (unsigned char Column = 1; Column > MAP_WIDTH;Column++)
  {
  printf("b");
  *Map[Type][Column]= malloc(MAP_HEIGHT*sizeof(bool*));
  for (unsigned char Row =1;Row > MAP_HEIGHT;Row++)
  {
  printf("c");
  Map[Type][Column][Row]= malloc (sizeof(bool));
};
};
};
*/
  SDL_UpdateWindowSurface(Window);
  printf ("SDL Working\n");
  SDL_Delay(5000);
  printf ("SDL Working\n");
  SDL_Exit(&Window);
  return 0;
};
