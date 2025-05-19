#include <game/world.h>
#include <game/gamestd.h>
#include <game/tilemap.h>
#include "items.c"
#include "entities.c"
#include <stddef.h>
#include <stdio.h>
#include <time.h>



void initWorld(World *world)
{
  clock_t begin = clock();
  Texture2D entities_texture[NUM_ENTITIES];
  loadTextureEntities(&world->entityTextures[0]);

  for (int c_y = 0; c_y < CHUNK_LIMIT_Y;c_y ++)
  {
    for (int c_x = 0; c_x < CHUNK_LIMIT_X;c_x ++)
    {
      fprintf(stdout,"INIT Chunk (%d,%d) STARTED\n",c_y,c_x);

      Vector2i chunk_index = {c_x,c_y};
      Chunk *chunk = &world->Chunks[chunk_index.y][chunk_index.x]; 
      initChunk(chunk,chunk_index,world->entityTextures);
      placeTilesInChunk(chunk);

      // printf("INIT Chunk (%zd,%zd) FINISHED \n",c_y,c_x);

    }
  }
  clock_t end = clock();
  double time_spent = (double)(end-begin)/CLOCKS_PER_SEC;
  fprintf(stdin,"Total INIT time taken : %f\n",time_spent);
}

void initChunk(Chunk *chunk,Vector2i chunk_index,Texture2D *entities_texture)
{
  static int init_num = 0 ;
  init_num ++;
  fprintf(stdout,"INIT %d : STARTED\n",init_num);
  chunk->index = chunk_index;
  initTilemanager(chunk);
  initEntityManager(chunk,entities_texture);
  fprintf(stdout,"INIT %d : FINISHED\n",init_num);
}

void initTilemanager(Chunk *chunk)
{
  TileManager *tileManager = &chunk->tileManger;
  for (int y = 0 ; y<TILE_MAX_Y; y ++)
  {
    for (int x = 0 ; x<TILE_MAX_X; x ++)
    {
      Tile tile = {
          .index = (Vector2i){x, y},
          .position = (Vector2){(x * 50) +(50*CHUNK_SIZE* chunk->index.x),
                                (y * 50) + (50*CHUNK_SIZE* chunk->index.y)},
          .terrainType = NULL_TILE,
          .possibilites = {1, 1, 1, 1},
      };
      tileManager->tiles[y][x] = tile;
    }
  }
}


void renderChunkDebug(Chunk *chunk)
{
  Rectangle chunk_rec = {50*CHUNK_SIZE* chunk->index.x ,50*CHUNK_SIZE* chunk->index.y,50*CHUNK_SIZE,50*CHUNK_SIZE};
  DrawRectangleLinesEx(chunk_rec, 2.0, RED);

  char out[100];
  sprintf(out,"%d,%d",chunk->index.x,chunk->index.y);
  DrawText(out,50*CHUNK_SIZE* chunk->index.x +10,50*CHUNK_SIZE* chunk->index.y+10,100,BLUE);
}



void renderChunk(Chunk *chunk)
{
  renderTiles(&chunk->tileManger); 
  renderEntities(&chunk->entityManager);

  if (IsKeyDown(DBG_KEY)) renderChunkDebug(chunk);
}


void updateWorld(World *world,Player *player)
{ 
  Vector2i playerChunkIndex = getChunkIndex(world,player->position);
  fprintf(stdout,"[CHUNK] Updating chunk with index  : %d ,%d \n",playerChunkIndex.x,playerChunkIndex.y);
  updateChunk(getChunkWithIndex(world, playerChunkIndex),player);
}


void updateChunk(Chunk *chunk, Player *player)
{
  if(chunk->entityManager.num_entites==0)
    return;
  int j = 0; // actual no of entities  
  int i = 0;
  while (j < chunk->entityManager.num_entites) {
    i++;  
    Entity* entity = &chunk->entityManager.Entities[i];
    if (entity->entityType==NULL_ENTITY)
      continue;
    j ++;
    Rectangle entity_hit_box = (Rectangle){entity->position.x,entity->position.y, entity->sprite.width, entity->sprite.height}; 
    Rectangle player_hit_box = (Rectangle){player->position.x,player->position.y,player->size.width,player->size.height};
    if (isColliding(player_hit_box, entity_hit_box)&&!player->inMenu)
    {
      Item item;  
      fprintf(stdout,"Player entity collishion detected");
      switch (entity->entityType) {
        case ITEM_ENTITY:
          item = entityToItem(*entity);
          addItemToInventory(item, &player->inventory);
          *entity = getTestEntity(player->position);
          break;
        default:
          break;
      }
      return; // WARNING: this is just for testing item pickup
    }
  }

  return;
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
  char *message;
  printf("Render Time take : %f\n",time_take);
}

Chunk *getChunkWithIndex(World *world, Vector2i index)
{
  // position -> chunk cords
  // return chunk

  // Validating if the given index is within the bound 
  if ((index.x * index.y) >= sizeof(world->Chunks))
    return NULL;

  return &world->Chunks[index.y][index.x];
}

// To get the chunk Index 
Vector2i getChunkIndex(World *world,Vector2 position){
  int x = 0;
  int y = 0;
  x = position.x / (CHUNK_SIZE*TILE_SIZE);
  y = position.y / (CHUNK_SIZE*TILE_SIZE);
  return (Vector2i) {x,y};
}

void spawnEntityInWorld(World *world,Entity *entity)
{
  Vector2i chunk_i = getChunkIndex(world, entity->position);
  Chunk* chunk = getChunkWithIndex(world, chunk_i);
  if (chunk->entityManager.num_entites == MAX_ENTITIES-1) 
  {
    fprintf(stderr, "[CHUNK] : Num of entities exceeded \n");
    return;
  }

  addEntity(&chunk->entityManager,entity);
  fprintf(stdout,"[CHUNK]{%d,%d} : Spawning entity at {%f,%f}\n",chunk->index.x,chunk->index.y,entity->position.x,entity->position.y);
  return;
}





