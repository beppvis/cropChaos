#include <game/ecs.h>
#include <stddef.h>
#include <stdio.h>
#include <stddef.h>
#include <stddef.h>
#include <stdlib.h>



ArchetypeTable createArchetypeTable(){
    return  (ArchetypeTable){.table=(Archetype *)malloc(MAX_ARCHETYPES*sizeof(Archetype))};
}

/*
    * HACK: creates a Key based on the type of the components
    */
int getComponentsKey(int n, Component *components){
    int key=0;
    for(int i = 0 ; i < n ;i++){
        key += components[i].type;
    }
    return key;
}

/*
    * Get the index of the archetype
*/
int 
findArchetype(ECSWorld* world ,int n,Component *components) 
{
    int key = getComponentsKey(n, components);
    int index = key%MAX_ARCHETYPES;
    ArchetypeTable table = *world->table;
    for(int i = 0 ; i < MAX_ARCHETYPES;i++){
    }
}

ECSWorld createWorld(){
    ArchetypeTable table = createArchetypeTable(); 
    return (ECSWorld){
        .table=&table
    };
}

int createEntity(ECSWorld* world,int n, Component *components){

}
