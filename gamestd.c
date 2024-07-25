#include "raylib.h"
#include "raymath.h"
#include "gamestd.h"


Rectangle getRect(Vector2 position,Size size)
{
  return (Rectangle) {position.x,position.y,size.width,size.height};
}

Color getItemColor(Item item)
{
  if (item.itemType == Bread.itemType){
    return BROWN;
  }
  return RED;
}

