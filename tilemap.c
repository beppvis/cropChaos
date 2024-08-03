#include "tilemap.h"
#include <raylib.h>

enum TerrainTypes{
  DIRT,// 0
  GRASS,// 1
  WATER,// 2
  SAND,// 3
  EMPTY,
  NULL_TILE,
} TerrainTypes;

int getNumOfPossibilites(Tile *tile)
{
  int num;
  for ( int i = 0; i < NUM_OF_TYPES - 1;i ++)
  {
    if (tile->possibilites[i]) num ++;
  }
  return num;
}

Tile nullTile()
{
  return (Tile){.terrainType= NULL_TILE,
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
  printf("PLACE : tile index %d, %d \n",tile->index.y,tile->index.x);
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
      sprintf(sIndex,"(%d,%d)",tile.index.y,tile.index.x );
      DrawRectangleLines(tile.position.x,tile.position.y ,TILE_SIZE,TILE_SIZE, RED);
      DrawText(sIndex,tile.position.x, tile.position.y, 10, YELLOW);
    }
  }
}

void dumbTiles(TileManager *tileManager,Entity *entities,int *num_entities)
{

  static Entity (env_items[TILE_MAX_X*TILE_MAX_Y]);

  int num = 0;

  for (int y = 0;y<TILE_MAX_Y;y++)
  {
    for (int x = 0;x<TILE_MAX_X;x++)
    {
      Vector2i index = {x,y};
      Tile tile = getTile(index, tileManager);
      tile.terrainType = NULL_TILE;
      placeTile(tileManager,&tile);
      char sIndex[50];
      SetRandomSeed(time(NULL));
      int random_num = GetRandomValue(1,3);
      if (1)
      {
        // Texture2D berries = LoadTexture("./assets/grass.png");
        // Rectangle source_rec = {0,0,berries.width,berries.height};
        // Rectangle dest_rec = {x,y,50,50};
        Vector2 position = {x,y};
        *entities= (Entity){
                              .entityType = BLOCK,
                              .position = position};
        printf("positions are : %f, %f",position.x,position.y);
        entities ++;
        num ++;
      }
      // sprintf(sIndex,"(%d,%d)",tile.index.y,tile.index.x );
      // DrawText(sIndex,tile.position.x, tile.position.y, 10, YELLOW);
    }
  }
  *num_entities = num;
}
