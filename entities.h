#include <raylib.h>
#include "gamestd.h"
#include "tilemap.h"
#ifdef entities_h
#define entities_h

void loadTextureEntities(Texture2D *entities_texture);
void initEntities(Entity *entities,int num,Texture2D entities_text[NUM_ENTITIES]);
void initEntity(Entity *entity,Texture2D *entities_texture);
void initEntityManager(EntityManager *entityManager,Texture2D entities_texture);


#endif
