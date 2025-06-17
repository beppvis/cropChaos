#include <ray/raylib.h>
#include <stddef.h>
#include "items.h"

#define MAX_ARCHETYPES 10
#define MAX_COMPONENTS 10

typedef enum {
  POSITION,
  TEXTURE,
  BOOLEAN,
  INT,
}ComponentType;

typedef struct{
  void* component;
  ComponentType type;
  int id;
} Component;

typedef struct{
  Component* table;
} ComponentTable;

typedef struct{
  ComponentTable* table;
  Component* type;
}Archetype;

typedef struct{
  Archetype* table;
}ArchetypeTable;

typedef struct{
  ArchetypeTable* table;
}ECSWorld ;


ECSWorld createWorld();
ArchetypeTable createArchetypeTable();
int getComponentsKey(int n, Component *components);
int createEntity(ECSWorld* world,int n, Component *components);
Component* getEntityComponents(int entityId,Component type);
int findArchetype(ECSWorld* world ,int n,Component *components); 




