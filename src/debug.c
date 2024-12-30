#include "gamestd.c"
#include "raylib.h"
#include <stdarg.h>
#include <stdio.h>
#include <string.h>


int debug(char *message,...){
  va_list ptr;
  va_start(ptr,message);
  char dest[100];

  while (*message != '\0' ){
    if (*message == 'd'){
      char *source;
      int i = va_arg(ptr,int);
      asprintf(&source,"%d",i);
      strcat(dest,source);
    }
    else if (*message == 'c'){
      int c = va_arg(ptr,int);
      char* source;
      asprintf(&source ,"%c",c);
      strcat(dest,source);
    }
    else if (*message == 'f'){
      double d = va_arg(ptr,double);
      char* source;
      asprintf(&source ,"%f",d);
      strcat(dest,source);
    }
    message ++;

  }
  va_end(ptr);

  DrawRectangle(100, 100,100 ,100 ,BLACK);
  DrawText(dest,100 , 100, 20,WHITE);

  return 0;
}

