#ifndef item_c 
#define item_c 
#include <game/items.h>
#include <game/gamestd.h>
#include <ray/raylib.h>
#include <stdio.h>

Color getItemColor(Item item)
{
  if (item.itemType == 0){
    return BROWN;
  }
  return RED;
}


// returns an entitiy with an ITEM_ENTITY type
Entity itemToEntity(Item item,Vector2 position)
{
  return (Entity){item.sprite,ITEM_ENTITY,position,item.itemType};  
  
}


Item entityToItem(Entity entity)
{
  return (Item){entity.itemType,entity.itemAttribute,entity.sprite,Vector2Zero()};
}

// adds item to inventory
void addItemToInventory(Item item,Inventory *inv)
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

Item getNullItem()
{
  Item nullItem ;  
  nullItem.itemAttribute = (ItemAttribute){0,0,0};
  nullItem.itemType = NULL_ITEM;
  return nullItem;
}

Item getBread()
{
  Item bread ;  
  bread.itemAttribute = (ItemAttribute){10,0,0};
  bread.itemType = CONSUMABLE;
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
  char path[100];
  getPathTo(path, ASSETS_PATH,"hoe.png");
  hoe.sprite = LoadTexture(path);
  return hoe;
}


#endif
