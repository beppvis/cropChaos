#include "../include/raylib.h"
#include <stdbool.h>
#include <stdio.h>
#include "gamestd.c"
#include "player.c"
#include "tilemap.c"
#include "world.c"
#define RAYGUI_IMPLEMENTATION
#include "../include/raygui.h"
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
  
  freopen("../logs/LOG.out","w", stdout);
  freopen("../logs/LOGE.out","w", stderr);

  const Size screenSize = {800,1200};
  InitWindow(screenSize.width,screenSize.height,"Crop");

  printf("BORG \n");

  World world;
  initWorld(&world);

  Player player;
  initPlayer(&player,&world);

  Camera2D camera = {0};
  camera.target = (Vector2){player.position.x + 20.0f,player.position.y+20.0f};
  camera.offset = (Vector2){screenSize.width/2.0f,screenSize.height/2.0f};
  camera.rotation = 0.0f;
  camera.zoom = 1.0f;


  SetWindowState(FLAG_WINDOW_MAXIMIZED);
  SetTargetFPS(60);

  printf("PLAYER : %lu \n ", sizeof(player));

  while (!WindowShouldClose() && !player.gameOver) {

    float delta = GetFrameTime();
    updatePlayer(&player,delta);
    cameraFollow(&camera, &player, delta, screenSize);
    
    printf("%s\n",getPlayerDebugInfo(&player));
    BeginDrawing();

      BeginMode2D(camera);

        ClearBackground(BLACK);
        renderWorld(&world);
        renderPlayer(&player,&camera);

      EndMode2D();

      //   GuiButton((Rectangle){10,10,100,200},"sdjadlk");
    renderHUD(&player);
    EndDrawing();
  
  }  

  CloseWindow();

  return 0;

}



