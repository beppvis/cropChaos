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
void dumbTiles(TileManager *tileManager,Entity *entities,int *num_entities);
void renderTiles(TileManager *tileManager);
void initTilemanager(TileManager *tileManager);

#endif
