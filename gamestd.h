#include "raylib.h"
#include "raymath.h"
#ifndef game_std_h_
#define game_std_h_

#define DBG_KEY KEY_E
#define ITEM_WORLD_SIZE 20
#define PLAYER_INV_LEN 10

enum ItemTypes
{
  NULL_ITEM,
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
  Vector2 inv_pos;
} Item;

typedef struct Inventory
{
  Item MainSlots[PLAYER_INV_LEN];
  Item item_grabbed;
  bool menu_open;
} Inventory;

Rectangle getRect(Vector2 position,Size size);
bool isInside(int size_A,Vector2 posA ,Vector2 posB);
// Item -> stat up (effect)

#endif
