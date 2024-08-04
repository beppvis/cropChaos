#include "items.h"
#include <raylib.h>


Color getItemColor(Item item)
{
  if (item.itemType == 0){
    return BROWN;
  }
  return RED;
}


Item getBread()
{
  return (Item){CONSUMABLE,LoadTexture("assets/bread.png"),BROWN};
}
