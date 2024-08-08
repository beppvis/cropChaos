#include "menu.h"
#include "player.h"
#include <raylib.h>
#include <stdio.h>

void playerMenuHandler(Inventory *inv)
{
  if(IsKeyPressed(KEY_Q)&&!inv->menu_open)
  {
    inv->menu_open = true;
  }
  else if(inv->menu_open&& IsKeyPressed(KEY_Q))
  {
    inv->menu_open = false;
  }
}


void renderInventoryMenu(Player *player)
{
  Rectangle menuBox = {player->position.x-250,player->position.y-450,500,800};
  DrawRectanglePro(menuBox, (Vector2){0,0}, 0, (Color){0,0,3,100});

  //rendering layout boxes

  Vector2 pos ={0};

  pos.y = player->position.y;
  int num = 0;
  float offset = GetScreenWidth()/2.5;
  for (int i =0; i < PLAYER_INV_LEN; i++)
  {
    Item *item = &player->inventory.MainSlots[i];
    if(num <PLAYER_INV_LEN/2)
    {
      pos.x = offset + player->position.x - boxSize* (PLAYER_INV_LEN-4);
      pos.x += 50*num;    
      num += 1;
    }

    else
    {
      num = 0 ;
      //arbitary
      pos.y += 60;
    }

    Rectangle inv_rec = getRect(pos,(Size){boxSize,boxSize});
    if (item->itemType != 0)
    {
      Rectangle source_rec = {0,0,item->sprite.width,item->sprite.height};
      DrawTexturePro(item->sprite,source_rec ,inv_rec , (Vector2){0,0}, 0.,WHITE);
    }

    item->inv_pos = pos;

    Rectangle inv_lines_rec = {inv_rec.x+3,inv_rec.y,inv_rec.width,inv_rec.height};
    DrawRectangleLinesEx(inv_lines_rec, 1, WHITE);
  }
}
void inventoryMouseInteraction(Player *player,Camera2D *camera)
{
  Rectangle menuBox = {player->position.x-250,player->position.y-450,500,800};
  Vector2 mousePos = GetScreenToWorld2D( GetMousePosition(),*camera);
  printf("Mouse pos : (%f,%f)\n",mousePos.x,mousePos.y);
  for (int i =0; i < PLAYER_INV_LEN; i++)
  {

    Item item = player->inventory.MainSlots[i];
    if (isInside(boxSize, item.inv_pos,mousePos)&&IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
      player->inventory.item_grabbed = item;
      printf("Grabbed\n");
    }

  }
}

void ItemMouse(Inventory *inventory,Camera2D camera)
{
  Vector2 MousePos = GetScreenToWorld2D(GetMousePosition(),camera);
  if (!inventory->menu_open){return;}
  if (inventory->item_grabbed.itemType == 0){return;}
  Item *item = &inventory->item_grabbed;
  Rectangle source_rec = {0,0,item->sprite.width,item->sprite.height};

  Rectangle dest_rec = {MousePos.x,MousePos.y,50,50};
  
  DrawTexturePro(item->sprite, source_rec,dest_rec , (Vector2){0,0},0,WHITE);
}
