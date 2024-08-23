#ifndef tilemap_h
#define tilemap_h
#include "raylib.h"
#include "gamestd.h"
#include "stdio.h"
#include <stdbool.h>
#include "time.h"


//Functions

void placeTile(TileManager *tileManager, Tile *tile );
Vector2i positionToIndex(Vector2 position,TileManager tileManager);
Tile itemToTile(Item item,Vector2 position, TileManager tileManager);
Tile nullTile();
int getNumOfPossibilites(Tile *tile);
void placeTilesInChunks(World *world);
void dumbTiles(TileManager *tileManager,EntityManager *entityManager);
void renderTiles(TileManager *tileManager);
void initTilemanager(TileManager *tileManager);

#endif
