#include "items.h"


Color getItemColor(Item item)
{
  if (item.itemType == 0){
    return BROWN;
  }
  return RED;
}

Entity itemToEntity(Item item,Vector2 position)
{
  return (Entity){item.sprite,ITEM,position};  
}

Item getNullItem()
{
  
  return (Item){NULL_ITEM,LoadTexture(""),RED,(Vector2){0}};

}

Item getBread()
{
  return (Item){CONSUMABLE,LoadTexture("assets/bread.png"),BROWN,(Vector2){0}};
}
