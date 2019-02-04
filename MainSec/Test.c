#include "stdio.h"
#include "stdlib.h"

void main()
{
  FILE* MapReader;
  MapReader = fopen("./Res/map.txt","r");
  char Size[5];
  fscanf (MapReader,"%s",Size);
  printf ("%s\n",Size);
  printf ("%c",Size[0]);
  printf ("%c\n",Size[1]);
  printf ("%c",Size[2]);
  printf ("%c\n",Size[3]);
  printf("%d\n",((Size[0]-'0')*10)+(Size[1]-'0'));
  printf("%d\n",((Size[2]-'0')*10)+(Size[3]-'0'));
  int MapHeight = ((Size[0]-'0')*10)+(Size[1]-'0');
  int MapWidth = ((Size[2]-'0')*10)+(Size[3]-'0');
  printf("%d",MapHeight);
  printf("%d\n",MapWidth);
  unsigned char** Map;
  Map = malloc ((MapHeight+1)*sizeof(unsigned char*));
  for (unsigned char x = 1;x<MapHeight+1;x++ )
  {
    Map[x] = malloc((MapWidth+1)*sizeof(unsigned char*));
  };
  for (unsigned char x = 1;x<MapHeight+1;x++)
  {
    for (unsigned char y = 1 ;y<MapWidth+1;y++)
    {
      printf("%d:%d\n",x,y);
      Map[x][y]=54;
    };
  };
  for (unsigned char x = 1;(x<MapHeight+1);x++)
  {
    for (unsigned char y = 1 ;(y<MapWidth+1);y++)
    {
      printf("%d\n",Map[x][y]);
    };
  };
};
