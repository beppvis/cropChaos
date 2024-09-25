#include "gamestd.h"



Rectangle getRect(Vector2 position,Size size)
{
  return (Rectangle) {position.x,position.y,size.width,size.height};
}

bool isInside(int size_A,Vector2 posA,Vector2 posB)
{
  if ((posB.x <= (size_A + posA.x) && posB.y <= (size_A + posA.y))&&(posB.x > posA.x &&posB.y > posA.y))
  {
    return true;
  }
  return false;
}

int flip_h(Rectangle *sourceRect)
{
  sourceRect->x = sourceRect->x * -1;
  return 0;
}


void LogIt(char *string, int buff_size,int flag)
{  
  //TODO : create more
}

