#include "raylib.h"
#include "plug.h"
#include <dlfcn.h>
#include <stdio.h>
#include "stdlib.h"

plug_hello_t plug_hello = NULL;

int main(){
  const char *libplug_filename = "libplug.so";
  void *libplug = dlopen(libplug_filename,RTLD_NOW);
  if (libplug == NULL){
    fprintf(stderr,"ERROR : could not load %s: %s",libplug_filename,dlerror());
    return 1;
  }
  plug_hello = dlsym(libplug,"plug_hello");

  if (plug_hello == NULL){
    fprintf(stderr,"ERROR : could not find plug_hello in %s:%s",
            libplug_filename,dlerror()); 
    return 1;
  }

  plug_hello();

  return 0; 
  
  Rectangle rec = {0,0,200,200};
  InitWindow(1000,1000 ,"TEST" );
  Vector2 origin = {100,100};
  SetTargetFPS(10);
  while(!WindowShouldClose()){
    BeginDrawing();

      ClearBackground(WHITE);
      DrawRectanglePro(rec, origin,10 ,RED );
      DrawCircle(origin.x, origin.y, 30, BLACK);
    EndDrawing();
  }
  CloseWindow();
}
