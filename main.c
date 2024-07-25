#include "raylib.h"
#include <stdbool.h>
#include "gamestd.c"
#include "player.c"
#include "tilemap.c"

//                       

/*
////////////////////////////////////////////////////
Reminder : This is the TEST Folder
////////////////////////////////////////////////////
*/
/*
  DIRT --> WATER & GRASS,
  GRASS --> DIRT,
  WATER --> DIRT,
*/



typedef struct Block 
{
  Vector2i position;
  Color color;
  Rectangle box;
  Size size;
}Block ;

void renderEntities(Entity *entities,int num);

int main(void){

  const Size screenSize = {500,900};
  InitWindow(screenSize.width,screenSize.height,"Crop");
  Player player;
  initPlayer(&player);
  Block block;
  block.position = (Vector2i) {100,100};
  block.color = BLACK;
  block.size = (Size){10,10};

  Camera2D camera = {0};
  camera.target = (Vector2){player.position.x + 20.0f,player.position.y+20.0f};
  camera.offset = (Vector2){screenSize.width/2.0f,screenSize.height/2.0f};
  camera.rotation = 0.0f;
  camera.zoom = 1.0f;

  Entity entities[TILE_MAX_X*TILE_MAX_Y];
  int num_enities;

  TileManager tileManager;
  initTilemanager(&tileManager);
  dumbTiles(&tileManager,entities,&num_enities);
  SetWindowState(FLAG_WINDOW_MAXIMIZED);
  SetTargetFPS(60);

  while (!WindowShouldClose()) {

    float delta = GetFrameTime();
    updatePlayer(&player,delta);
    cameraFollow(&camera, &player, delta, screenSize);
    BeginDrawing();
      BeginMode2D(camera);
      ClearBackground(BLACK);
      renderTiles(&tileManager);
      renderEntities(entities,num_enities);
      renderPlayer(&player,&camera);
      EndMode2D();
    EndDrawing();

  }  
  CloseWindow();

  return 0;

}


void renderEntities(Entity *entities,int num)
{
  for (int i =0 ; i<num; i++)
  {
    DrawTexture(entities->sprite,entities->position.x, entities->position.y,WHITE);
    entities ++;
  }
}

