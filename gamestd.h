#ifndef game_std_h_
#define game_std_h_

#include "raylib.h"
#include "raymath.h"
#include "stdio.h"

#define DBG_KEY KEY_E
#define ITEM_WORLD_SIZE 20
#define PLAYER_INV_LEN 10

#define TILE_MAX_X 20
#define TILE_MAX_Y 20
#define TILE_SIZE 50
#define WATER_MAX 10
#define NUM_OF_TYPES 4

// In a chunk
#define MAX_ENTITIES  100

#define CHUNK_SIZE 5
#define CHUNK_LIMIT_X TILE_MAX_Y/CHUNK_SIZE
#define CHUNK_LIMIT_Y TILE_MAX_X/CHUNK_SIZE

//LOG FILE name


//LOG FLAGS

#define LOG_ERROR -1
#define LOG_OK 0

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
  ITEM,
  ENEMY,
  NUM_ENTITIES,
}EntityType;

enum TerrainTypes{
  DIRT,// 0
  GRASS,// 1
  WATER,// 2
  SAND,// 3
  PLAYER_TILE,
  EMPTY,
  NULL_TILE,
} TerrainTypes;

typedef struct Entity
{
  Texture2D sprite;
  int entityType;
  Vector2 position;
}Entity;


typedef struct EntityManager
{
  Entity Entities[MAX_ENTITIES];
  int num_entites;
}EntityManager;

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
  int item_grabbed_index;
  bool menu_open;
} Inventory;

typedef struct Tile{
  Vector2i index;
  Vector2 position;
  int terrainType;
  Color color;
  bool possibilites[NUM_OF_TYPES];
}Tile;

typedef struct TileManager{
  Tile tiles[TILE_MAX_Y][TILE_MAX_X];
}TileManager;

typedef struct Player
{
  Vector2 position;
  Texture2D sprite;
  Size size;
  bool isMoving;
  bool inMenu;
  float speed;
  float hunger;
  Inventory inventory;
  int MainHand;
  int  OffHand;
} Player;



typedef struct
{
  TileManager tileManger;
  EntityManager entitiyManager;
  bool render;
  Vector2i index;
}Chunk ;

  

typedef struct
{

  Chunk Chunks[CHUNK_LIMIT_Y][CHUNK_LIMIT_X];
  Player player;
  Texture2D entitiyTextures[NUM_ENTITIES];
}World;

Rectangle getRect(Vector2 position,Size size);
bool isInside(int size_A,Vector2 posA ,Vector2 posB);
// Item -> stat up (effect)

#endif
