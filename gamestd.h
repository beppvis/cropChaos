#include "raylib.h"
#include "raymath.h"
#ifndef game_std_h_
#define game_std_h_
#define DBG_KEY KEY_E

enum ItemTypes
{
  NULL_,
  CONSUMABLE,
  EQUIPMENT,
  NUM_ITEMS,
}ItemTypes;

enum EntityType
{
  NULL_ENTITY,
  BLOCK,
  ENEMY,
  NUM_ENTITIES,
}EntityType;

typedef struct Entity
{
  Texture sprite;
  int entityType;
  Vector2 position;
}Entity;

typedef struct Size
{
  float width;
  float height;
} Size;

typedef struct Vector2i{
  int x;
  int y;
}Vector2i;

typedef struct Item
{
  enum ItemTypes itemType;  
  Color color;
} Item;

Rectangle getRect(Vector2 position,Size size);
Color getItemColor(Item item);
// Item -> stat up (effect)
const Item Bread = {CONSUMABLE,BROWN};
const Item Null = {NULL_,RED}; 

#endif
