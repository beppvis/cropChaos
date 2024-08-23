

#ifndef world_h

#define world_h
#include "gamestd.h"
#include "entities.c"
#include "tilemap.h"
#include <raylib.h>

void initWorld(World *world);
void initChunk(Chunk *chunk,Texture2D entities_texture);
void initTilemanager(TileManager *tileManager);
void initTilemanager(TileManager *tileManager);

#endif
