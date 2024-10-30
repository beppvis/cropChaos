#include "items.h"
#include "gamestd.h"
#include <raylib.h>
#include <stdio.h>

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
    Item inv_item = inv->slots[i];
    if (inv_item.itemType == 0)
    {
      inv->slots[i] = item;
      return;
    }
  }
}

void removeItem(Inventory *inv,int slot_num)
{
  inv->slots[slot_num] = getNullItem();
}
// Tile itemToTile(Item item,Vector2 position)
// {
//   return (Tile){}
// }


Item getNullItem()
{
  Item nullItem ;  
  nullItem.itemAttribute = (ItemAttribute){0,0,0};
  nullItem.itemType = NULL_ITEM;
  nullItem.color = RED;

  return nullItem;
}

Item getBread()
{
  Item bread ;  
  bread.itemAttribute = (ItemAttribute){10,0,0};
  bread.itemType = CONSUMABLE;
  bread.color = BROWN;
  bread.itemAttribute.chances_of_spoil = 10;
  char path[100];
  getPathTo(path, ASSETS_PATH,"bread.png");
  bread.sprite = LoadTexture(path);
  return bread;
}


Item getHoe()
{
  Item hoe;  
  hoe.itemAttribute = (ItemAttribute){10,0,0};
  hoe.itemType = EQUIPMENT;
  hoe.color = WHITE;
  char path[100];
  getPathTo(path, ASSETS_PATH,"hoe.png");
  hoe.sprite = LoadTexture(path);
  return hoe;
}


