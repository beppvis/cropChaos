#ifndef game_std_h_
#define game_std_h_

#include "../ray/raylib.h"
#include "../ray/raymath.h"
#include "../../src/enums.c" // TODO : If you wanna try and remove this requirement
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

// this init should vary on user settings 
#define INIT_CHUNK_NUM 3 
#define CHUNK_SIZE 20
#define CHUNK_LIMIT_X  (TILE_MAX_X*INIT_CHUNK_NUM)/CHUNK_SIZE
#define CHUNK_LIMIT_Y  (TILE_MAX_Y*INIT_CHUNK_NUM)/CHUNK_SIZE

//LOG FILE name


//LOG FLAGS

#define LOG_ERROR -1
#define LOG_OK 0


const char *ASSETS_PATH = "../assets";


typedef struct 
{
  float width;
  float height;
} Size;

typedef struct {
  int x;
  int y;
}Vector2i;

typedef struct 
{
  float saturation;
  float durabilty;
  float strength;
  int chances_of_spoil;
}ItemAttribute;

typedef struct 
{
  enum ItemTypes itemType;  
  ItemAttribute itemAttribute;
  Texture2D sprite;
  Vector2 inv_pos;
} Item;

typedef struct 
{
  Texture2D sprite;
  enum EntityType entityType;
  Vector2 position;
  enum ItemTypes itemType;
  ItemAttribute itemAttribute;
}Entity;


typedef struct 
{
  Entity Entities[MAX_ENTITIES];
  int num_entites;
}EntityManager;

typedef struct Inventory
{
  Item slots[PLAYER_INV_LEN];
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

typedef struct
{
  TileManager tileManger;
  EntityManager entityManager;
  bool render;
  Vector2i index;
}Chunk ;
  

typedef struct
{

  Chunk Chunks[CHUNK_LIMIT_Y][CHUNK_LIMIT_X];
  Texture2D entityTextures[NUM_ENTITIES];
}World;

typedef struct Player
{
  World  *world; //player world
  Vector2 position; //position
  Texture2D sprite; //sprit
  Size size;//size   
  bool gameOver;//game over
  bool isMoving;//check if player is moving
  enum FacingDirections facing;// facing direction linked to enum
  bool inMenu;
  float speed;
  float hunger;
  Inventory inventory;
  int MainHand;
  int  OffHand;
} Player; 

typedef struct
{
  char* message;
  int value;
}Interaction;






Rectangle getRect(Vector2 position,Size size);
bool isInside(int size_A,Vector2 posA ,Vector2 posB);
bool isColliding(Rectangle rectA, Rectangle rectB);
int flip_h(Rectangle *sourceRect);
int LogIt(char *TAG,char *message, ...);
//THOUGHTS: I kinda think its unnnecesay
int getPathTo(char * out,const char *section_path,const char* file_name);
// (TAG: the property, MESSAGE ):print to screen debugging
int addDebugText(char *TAG,char *message, ...);
int renderDebugText();
// Item -> stat up (effect)

#endif
