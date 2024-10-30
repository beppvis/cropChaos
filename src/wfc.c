#include "time.h"
#include "raylib.h"
#include "stdio.h"
#include <stdbool.h>
#include <stdlib.h>
#include "tilemap.c"


/*
  The following need to be done for this to work
  1. Initialised tileManager
*/





Tile getRandomTile(TileManager *tileManager)
{
  int rand_x = getRandomItemI(TILE_MAX_X);
  int rand_y = getRandomItemI(TILE_MAX_Y);
  Tile randTile = tileManager->tiles[rand_y][rand_x];
  return tileManager->tiles[rand_y][rand_x];
}

Tile *getTileNeighbours(TileManager *tileManager,Tile tile,int *num)
{
  static Tile neighbours[4];
  /*
    0
    #
    T D L R
    */
  int i = 0 ;
  if (tile.index.y > 0)
  {
    Vector2i index = {tile.index.x,tile.index.y - 1};
    neighbours[i] = getTile(index, tileManager);
    // printf("NEIGHBOUR %d:%d,%d\n",i,index.y,index.x);
    i ++;
  }
  if (tile.index.y < 50 )
  {
    Vector2i index = {tile.index.x,tile.index.y + 1};
    neighbours[i] = getTile(index, tileManager);
    // printf("NEIGHBOUR %d:%d,%d\n",i,index.y,index.x);
    i ++;
  }
  if (tile.index.x > 0)
  {
    Vector2i index = {tile.index.x -1 ,tile.index.y };
    neighbours[i] = getTile(index, tileManager);
    // printf("NEIGHBOUR %d:%d,%d\n",i,index.y,index.x);
    i ++;
  }
  if (tile.index.x < 50)
  {
    Vector2i index = {tile.index.x + 1 ,tile.index.y };
    neighbours[i] = getTile(index, tileManager);
    // printf("NEIGHBOUR %d:%d,%d\n",i,index.y,index.x);
    i ++;
  }
  *num = i;
  // printf("Num of neighbours : %d\n",i);
  return neighbours;
}

void evaluvateTile(Tile *tile, Tile *tileNeigbour, int num)
{
  for (int i = 0; i<num;i++)
  {
    switch (tileNeigbour->terrainType)
    {
      case DIRT:
        tile->possibilites[SAND] = false;
        return;
      case GRASS:
        tile->possibilites[SAND] = false;
        tile->possibilites[WATER] = false;
        return;
      case WATER:
        tile->possibilites[DIRT] = false;
        tile->possibilites[GRASS] = false;
        return;
      case SAND:
        tile->possibilites[GRASS] = false;
        tile->possibilites[DIRT] = false;
        return;
      default:
        return;
        
    }
    tileNeigbour ++;
  }
}

enum TerrainTypes getRandomTerrainType()
{
  SetRandomSeed(time(NULL));
  int randomNumber = GetRandomValue(0,NUM_OF_TYPES-1);
  return (enum TerrainTypes)randomNumber;
}

enum TerrainTypes getTypeFromInt(int i)
{
  switch (i) 
  {
    case 0:
      return DIRT;
    case 1:
      return GRASS;  
    case 2:
      return WATER;  
    case 3:
     return SAND;  
    }
  return NULL_TILE;
}

void setTileTerrainType(Tile *tile)
{
  //checking if it all possibilites are there
  bool all_true = true;
  int num=0;
  static int numOfWaterBlocks = 0;
  for(int i = 0;i<NUM_OF_TYPES ;i++)
  {
    bool possibility = tile->possibilites[i];
    if (possibility) 
    {
      num++;
    }
    else if (!possibility) 
   {
      all_true = false;
    }
  }
  if (all_true)
  {
    printf("ALL TRUE\n");
    tile->terrainType = getRandomTerrainType();
    if (tile->terrainType == WATER )
    {
      numOfWaterBlocks ++;
      if(numOfWaterBlocks > WATER_MAX)
      {
        tile->terrainType = GRASS;
      }
    return;
  }
  }

  enum TerrainTypes types[num];
  int j = 0;
  printf("NUM :%d\n",num);
  for (int i = 0; i<num; i++)
  {
    if(tile->possibilites[i])
    {
     types[j] = getTypeFromInt(i);
     j ++;
    }
  }

  SetRandomSeed(time(NULL));
  int randomNumber = GetRandomValue(0,num - 1);
  tile->terrainType = types[randomNumber];

  if (tile->terrainType == WATER )
  {
    numOfWaterBlocks ++;
    if(numOfWaterBlocks > WATER_MAX)
    {
      tile->terrainType = GRASS;
    }
    }
  return;
  // Now get the tile with least 

}

void evaluvateTileNeighbours(TileManager *tileManager,Tile *sTile,Tile *sTileNeighbour,int numOfNeighbours)
{
  for (int i = 0; i < numOfNeighbours; i++)
  {
    Tile *tileNeighbours;
    int num = 0;
    Tile *tile= sTileNeighbour;
    tileNeighbours = getTileNeighbours(tileManager,*tile, &num);
    evaluvateTile(tile,tileNeighbours ,num );
    sTileNeighbour ++;
  }  
}

Tile getNeighbourWithLeastPossibilites(TileManager *tileManager,Tile *tileNeighbour,int num)
{
  int min = 4;
  bool changed = false;
  Tile tile;
  for (int i =0; i < num; i++)
  {
    if (getNumOfPossibilites(tileNeighbour) < min && isNULL(*tileNeighbour))
    {
      tile = *tileNeighbour;
      min = getNumOfPossibilites(tileNeighbour);
      changed = true;
    }
    tileNeighbour ++;
  }
  if (!changed){
    int i =0;
    SetRandomSeed(time(NULL));
    Tile randomTile = *getNullTiles(tileManager,&i ); 
    int r = GetRandomValue(0, i-1);
    Tile *tileNeighbours = getTileNeighbours(tileManager, randomTile,&i );
    *(tileNeighbour+r);
    evaluvateTile(&randomTile,tileNeighbours,i );
    return randomTile;
  }
  return tile;
}

void waveFunctionCollapse(TileManager *tileManager)
{
  //Chose random tile
  int num = 0 ;
  Tile tile = *getNullTiles(tileManager, &num);
  printf("MAIN TILE: %d,%d\n",tile.index.x,tile.index.y);
  //Evaluvate the nearest tiles
  Tile *tileNeighbour;
  int numOfNeighbours = 0;
  evaluvateTile(&tile,tileNeighbour ,numOfNeighbours);
  setTileTerrainType(&tile);
  placeTile(tileManager,&tile );

  while (!allFilled(*tileManager))
  {
    printf("MAIN TILE: %d,%d\n",tile.index.x,tile.index.y);
    tileNeighbour = getTileNeighbours(tileManager,tile , &numOfNeighbours);
    evaluvateTileNeighbours(tileManager,&tile , tileNeighbour, numOfNeighbours);
    tile = getNeighbourWithLeastPossibilites(tileManager,tileNeighbour,numOfNeighbours );
    setTileTerrainType(&tile);
    placeTile(tileManager,&tile);

  }
    

  //LOOP
  //Evaluvate the nearest tiles
  //Choose the tile with least prblty
  //LOOP END
}

