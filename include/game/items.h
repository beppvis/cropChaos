#include "../ray/raylib.h"
#include "gamestd.h"

#ifndef items_h
#define items_h


Color getItemColor(Item item);
Item getNullItem();
Entity itemToEntity(Item item,Vector2 position);
void addItemToInventory(Item item,Inventory *inv);


#endif
