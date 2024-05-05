#ifndef OBJECT_H
#define OBJECT_H

#include <SDL2/SDL.h>

typedef struct OBJECT_STRUCT {
    int x;
    int y;
    int z;
    SDL_Surface *sprite;
    SDL_Texture *texture;
} Object;

void initObject(Object *object, SDL_Renderer *renderer, char* sprite, int x, int y, int z);
void updateObject(Object *object, int x, int y, int z);
void cleanupObject(Object *object);

#endif
