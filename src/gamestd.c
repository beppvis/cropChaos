#include "gamestd.h"
#include "../include/raylib.h"
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

// REMINDER: Initialised with a buffer of 100
#define debugTxtBuffer  100

char* DebugTxts[debugTxtBuffer];
int DebugIndex = 0;


Rectangle getRect(Vector2 position,Size size)
{
  return (Rectangle) {position.x,position.y,size.width,size.height};
}

bool isInside(int size_A,Vector2 posA,Vector2 posB)
{
  if ((posB.x <= (size_A + posA.x) && posB.y <= (size_A + posA.y))&&(posB.x > posA.x &&posB.y > posA.y))
  {
    return true;
  }
  return false;
}

int flip_h(Rectangle *sourceRect)
{
  sourceRect->x = sourceRect->x * -1;
  return 0;
}


int LogIt(char *TAG,char *message, ...)
{  
  //TODO : create more
  va_list ptr;
  va_start(ptr, message);
  char dest[1000];
  sprintf(dest,"%s",TAG );

  while(*message != '\0'){
    if (*message == 'd'){
      int i = va_arg(ptr,int);
      char* source;
      asprintf(&source ,"%d",i);
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
  strcat(dest,"\n" );
  printf("%s",dest);
  return 0;
}

int addDebugText(char *TAG,char *message, ...){
  va_list ptr;
  va_start(ptr, message);
  // BUFFER: 200 for destination char
  static char dest[200];
  sprintf(dest,"%s",TAG );

  while(*message != '\0'){
    if (*message == 'd'){
      int i = va_arg(ptr,int);
      char* source;
      asprintf(&source ,"%d",i);
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

  DebugTxts[DebugIndex] = dest;
  if (!(DebugIndex > debugTxtBuffer)){
    DebugIndex ++;
  }
  else{
    DebugIndex = 0 ;
  }


  printf("ADDED ENTRY\n");

  return 0;
}

int renderDebugText(){
  for (int i=0; i < DebugIndex ; i++){
    char* dest = DebugTxts[i];
    printf("HUH : %d\n",i);
    Vector2 debugPos = {20,20 + (10*i)};
    DrawTextPro(GetFontDefault(),dest,debugPos, (Vector2){0,0}, 0, 20, 2,WHITE );
  }
  return 0;
}


// returns sectionapath/filename
int getPathTo(char *out,const char *section_path,const char* file_name){
  sprintf(out,"%s/%s",section_path,file_name);
  return 0;
}
