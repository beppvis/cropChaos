#include "tilemap.h"
#include "gamestd.h"
#include <stdio.h>

int getNumOfPossibilites(Tile *tile)
{
  int num;
  for ( int i = 0; i < NUM_OF_TYPES - 1;i ++)
  {
    if (tile->possibilites[i]) num ++;
  }
  return num;
}

Vector2i positionToIndex(Vector2 position,TileManager tileManager)
{
  return (Vector2i){0,0};
}

Tile itemToTile(Item item,Vector2 position, TileManager tileManager)
{
  return (Tile){positionToIndex(position,tileManager),position,PLAYER_TILE,GRAY};
}

Tile nullTile()
{
  return (Tile){.terrainType = NULL_TILE,
  .index = (Vector2i){0,0},
      };
}

bool isNULL(Tile tile)
{
  if (tile.terrainType == NULL_TILE)return true;
  else return false;
}

Tile *getNullTiles(TileManager *tileManager,int *num)
{
  static Tile nullTiles[TILE_MAX_Y*TILE_MAX_X];
  int i = 0;
  for (int y = 0; y<TILE_MAX_Y; y ++)
  {
    for (int x = 0; x<TILE_MAX_X; x ++)
    {
      Tile tile = tileManager->tiles[y][x];
      if (isNULL(tile))
      {
        nullTiles[i] = tile;
        i ++;
      }
    }
  }
  num = &i;
  return nullTiles;
}

//STD
void debugPlaceholder()
{
    printf("TILL HERE\n");
}
//RandomIndex
int getRandomItemI(int itemSize)
{
  // MIGHT Go BAD 
  SetRandomSeed(itemSize);
  return GetRandomValue(0,itemSize-1 );
}

Tile getTile(Vector2i index,TileManager *tileManager)
{
  return tileManager->tiles[index.y][index.x];
}

bool isEmptyTile(Tile tile)
{
  return tile.terrainType == EMPTY;
}

bool isNotNullTile(Tile tile)
{
  return tile.terrainType != NULL_TILE;
}

bool allFilledDebug(TileManager tileManager)
{
  bool filled = false;
  static int runned = 0;
  if (runned ==100){
    return true;
  }
  runned++;
  return false;
}
bool allFilled(TileManager tileManager)
{
  bool filled = false;
  for (int y = 0; y<TILE_MAX_Y;y++)
  {
    for (int x = 0; x<TILE_MAX_X;x++)
    {
      if (isNULL(tileManager.tiles[y][x]))return false;
    }
}
  return true;
}

void placeTile(TileManager *tileManager, Tile *tile )
{
  tileManager->tiles[tile->index.y][tile->index.x] = *tile;
}

void setColor(Tile *tile)
{
    switch (tile->terrainType) 
    {
      case DIRT:
        tile->color = BROWN;
        return;
      case GRASS:
        tile->color = GREEN;
        return;
      case WATER:
        tile->color = BLUE;
        return;
      case SAND:
        tile->color = YELLOW;
        return;
      default:
        tile->color = GREEN;
        return;
    }
  
}

void renderTiles(TileManager *tileManager)
{
  for (int y = 0;y<TILE_MAX_Y;y++)
  {
    for (int x = 0;x<TILE_MAX_X;x++)
    {
      Vector2i index = {x,y};
      Tile tile = getTile(index, tileManager);
      setColor(&tile);
      DrawRectangle(tile.position.x,tile.position.y ,TILE_SIZE,TILE_SIZE, tile.color);
      char sIndex[50];

      if (!IsKeyDown(DBG_KEY)) continue;
      //sprintf(sIndex,"(%d,%d)",tile.index.y,tile.index.x );
      sprintf(sIndex,"(%.1f,%.1f)",tile.position.y,tile.position.x );
      //DrawRectangleLines(tile.position.x,tile.position.y ,TILE_SIZE,TILE_SIZE, RED);
      DrawText(sIndex,tile.position.x, tile.position.y, 10, YELLOW);
    }
  }
}


void placeTilesInChunk(Chunk *chunk)
{
  TileManager *tileManager = &chunk->tileManger;
  for (int y = 0;y<TILE_MAX_Y;y++)
  {
    for (int x = 0;x<TILE_MAX_X;x++)
    {
      Vector2i index = {x,y};
      Tile tile = getTile(index, tileManager);
      tile.terrainType = NULL_TILE;
      tileManager->tiles[y][x] = tile;
    }
  }

    
}


void dumbTiles(TileManager *tileManager,EntityManager *entityManager)
{
  int num = 0;
  Entity *entities = entityManager->Entities;

  //FAILURE WARNING this might break but clean code : ) 

  int num_entities = entityManager->num_entites;

  for (int y = 0;y<TILE_MAX_Y;y++)
  {
    for (int x = 0;x<TILE_MAX_X;x++)
    {
      Vector2i index = {x,y};
      Tile tile = getTile(index, tileManager);
      tile.terrainType = NULL_TILE;
      tileManager->tiles[y][x] = tile;
      // SetRandomSeed(time(NULL));
      // int random_num = GetRandomValue(1,3);
      // if (1)
      // {
      //   Vector2 position = {x,y};
      //   *entities= (Entity){
      //                         .entityType = BLOCK,
      //                         .position = position};
      //   entities ++;
      //   num_entities ++;
      // }
    }
  }
}
