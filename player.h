#ifndef player_h
#define player_h

#include "raylib.h"
#include "gamestd.h"
#include "items.c"

typedef struct Player
{
  Vector2 position;
  Texture2D sprite;
  Size size;
  bool isMoving;
  float speed;
  float hunger;
  Inventory inventory;
} Player;


void updatePlayer(Player *player, float delta);
bool isColliding(Rectangle A, Rectangle B);
void renderPlayer(Player *player, Camera2D *camera);
void initPlayer(Player *player);
void playerMovement(Player *player, float delta);
void updateHunger(Player *player, float delta);


#endif
