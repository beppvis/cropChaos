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

void itemToInvetory(Item item,Inventory *inv)
{
  for (int i =0 ; i < PLAYER_INV_LEN; i++)
  {
    Item inv_item = inv->MainSlots[i];
    if (inv_item.itemType == 0)
    {
      inv->MainSlots[i] = item;
      return;
    }
  }
}

Item getNullItem()
{
  
  return (Item){NULL_ITEM,LoadTexture(""),RED,(Vector2){0}};

}

Item getBread()
{
  return (Item){CONSUMABLE,LoadTexture("assets/bread.png"),BROWN,(Vector2){0}};
}
