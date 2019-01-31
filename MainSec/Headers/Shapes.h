#ifndef  _SHAPES_H_
#define  _SHAPES_H_
struct Point;
struct Spots_Hex;
struct SDL_Hexagon;
SDL_Hexagon Create_Hexagon(Point Center , Point Radius);
SDL_Hexagon Move_Hexagon(SDL_Hexagon Old , Point New);
int Draw_FillHexagon(SDL_Hexagon);
#endif
