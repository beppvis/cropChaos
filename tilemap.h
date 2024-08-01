#include "raylib.h"
#include "gamestd.h"
#include "stdio.h"
#include <stdbool.h>
#include "time.h"
#ifndef tilemap_h
#define tilemap_h
#define TILE_MAX_X 20
#define TILE_MAX_Y 20
#define TILE_SIZE 25
#define WATER_MAX 10
#define NUM_OF_TYPES 4



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

//Functions

void placeTile(TileManager *tileManager, Tile *tile );
Tile nullTile();
int getNumOfPossibilites(Tile *tile);
void dumbTiles(TileManager *tileManager,Entity *entities,int *num_entities);
void renderTiles(TileManager *tileManager);
void initTilemanager(TileManager *tileManager);

#endif
