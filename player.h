#ifndef player_h
#define player_h


#include <raylib.h>
#include <raymath.h>
#include <stdbool.h>
#include <stdio.h>
#include "gamestd.h"
#include "items.c"

typedef struct Player
{
  Vector2 position;
  Texture2D sprite;
  Size size;
  bool isMoving;
  bool inMenu;
  float speed;
  float hunger;
  Inventory inventory;
  int MainHand;
  int  OffHand;
} Player;


void updatePlayer(Player *player, float delta);
bool isColliding(Rectangle A, Rectangle B);
void renderPlayer(Player *player, Camera2D *camera);
void initPlayer(Player *player);
void playerMovement(Player *player, float delta);
void updateHunger(Player *player, float delta);
void initInventory(Player *player);
void renderInventory(Player player);
void renderHand(Player *player);
void numToInventorySlot(Player *player);
void updateInventory(Player *player);


#endif
