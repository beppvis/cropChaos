#ifndef player_h
#define player_h


#include "../include/raylib.h"
#include "../include/raymath.h"
#include <stdbool.h>
#include <stdio.h>
#include "gamestd.h"
#include "items.c"

void updatePlayer(Player *player, float delta);
bool isColliding(Rectangle A, Rectangle B);
void renderPlayer(Player *player, Camera2D *camera);
void initPlayer(Player *player,World *world);
void playerMovement(Player *player, float delta);
void playerInputHandler(Player *player,float delta);
void useItem(Player *player);
void consumeItem(Item *item,int inv_index,Player *player);
void updateHunger(Player *player, float delta);
char* getPlayerDebugInfo(Player *player);
Interaction* getInteraction(Player *player,int N); // N being the number of interactions
void initInventory(Player *player);
void renderInventory(Player player);
void renderHand(Player *player);
// key - > key code
void numToInventorySlot(Player *player,int key);
void updateInventory(Player *player);


#endif
