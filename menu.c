#include "menu.h"
#include "player.h"
#include <raylib.h>

void playerMenuHandler(Player *player)
{
  if(IsKeyPressed(KEY_Q)&&!player->inMenu)
  {
    player->inMenu = true;
  }
  else if(player->inMenu && IsKeyPressed(KEY_Q))
  {
    player->inMenu = false;
  }
}


void renderInventoryMenu(Player *player)
{
  Rectangle menuBox = {player->position.x-250,player->position.y-450,500,800};
  DrawRectanglePro(menuBox, (Vector2){0,0}, 0, (Color){0,0,3,100});

  //rendering layout boxes

  Vector2 pos ={0};

  Size box_size = {50,50};
  pos.y = player->position.y;
  int num = 0;
  float offset = GetScreenWidth()/2.5;
  for (int i =0; i <= PLAYER_INV_LEN; i++)
  {
    Item item = player->inventory.MainSlots[i];
    if(num <PLAYER_INV_LEN/2)
    {
      pos.x = offset + player->position.x - box_size.width * (PLAYER_INV_LEN-4);
      pos.x += 50*num;    
      num += 1;
    }

    else
    {
      num = 0 ;
      //arbitary
      pos.y += 60;
    }

    Rectangle inv_rec = getRect(pos,box_size);
    if (item.itemType != 0)
    {
      Rectangle source_rec = {0,0,item.sprite.width,item.sprite.height};
      DrawTexturePro(item.sprite,source_rec ,inv_rec , (Vector2){0,0}, 0.,WHITE);

    }
    Rectangle inv_lines_rec = {inv_rec.x+3,inv_rec.y,inv_rec.width,inv_rec.height};
    DrawRectangleLinesEx(inv_lines_rec, 1, WHITE);
  }
  
}
void inventoryMouseInteraction(Player *player)
{
  Rectangle menuBox = {player->position.x-250,player->position.y-450,500,800};
  Vector2 mousePos = GetMousePosition();
  //to be pasted on top not here just for DBG
  if(IsMouseButtonPressed(MOUSE_RIGHT_BUTTON)&&!(CheckCollisionPointRec(mousePos,menuBox)))
  {
    return;
  }

  
  for (int i =0; i <= PLAYER_INV_LEN; i++)
  {
    Item item = player->inventory.MainSlots[i];
    if(num <PLAYER_INV_LEN/2)
    {
      pos.x = offset + player->position.x - box_size.width * (PLAYER_INV_LEN-4);
      pos.x += 50*num;    
      num += 1;
    }

    else
    {
      num = 0 ;
      //arbitary
      pos.y += 60;
    }

    Rectangle inv_rec = getRect(pos,box_size);
    if (item.itemType != 0)
    {
      Rectangle source_rec = {0,0,item.sprite.width,item.sprite.height};
      DrawTexturePro(item.sprite,source_rec ,inv_rec , (Vector2){0,0}, 0.,WHITE);

    }
    Rectangle inv_lines_rec = {inv_rec.x+3,inv_rec.y,inv_rec.width,inv_rec.height};
    DrawRectangleLinesEx(inv_lines_rec, 1, WHITE);
  }


}
