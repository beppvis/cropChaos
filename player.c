#include "player.h"
#include <raylib.h>
#include <raymath.h>
#include <stdio.h>
#include <math.h>

#define CAM_LIM 2  
#define CAM_LIM_MAX 160
#define MIN_HUNGER_TICK  1


void updatePlayer(Player *player ,float delta)
{
  playerMovement(player,delta);
  updateHunger(player, delta);
}


void playerMovement(Player *player,float delta)
{
  float speed = player->speed;
  player->isMoving = true;
  if(IsKeyDown(KEY_W)){player->position.y -= speed*delta;}

  else if(IsKeyDown(KEY_S)){player->position.y += speed*delta;}

  else if(IsKeyDown(KEY_A)){player->position.x -= speed*delta;}

  else if(IsKeyDown(KEY_D)){player->position.x += speed*delta;}

  else player->isMoving = false;
}

void updateHunger(Player *player, float delta)
{
  if (player->isMoving)
  {
    player->hunger += MIN_HUNGER_TICK *delta*(player->speed/150);
  }
  else
    player->hunger += MIN_HUNGER_TICK *delta;

}


bool isColliding(Rectangle A, Rectangle B)
{
  return CheckCollisionRecs(A,B);
}

void renderPlayer(Player *player, Camera2D *camera)
{
  //Body
  // Rectangle sourceRec = {0,0,(player->sprite.width/(16.0f)),player->sprite.height/(10.0f)};
  // sourceRec.x = 5.0f*(player->sprite.width/(16.0f));
  Rectangle sourceRec = {0,0,player->sprite.width,player->sprite.height};
  DrawTexturePro(player->sprite, sourceRec, getRect(player->position,player->size ),(Vector2){0,0} ,0,WHITE );
  //Item
  char s[50];
  sprintf(s,"Hunger : %f" ,player->hunger);
  Vector2 diff =Vector2Subtract(player->position,camera->target);
  DrawTextPro(GetFontDefault(),s,(Vector2){GetScreenWidth(),GetScreenHeight()}, player->position, 0, 10, 2,WHITE );
  if (!player->item.itemType)return;
  Vector2 itemPosition = {player->position.x+50,player->position.y+10};
  DrawRectangleRec(getRect(itemPosition,(Size){40,40} ),getItemColor(player->item));
}

void initPlayer(Player *player)
{
  Texture2D playerSprite = LoadTexture("./assets/player.png");
  player->sprite = playerSprite;
  player->position = (Vector2){0,0};
  player->speed = 600.;
  player->size = (Size){100,100};
  player->item = Bread;
  player->hunger = 0.00;
  
}

void renderHunger(Player *player)
{
}
void cameraFollow(Camera2D *camera,Player *player,float delta,Size screen_size)
{

  static float minSpeed = 90;
  static float minEffectLength = 10;
  static float fractionSpeed = 1.0f;
  camera->offset = (Vector2){screen_size.width/2.0f,screen_size.height/2.0f};

  Vector2 diff= Vector2Subtract(player->position,camera->target);
  float diff_length = Vector2Length(diff);
  printf("Cam dist : %f\n",diff_length);
  // if (diff_length > CAM_LIM)
  // {
  //   float speed = fmaxf(fractionSpeed*diff_length,minSpeed);
  //   camera->target = Vector2Add(camera->target,Vector2Scale(diff,(speed*delta)/diff_length));
  // }
  camera->target = player->position;
  // if (diff_length > CAM_LIM_MAX)
  // {

  //   camera->target= Vector2Add(camera->target,Vector2Scale(diff,delta));
  // }
}
