#ifndef RENDERER_H
#define RENDERER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "object.h"
#include "../game/constants.h"

typedef struct RENDERER_STRUCT {
    SDL_Renderer *renderer;
    Object *objects[MAX_OBJECTS];
    TTF_Font *fonts[MAX_FONTS];
    int lastFontIndex;
} Renderer;

void initRenderer(Renderer *renderer, SDL_Window *handle);
void addToRenderer(Renderer *renderer, ObjectData *data);
void addFontToRenderer(Renderer *renderer, char *filename, unsigned short size);
void flushRenderer(Renderer *renderer);
void cleanupRenderer(Renderer *renderer);

#endif
