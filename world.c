#include "world.h"

void initWorld(World *world)
{
  Texture2D entities_texture;
  loadTextureEntities(&entities_texture);
  world->entitiyTextures = entities_texture;
  for (int c_y = 0; c_y < CHUNK_LIMIT_Y;c_y ++)
  {
    for (int c_x = 0; c_x < CHUNK_LIMIT_X;c_x ++)
    {
      initChunk(&world->Chunks[c_y][c_x],world->entitiyTextures);
    }
  }
}

void initChunk(Chunk *chunk,Texture2D entities_texture)
{
  TileManager tileManager;
  initTilemanager(&tileManager);
  EntityManager entityManager;
  initEntityManager(&entityManager,entities_texture);
}

void initTilemanager(TileManager *tileManager)
{
  int i = 0 ;
  for (int y = 0; y<TILE_MAX_Y; y ++)
  {
    for (int x = 0; x<TILE_MAX_X; x ++)
    {
        Tile tile = {
          .index= (Vector2i){x,y},
          .position = (Vector2){x*50,y*50},
          .terrainType = NULL_TILE,
          .possibilites = {1,1,1,1},
        };
        tileManager->tiles[y][x]= tile;
        i ++;
    }
  }
}

