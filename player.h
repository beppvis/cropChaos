#include "raylib.h"
#include "gamestd.h"
#ifndef player_h
#define player_h
typedef struct Player
{
  Vector2 position;
  Texture2D sprite;
  Size size;
  bool isMoving;
  float speed;
  float hunger;
  Item item;
} Player;


void updatePlayer(Player *player, float delta);
bool isColliding(Rectangle A, Rectangle B);
void renderPlayer(Player *player, Camera2D *camera);
void initPlayer(Player *player);
void playerMovement(Player *player, float delta);
void updateHunger(Player *player, float delta);


#endif
