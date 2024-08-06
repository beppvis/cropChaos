#include "items.h"
#include <raylib.h>


Color getItemColor(Item item)
{
  if (item.itemType == 0){
    return BROWN;
  }
  return RED;
}

Item getNullItem()
{
  
  return (Item){NULL_ITEM,LoadTexture("assets/bread.png"),RED,(Rectangle){0}};

}

Item getBread()
{
  return (Item){CONSUMABLE,LoadTexture("assets/bread.png"),BROWN,(Rectangle){0}};
}
