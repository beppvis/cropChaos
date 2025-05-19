

#ifndef world_h
#define world_h
#include "gamestd.h"
#include "tilemap.h"

void initWorld(World *world);
void initChunk(Chunk *chunk,Vector2i chunk_index,Texture2D *entities_texture);
void initTilemanager(Chunk *chunk);
Chunk* getChunkWithIndex(World *world, Vector2i index);
void spawnEntityInWorld(World *world,Entity *entity);
Vector2i getChunkIndex(World *world,Vector2 Position);
void renderChunkDebug(Chunk *chunk);
void updateChunk(Chunk *chunk, Player *player);
void updateWorld(World *world,Player *player);


#endif
