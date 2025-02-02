#include "entities.h"
#include "gamestd.h"
#include <stdio.h>


const char *file_paths[NUM_ENTITIES - 1] = {
    "../assets/grass.png", "../assets/grass.png", "../assets/grass.png"};

void loadTextureEntities(Texture2D *entities_texture) {
  printf("%d\n", NUM_ENTITIES);
  // NO IDEA ON WHY THIS IS NEEDED
  for (int i = 0; i < NUM_ENTITIES - 1; i++) {

    printf("%d\n", i);
    *entities_texture = LoadTexture(file_paths[i]);
    entities_texture++;
  }
  printf("ENTITIES:  finished loading \n");
}

void initEntity(Entity *entity, Texture2D *entities_texture) {
  entity->entityType = 0;
  entity->sprite = *entities_texture;
  entity->position = (Vector2){0, 0};
}

void initEntityManager(Chunk *chunk, Texture2D *entitiesTexture) {
  EntityManager *entityManager = &chunk->entityManager;
  entityManager->num_entites = 0;
}


Entity getTestEntity(Vector2 position)
{
  return (Entity) {
    LoadTexture("../assets/bread.png"),
    NULL_ENTITY,
    position
  };
}


void initEntities(Entity *entities, int num,
                  Texture2D entities_text[NUM_ENTITIES]) {
  for (int i = 0; i < num; i++) {
    if (entities->entityType == 0) {
      printf("NULL entity\n");
      entities++;
      continue;
    }
    entities->sprite = entities_text[entities->entityType];
    entities++;
  }
}

void renderEntities(EntityManager *entityManager) {
  int num = entityManager->num_entites;
  Entity *entities = entityManager->Entities;

  for (int i = 0; i < num; i++) {
    Rectangle sourceRec =
        getRect((Vector2){0, 0},
                (Size){entities->sprite.width, entities->sprite.height});
    Rectangle destRec = getRect((Vector2){entities->position.x * TILE_SIZE,
                                          entities->position.y * TILE_SIZE},
                                (Size){TILE_SIZE, TILE_SIZE});
    Texture2D spirte = entities->sprite;
    DrawTexturePro(spirte, sourceRec, destRec, (Vector2){0, 0}, 0, WHITE);
    entities++;
  }
}

void addEntity(EntityManager* entityManager , Entity* entity) 
{
  int i = entityManager->num_entites;
  entityManager->Entities[i] = *entity;
  entityManager->num_entites ++;
}



