
#ifndef menu_h 
#define menu_h

#include <raylib.h>
#include "player.h"
#include "gamestd.h"

#define boxOffset 150
#define boxSize 50

void playerMenuHandler(Inventory *inv);
void renderInventoryMenu(Player *player);
void inventoryMouseInteraction(Player *player,Camera2D *camera);
void ItemMouse(Inventory *inventory,Camera2D camera);

#endif
