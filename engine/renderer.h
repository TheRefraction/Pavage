#ifndef RENDERER_H
#define RENDERER_H

#include <SDL2/SDL.h>
#include "object.h"

typedef struct RENDERER_STRUCT {
    SDL_Renderer *renderer;
    Object *objects[128];
} Renderer;

void initRenderer(Renderer *renderer, SDL_Window *handle);
void cleanupRenderer(Renderer *renderer);

#endif
