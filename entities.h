#include <raylib.h>
#include "gamestd.h"
#include "tilemap.h"
#ifdef entities_h
#define entities_h

void loadTextureEntities(Texture2D *entities_texture);
void initEntities(Entity *entities,int num,Texture2D entities_text[NUM_ENTITIES]);

#endif
