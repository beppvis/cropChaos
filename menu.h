
#ifndef menu_h 
#define menu_h

#include <raylib.h>
#include "player.h"
#include "gamestd.h"

#define boxOffset 150

void playerMenuHandler(Player *player);
void renderInventoryMenu(Player *player);
void inventoryMouseInteraction(Player *player,Camera2D *camera);

#endif
