#include "ecs.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

/*
  returns ECS_WORLD 
  with 100 entities
  and 100 items 
  */
ECS_World createWorld()
{
  return (ECS_World) {
    .entities = malloc(sizeof(ECS_Entity)*100), // 100 entities
    .no_entities = 100,
    .itemTable = (ECS_Items_Table){
      .items = malloc(sizeof(ECS_Item)*100), // 100 items
      .no_items = 100 
    }
  };
}

/*
  * returns entity ID (size_t)
  */
size_t createEntity(ECS_World *world,char* texutre_path,Vector2 position)
{
  size_t prev_id = 0;
  size_t id ;
  for (int i = 0 ; i < world->no_entities ; i++)
  {
    if (world->entities[i].id)
    {
      prev_id = world->entities[i].id;
      continue;
    }
    id = prev_id+1;
    world->entities[i] = (ECS_Entity){
      id,
      LoadTexture(texutre_path),
      position,
    };
    break;
  }
  return id;
}

int destroyEntity(ECS_World *world,size_t entityId){
  for (size_t i = 0 ; i < world -> no_entities ; i ++ ){
    if(i==entityId){
      world->entities[i]= (ECS_Entity){};
      fprintf(stdout,"[ENTITY]: Destroyed entity ID : %lu\n",i);
      return 0;
    }
  }
  return -1;
}

size_t createItem(ECS_Items_Table *itemTable,enum ItemTypes itemType ,Vector2 inv_position){
  size_t prev_id = 0;
  size_t id = 0;
  for (int i = 0 ; i < itemTable->no_items ; i++){
   if (itemTable->items[i].id)
    {
      prev_id = itemTable->items[i].id;
      continue;
    }
    id = prev_id+1;
    itemTable->items[i] = (ECS_Item){
      id,
    };
    break; 
  }
  return id;
}

int destroyItem(ECS_World *world,size_t itemId){
  for (size_t i = 0 ; i < world ->itemTable.no_items ; i ++ ){
    if(i==itemId){
      world->itemTable.items[i]= (ECS_Item){};
      fprintf(stdout,"[ITEM]: Destroyed item ID : %lu \n",i);
      return 0;
    }
  }
  return -1;
}

int destroyWorld(ECS_World *world){
  free(world->entities);
  free(world->itemTable.items);
  return  0;
}


