#include "world.h"
#include <stdio.h>
#include <time.h>



void initWorld(World *world)
{
  clock_t begin = clock();
  Texture2D entities_texture[NUM_ENTITIES];
  loadTextureEntities(&world->entitiyTextures[0]);
  for (int c_y = 0; c_y < CHUNK_LIMIT_Y;c_y ++)
  {
    for (int c_x = 0; c_x < CHUNK_LIMIT_X;c_x ++)
    {
      printf("INIT Chunk (%d,%d) STARTED\n",c_y,c_x);

      Vector2i chunk_index = {c_x,c_y};
      Chunk *chunk = &world->Chunks[chunk_index.y][chunk_index.x]; 
      initChunk(chunk,chunk_index,world->entitiyTextures);
      placeTilesInChunk(chunk);

      printf("INIT Chunk (%d,%d) FINISHED \n",c_y,c_x);

    }
  }
  clock_t end = clock();
  double time_spent = (double)(end-begin)/CLOCKS_PER_SEC;
  printf("Total INIT time taken : %f\n",time_spent);
}

void initChunk(Chunk *chunk,Vector2i chunk_index,Texture2D *entities_texture)
{
  static int init_num = 0 ;
  init_num ++;
  printf("INIT %d : STARTED\n",init_num);
  chunk->index = chunk_index;
  initTilemanager(chunk);
  initEntityManager(chunk,entities_texture);
  printf("INIT %d : FINISHED\n",init_num);
}

void initTilemanager(Chunk *chunk)
{
  TileManager *tileManager = &chunk->tileManger;
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


void renderChunk(Chunk *chunk)
{
  renderTiles(&chunk->tileManger); 
  int static render_nums =  0; 
  if  (render_nums < 1){
      renderEntities(&chunk->entitiyManager);
      render_nums++;
  }
}

void renderWorld(World *world)
{
  clock_t begin = clock();
  for (int c_y = 0; c_y < CHUNK_LIMIT_Y;c_y ++)
  {
    for (int c_x = 0; c_x < CHUNK_LIMIT_X;c_x ++)
    {
      renderChunk(&world->Chunks[c_y][c_x]);
    }
  }
  clock_t end = clock();
  double time_take = (double)(end-begin)/CLOCKS_PER_SEC;
  printf("Render Time take : %f\n",time_take);
}
