
#ifndef menu_h 
#define menu_h

#include <raylib.h>

#include "gamestd.h"
#include "player.h"
#define boxOffset 150

void playerMenuHandler(Player *player);
void renderInventoryMenu(Player *player);
void inventoryMouseInteraction(Player *player);

#endif
