#include <raylib.h>
#include <stdio.h>
#include "entities.h"
#include "entities.h"

const char *file_paths[NUM_ENTITIES] = {"","assets/grass.png",""};


void loadTextureEntities(Texture2D *entities_texture)
{
  for (int i =0;i<NUM_ENTITIES;i++)
  {

    *entities_texture = LoadTexture(file_paths[i]);
    printf("Loaded one Txt\n");
    entities_texture ++;

  }
}

void initEntities(Entity *entities,int num,Texture2D entities_text[NUM_ENTITIES])
{
  for (int i = 0 ; i < num; i++)
  {
    if (entities->entityType==0)
    {
      printf("NULL entity\n");
      printf("Pos : %f,%f\n",entities->position.x,entities->position.y);
      entities++;
      continue;
    }
    entities->sprite = entities_text[entities->entityType];
    entities++;
  }
}

void renderEntities(Entity *entities,int num)
{
  for (int i =0 ; i<num; i++)
  {
    // printf("I am rendering %f,%f\n",entities->position.x,entities->position.y);
    Rectangle sourceRec = getRect((Vector2){0,0},(Size){entities->sprite.width,entities->sprite.height} );
    Rectangle destRec = getRect((Vector2){entities->position.x*TILE_SIZE,entities->position.y*TILE_SIZE},(Size){TILE_SIZE,TILE_SIZE});
    Texture2D spirte = entities->sprite;
    DrawTexturePro(spirte,sourceRec,destRec,(Vector2){0,0},0,WHITE);
    entities ++;
  }
}
