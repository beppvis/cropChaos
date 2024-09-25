#include "gamestd.h"
#include "raylib.h"
#include <stdbool.h>
#include "gamestd.c"
#include "player.c"
#include "tilemap.c"
#include "world.c"
//                       

/*
////////////////////////////////////////////////////
Reminder : I started because I thought it was easy
////////////////////////////////////////////////////
*/
/*
  DIRT --> WATER & GRASS,
  GRASS --> DIRT,
  WATER --> DIRT,
*/



int main(){

  const Size screenSize = {800,1200};
  InitWindow(screenSize.width,screenSize.height,"Crop");
  Player player;
  initPlayer(&player);

  Camera2D camera = {0};
  camera.target = (Vector2){player.position.x + 20.0f,player.position.y+20.0f};
  camera.offset = (Vector2){screenSize.width/2.0f,screenSize.height/2.0f};
  camera.rotation = 0.0f;
  camera.zoom = 1.0f;

  World world;
  initWorld(&world);
  world.player = player;


  SetWindowState(FLAG_WINDOW_MAXIMIZED);
  SetTargetFPS(60);

  while (!WindowShouldClose()) {

    float delta = GetFrameTime();
    updatePlayer(&player,delta);
    cameraFollow(&camera, &player, delta, screenSize);
    BeginDrawing();

      BeginMode2D(camera);

        ClearBackground(BLACK);
        renderWorld(&world);
        renderPlayer(&player,&camera);

      EndMode2D();

    renderHUD(&player);
    EndDrawing();
  
  }  

  CloseWindow();

  return 0;

}



