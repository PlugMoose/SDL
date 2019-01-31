#include "SDL.h"

typedef struct
{
  unsigned short x;
  unsigned short y;
}Point;

typedef struct
{
  Point One;
  Point Two;
  Point Three;
  Point Four;
  Point Five;
  Point Six;
}Spots_Hex;

typedef struct
{
  Point Center;
  unsigned int Radius;
  Spots_Hex Points;
}SDL_Hexagon;

SDL_Hexagon Create_Hexagon(Point Center , unsigned int Radius)//config 1
{
  SDL_Hexagon INTER_Hexagon;
  INTER_Hexagon.Center = Center;
  INTER_Hexagon.Radius = Radius;
  INTER_Hexagon.Points.One.x = Center.x - Radius;
  INTER_Hexagon.Points.One.y = Center.y ;
  INTER_Hexagon.Points.Two.x = Center.x - Radius/2;
  INTER_Hexagon.Points.Two.y = Center.y + Radius;
  INTER_Hexagon.Points.Three.x = Center.x + Radius/2;
  INTER_Hexagon.Points.Three.y = Center.y + Radius;
  INTER_Hexagon.Points.Four.x = Center.x + Radius;
  INTER_Hexagon.Points.Four.y = Center.y;
  INTER_Hexagon.Points.Five.x = Center.x + Radius/2;
  INTER_Hexagon.Points.Five.y = Center.y- Radius;
  INTER_Hexagon.Points.Six.x = Center.x - Radius/2;
  INTER_Hexagon.Points.Six.y = Center.y - Radius;
  return INTER_Hexagon;
};

SDL_Hexagon Move_Hexagon(SDL_Hexagon OldHexagon , Point NewCenter)
{
  SDL_Hexagon INTER_Hexagon = OldHexagon;
  INTER_Hexagon.Center = OldHexagon.Center;
  INTER_Hexagon.Points.One.x = OldHexagon.Center.x - OldHexagon.Radius;
  INTER_Hexagon.Points.One.y = OldHexagon.Center.y ;
  INTER_Hexagon.Points.Two.x = OldHexagon.Center.x - OldHexagon.Radius/2;
  INTER_Hexagon.Points.Two.y = OldHexagon.Center.y + OldHexagon.Radius;
  INTER_Hexagon.Points.Three.x = OldHexagon.Center.x + OldHexagon.Radius/2;
  INTER_Hexagon.Points.Three.y = OldHexagon.Center.y + OldHexagon.Radius;
  INTER_Hexagon.Points.Four.x = OldHexagon.Center.x + OldHexagon.Radius;
  INTER_Hexagon.Points.Four.y = OldHexagon.Center.y;
  INTER_Hexagon.Points.Five.x = OldHexagon.Center.x + OldHexagon.Radius/2;
  INTER_Hexagon.Points.Five.y = OldHexagon.Center.y- OldHexagon.Radius;
  INTER_Hexagon.Points.Six.x = OldHexagon.Center.x - OldHexagon.Radius/2;
  INTER_Hexagon.Points.Six.y = OldHexagon.Center.y - OldHexagon.Radius;
  return INTER_Hexagon;
};
int Draw_FillHexagon(SDL_Hexagon Hex ,SDL_Surface **Surface)
{
  //SDL_FillRect (Surface, NULL, SDL_MapRGB(Surface->format,0xAA,0xFF,0xFF));
  int RETURN_VALUE = 0;
  return RETURN_VALUE;
};
