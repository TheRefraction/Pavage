#ifndef RENDERER_H
#define RENDERER_H

#include <SDL2/SDL.h>
#include "object.h"
#include "../game/constants.h"

typedef struct RENDERER_STRUCT {
    SDL_Renderer *renderer;
    Object objects[MAX_OBJECTS];
} Renderer;

void initRenderer(Renderer *renderer, SDL_Window *handle);
void addToRenderer(Renderer *renderer, ObjectData data);
void cleanupRenderer(Renderer *renderer);

#endif
