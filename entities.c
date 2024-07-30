#include <stdio.h>
#include "entities.h"

const char *file_paths[NUM_ENTITIES] = {"assets/grass.png"};



void loadTextureEntities(Texture2D *entities_texture)
{
  for (int i =0;i<NUM_ENTITIES;i++)
  {
    if (i == 0)continue;
    *entities_texture = LoadTexture(file_paths[i-1]);
    entities_texture ++;
  }
}

void initEntities(Entity *entities,int num,Texture2D entities_text[NUM_ENTITIES])
{
    for (int i =0 ; i<num; i++)
    {
      if (!entities->entityType){printf("NULL entity");entities++;continue;}
      entities->sprite = entities_text[entities->entityType -1];
      entities++;
    }
}

void renderEntities(Entity *entities,int num)
{
  for (int i =0 ; i<num; i++)
  {
    DrawTexture(entities->sprite,entities->position.x, entities->position.y,WHITE);
    entities ++;
  }
}
