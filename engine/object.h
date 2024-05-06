#ifndef OBJECT_H
#define OBJECT_H

#include <SDL2/SDL.h>
#include "objectdata.h"

typedef struct OBJECT_STRUCT {
    ObjectData data;
    bool null;
    SDL_Surface *sprite;
    SDL_Texture *texture;
} Object;

Object initObject(SDL_Renderer *renderer, ObjectData data);
void cleanupObject(Object *object);

#endif
