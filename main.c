#include "raylib.h"
#include <stdbool.h>
#include "gamestd.c"
#include "player.c"
#include "tilemap.c"
#include "entities.c"

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


void renderEntities(Entity *entities,int num);

int main(void){

  const Size screenSize = {500,900};
  InitWindow(screenSize.width,screenSize.height,"Crop");
  Player player;
  initPlayer(&player);

  Camera2D camera = {0};
  camera.target = (Vector2){player.position.x + 20.0f,player.position.y+20.0f};
  camera.offset = (Vector2){screenSize.width/2.0f,screenSize.height/2.0f};
  camera.rotation = 0.0f;
  camera.zoom = 1.0f;

  Entity entities[TILE_MAX_X*TILE_MAX_Y];
  int num_enities;
  Texture2D entities_texture[NUM_ENTITIES];

  TileManager tileManager;
  initTilemanager(&tileManager);
  dumbTiles(&tileManager,entities,&num_enities);
  loadTextureEntities(entities_texture);
  initEntities(entities,num_enities,entities_texture);
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
        renderEntities(entities, num_enities);
        renderPlayer(&player,&camera);
        
      EndMode2D();

    renderHUD(&player);
    EndDrawing();
  
  }  
  CloseWindow();

  return 0;

}



