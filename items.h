#include <raylib.h>
#include "gamestd.h"

#ifndef items_h
#define items_h


Color getItemColor(Item item);
Entity itemToEntity(Item item,Vector2 position);
void itemToInvetory(Item item,Inventory *inv);
void consumeItem(Item item);


#endif
