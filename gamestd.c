#include "gamestd.h"
#include <raylib.h>



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


