#include "raylib.h"
#include "raymath.h"
#ifndef game_std_h_
#define game_std_h_

#define DBG_KEY KEY_E
#define ITEM_WORLD_SIZE 20
#define PLAYER_INV_LEN 10

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
  Texture2D sprite;
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
  Texture2D sprite;
  Color color;
} Item;

typedef struct Inventory
{
  Item MainSlots[PLAYER_INV_LEN];
} Inventory;

Rectangle getRect(Vector2 position,Size size);
// Item -> stat up (effect)

#endif
