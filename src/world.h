

#ifndef world_h

#define world_h
#include "gamestd.h"
#include "entities.c"
#include "tilemap.h"

void initWorld(World *world);
void initChunk(Chunk *chunk,Vector2i chunk_index,Texture2D *entities_texture);
void initTilemanager(Chunk *chunk);
Chunk getChunkWithPos(World *world, Vector2 position);
void spawnEntity(World *world,Entity *entity);

#endif
