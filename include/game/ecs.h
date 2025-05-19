#include <ray/raylib.h>
#include <stddef.h>
#include "gamestd.h"
#include "items.h"

typedef struct {
  size_t id;
  Texture2D sprite;
  Vector2 position;
} ECS_Entity;
typedef struct {
  size_t id;
  enum ItemTypes itemType;
  ItemAttribute itemAttribute;
  Vector2 inv_pos;
} ECS_Item;

typedef struct {
  ECS_Item *items; 
  size_t no_items;
} ECS_Items_Table;

typedef struct {
  ECS_Entity *entities;
  size_t no_entities; 
  ECS_Items_Table itemTable;
} ECS_World;


ECS_World InitWorld();
int destroyWorld(ECS_World *world);

size_t CreateEntity(ECS_World *world,char* texutre_path,Vector2 position);
int destroyEntity(ECS_World *world,size_t entityID);
size_t CreateItem(ECS_Items_Table *table,enum ItemTypes itemType ,Vector2 inv_position);
int destroyItem(ECS_World *world,size_t itemID);




