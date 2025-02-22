#include "menu.h"
#include "gamestd.h"
#include "player.h"
#include "world.h"
#include <stdint.h>
#include <stdio.h>

void playerMenuHandler(Player *player)
{

  Inventory *inv = &player->inventory;

  if(IsKeyPressed(KEY_Q)&&!inv->menu_open)
  {
    inv->menu_open = true;
    player->inMenu = true;
    return;
  }
  else if(inv->menu_open && IsKeyPressed(KEY_Q))
  {
    inv->menu_open = false;
    player->inMenu = false;
    return;
  }
}


void renderInventoryMenu(Player *player)
{
  //rendering layout boxes

  Vector2 pos ={0};

  pos.y = player->position.y;
  int num = 0;
  float offset = GetScreenWidth()/2. - (PLAYER_INV_LEN/2.3)*50;
  Rectangle menuBox = {offset+player->position.x -boxSize*(PLAYER_INV_LEN-4),player->position.y,boxSize*PLAYER_INV_LEN/2.,110};
  DrawRectanglePro(menuBox, (Vector2){0,0}, 0, (Color){0,0,3,100});
  for (int i =0; i < PLAYER_INV_LEN; i++)
  {
    Item *item = &player->inventory.slots[i];
    if(num < PLAYER_INV_LEN/2)
    {
      pos.x = offset + player->position.x - boxSize* (PLAYER_INV_LEN-4);
      pos.x += boxSize*num;    
      num += 1;
    }

    else
    {
      num = 0 ;
      //arbitary
      pos.y += 60;
    }

    Rectangle inv_rec = getRect(pos,(Size){boxSize,boxSize});

    if (item->itemType != 0 && i != player->inventory.item_grabbed_index)
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
  float offset = GetScreenWidth()/2. - (PLAYER_INV_LEN/2.3)*50;
  Rectangle menuBox = {offset+player->position.x -boxSize*(PLAYER_INV_LEN-4),player->position.y,boxSize*PLAYER_INV_LEN/2.,110};
  Vector2 mousePos = GetScreenToWorld2D( GetMousePosition(),*camera);
  Inventory *inventory = &player->inventory;

  for (int i =0; i < PLAYER_INV_LEN; i++)
  {
    Item item = inventory->slots[i];
    if (isInside(boxSize, item.inv_pos,mousePos)&&IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
      if(inventory->item_grabbed_index != -1)
      {
        //To get the item

        Item grabbed_item = inventory->slots[inventory->item_grabbed_index];
        inventory->slots[inventory->item_grabbed_index] =inventory->slots[i];  
        inventory->slots[i] = grabbed_item;
        inventory->item_grabbed_index = -1;
        return;
      }

      if(item.itemType == 0)return;
      inventory->item_grabbed_index = i;
      return;
    }
    else if (!(CheckCollisionPointRec(mousePos,menuBox )))
    {
      //item is   
      if (inventory->item_grabbed_index != -1)
      {
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
          fprintf(stdout,"[PLAYER] Item dropped\n"); 
          Entity dropped_item_entity = itemToEntity(inventory->slots[inventory->item_grabbed_index], player->position);
          spawnEntityInWorld(player->world, &dropped_item_entity);
          inventory->slots[inventory->item_grabbed_index] =getNullItem() ;
          return;
        }
      }
    }

  }
}


void ItemMouse(Inventory *inventory,Camera2D camera)
{

  Vector2 MousePos = GetScreenToWorld2D(GetMousePosition(),camera);
  if (inventory->item_grabbed_index  == -1){return;}
  Item item  = inventory->slots[inventory->item_grabbed_index];
  if (!inventory->menu_open){return;}
  if (item.itemType == 0){return;}

  Rectangle source_rec = {0,0,item.sprite.width,item.sprite.height};

  Rectangle dest_rec = {MousePos.x,MousePos.y,50,50};
  
  DrawTexturePro(item.sprite, source_rec,dest_rec , (Vector2){0,0},0,WHITE);

}



