#include "player.h"
#include "gamestd.h"
#include "menu.c"
#include <raylib.h>
#include <stdio.h>
#define CAM_LIM 2  
#define CAM_LIM_MAX 160
#define MIN_HUNGER_TICK  0.001


void updatePlayer(Player *player ,float delta)
{

  playerInputHandler(player, delta);
  updateInventory(player);
  updateHunger(player, delta);

}


void playerInputHandler(Player *player,float delta)
{
  playerMovement(player,delta);
  // TODO : Might be BUG PRONE
  if (GetKeyPressed() != 0)
  {
    playerMenuHandler(&player->inventory);
  }
  if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)&&!player->inventory.menu_open)
  {

  }
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

void useItem(Player *player)
{
  switch (ItemTypes)
  {
    
  }
}

void updateInventory(Player *player)
{
  numToInventorySlot(player);
}

void numToInventorySlot(Player *player)
{
  if(player->inventory.menu_open)return;
  switch(GetKeyPressed())
  {
    case KEY_ONE:
      player->MainHand = 0;
      break;
    case KEY_TWO:
      player->MainHand = 1;
      break;
    case KEY_THREE:
      player->MainHand = 2;
      break;
    case KEY_FOUR:
      player->MainHand = 3;
      break;
  }
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
  Vector2 diff =Vector2Subtract(player->position,camera->target);
  renderHand(player);
  if (player->inventory.menu_open)
  { 
    renderInventoryMenu(player);
    inventoryMouseInteraction(player,camera);
    ItemMouse(&player->inventory,*camera);
  }
}


void renderHand(Player *player)
{
  Item item = player->inventory.MainSlots[player->MainHand];
  if(item.itemType != 0)
  {
    Rectangle source_rec = {0,0,item.sprite.width,item.sprite.height};
    Rectangle dest_rec = {player->position.x,player->position.y+20,30,30};
    DrawTexturePro(item.sprite,source_rec ,dest_rec ,(Vector2){0,0} ,0 ,WHITE);    

  }

}

void renderHUD(Player *player)
{
  char s[50];
  sprintf(s,"Hunger : %f" ,player->hunger);
  DrawTextPro(GetFontDefault(),s,(Vector2){10,10}, (Vector2){0,0}, 0, 40, 2,WHITE );
  renderInventory(*player);
}


void renderInventory(Player player)
{
  Inventory inv = player.inventory;
  for (int i = 0; i < 4; i++)
  {
    Item item = inv.MainSlots[i];
    Rectangle inv_rec = {GetScreenWidth()/3.+50*i,GetScreenHeight()-100,50,50};
    if (item.itemType != 0)
    {
      Rectangle source_rec = {0,0,item.sprite.width,item.sprite.height};
      DrawTexturePro(item.sprite,source_rec ,inv_rec , (Vector2){0,0}, 0.,WHITE);
    }
    Rectangle inv_lines_rec = {inv_rec.x+3,inv_rec.y,inv_rec.width,inv_rec.height};
    if (i == player.MainHand)
    {
      DrawRectangleLinesEx(inv_lines_rec,3 ,BLUE);
      continue;
    }
    DrawRectangleLinesEx(inv_lines_rec,3 ,WHITE );
  }

}

void initPlayer(Player *player)
{
  Texture2D playerSprite = LoadTexture("./assets/player.png");
  player->sprite = playerSprite;
  player->position = (Vector2){0,0};
  player->speed = 600.;
  player->size = (Size){100,100};
  player->hunger = 0.00;
  initInventory(player);
}

void cameraFollow(Camera2D *camera,Player *player,float delta,Size screen_size)
{

  static float minSpeed = 90;
  static float minEffectLength = 10;
  static float fractionSpeed = 1.0f;
  camera->offset = (Vector2){screen_size.width/2.0f,screen_size.height/2.0f};

  Vector2 diff= Vector2Subtract(player->position,camera->target);
  float diff_length = Vector2Length(diff);
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


void initInventory(Player *player)
{
  for (int i = 0; i < PLAYER_INV_LEN ; i++)
  {
    if ( i ==2)
    {
      player->inventory.MainSlots[i] = getBread();
    }
    else
    {
      player->inventory.MainSlots[i] = getNullItem();
    }
  }
  //Assuming its not null
  player->inventory.menu_open = false;
  player->inventory.item_grabbed_index = -1;
  player->MainHand = 0;
  player->OffHand = 1;
}
