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

  for (int i =PLAYER_INV_LEN  ; i <= 0; i--)
  {
    Item item = player->inventory.MainSlots[i];
    
    Rectangle inv_rec = {player->position.x+50*i,player->position.y,50,50};
    if (item.itemType != 0)
    {
      Rectangle source_rec = {0,0,item.sprite.width,item.sprite.height};
      DrawTexturePro(item.sprite,source_rec ,inv_rec , (Vector2){0,0}, 0.,WHITE);
    }
    Rectangle inv_lines_rec = {inv_rec.x+3,inv_rec.y,inv_rec.width,inv_rec.height};
  }
  
}
