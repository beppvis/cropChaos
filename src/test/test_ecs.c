#include "../ecs.c"
#include <stdio.h>


int main(){

  ECS_World world = createWorld();
  size_t entityID = createEntity(&world, "../../assets/hoe.png", (Vector2){10,10});
  size_t itemID = createItem(&world.itemTable,EQUIPMENT, (Vector2){1,0});
  createItem(&world.itemTable,EQUIPMENT, (Vector2){1,0});
  createItem(&world.itemTable,EQUIPMENT, (Vector2){1,0});
  createItem(&world.itemTable,EQUIPMENT, (Vector2){1,0});
  createItem(&world.itemTable,EQUIPMENT, (Vector2){1,0});
  itemID = createItem(&world.itemTable,EQUIPMENT, (Vector2){1,0});
  int out = destroyItem(&world, itemID);
  if (out){
    printf("Oh no\n");
  }
  itemID = createItem(&world.itemTable,EQUIPMENT, (Vector2){1,0});
  out = destroyItem(&world, itemID);
  if (out){
    printf("Oh no\n");
  }
 
}
