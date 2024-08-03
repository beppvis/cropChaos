#include "raylib.h"
#include "raymath.h"
#include "gamestd.h"



Rectangle getRect(Vector2 position,Size size)
{
  return (Rectangle) {position.x,position.y,size.width,size.height};
}



void itemToWorld(Item item)
{
  if (item.itemType ==0 )return;
}


