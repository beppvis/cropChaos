#include "../include/raylib.h"
#include "gamestd.c"
#include "gamestd.h"
#include "player.c"
#include "tilemap.c"
#include "world.c"
#include <stdatomic.h>
#include <stdbool.h>
#include <stdio.h>


// WARNING: the following line are position dependent
#define RAYGUI_IMPLEMENTATION
#include "../include/raygui.h"

/*
  DIRT --> WATER & GRASS,
  GRASS --> DIRT,
  WATER --> DIRT,
*/

int main() {

  // freopen("../logs/LOG.out","w", stdout);
  freopen("../logs/LOGE.out", "w", stderr);

  // WARNING: wierd sizes on MAC and LINUX
  const Size screenSize = {500, 800};

  InitWindow(screenSize.width, screenSize.height, "Crop");

  World world;
  initWorld(&world);

  Player player;
  initPlayer(&player, &world);

  Camera2D camera = {0};
  camera.target =
      (Vector2){player.position.x + 20.0f, player.position.y + 20.0f};
  camera.offset = (Vector2){screenSize.width / 2.0f, screenSize.height / 2.0f};
  camera.rotation = 0.0f;
  camera.zoom = 1.0f;

  //NOTE: to stop for maximisig windows 
  //SetWindowState(FLAG_WINDOW_MAXIMIZED);

  SetTargetFPS(60);

  printf("PLAYER : %lu \n", sizeof(player));
  Chunk *test  = getChunkWithIndex(&world, (Vector2i){1,1}) ;
  
  Entity entity = (Entity) 
  {
      LoadTexture("../assets/bread.png"),
      0,
      (Vector2){10,10},
  };
  addEntity(&test->entityManager,&entity);

  while (!WindowShouldClose() && !player.gameOver) {

    float delta = GetFrameTime();
    updatePlayer(&player, delta);
    cameraFollow(&camera, &player, delta, screenSize);

    printf("%s\n", getPlayerDebugInfo(&player));
    BeginDrawing();

    ClearBackground(BLACK);
    BeginMode2D(camera);

    renderWorld(&world);
    renderPlayer(&player, &camera);

    EndMode2D();

    int out = GuiSlider((Rectangle){10, 10, 100, 10}, "hoo", "hee",
                        &player.speed, 100.0, 1000.0);

    char debugBuff[100];
    Vector2i chunk_i = getChunkIndex(&world, player.position);
    sprintf(debugBuff, "Player is in CHUNK: %d,%d ", chunk_i.x, chunk_i.y);
    DrawText(debugBuff, 20, 20, 20, BLUE);
    // GuiLabel((Rectangle){10,60,100,10},debugBuff);

    renderHUD(&player);
    EndDrawing();
  }

  CloseWindow();

  return 0;
}
