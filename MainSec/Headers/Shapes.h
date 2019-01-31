#ifndef  _SHAPES_H_
#define  _SHAPES_H_
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

SDL_Hexagon Create_Hexagon(Point Center , Point Radius);
SDL_Hexagon Move_Hexagon(SDL_Hexagon Old , Point New);
int Draw_FillHexagon(SDL_Hexagon Hex ,SDL_Surface **Surface);
#endif
