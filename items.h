#include <raylib.h>
#include "gamestd.h"

#ifndef items_h
#define items_h

enum ItemTypes
{
  NULL_,
  CONSUMABLE,
  EQUIPMENT,
  NUM_ITEMS,
}ItemTypes;

typedef struct Item
{
  int itemType;  
  Color color;
} Item;

Color getItemColor(Item item);

const Item Bread = {CONSUMABLE,BROWN};
const Item Null = {NULL_,RED}; 

#endif
