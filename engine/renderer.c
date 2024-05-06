#include "renderer.h"

void initRenderer(Renderer *renderer, SDL_Window *handle) {
    renderer->renderer = SDL_CreateRenderer(handle, -1, SDL_RENDERER_SOFTWARE);

    for(int i = 0; i < MAX_OBJECTS; i++) {
        renderer->objects[i] = NULL;
    }
}

void cleanupRenderer(Renderer *renderer) {
    for(int i = 0; i < MAX_OBJECTS; i++) {
        cleanupObject(renderer->objects[i]);
        renderer->objects[i] = NULL;
    }
    SDL_DestroyRenderer(renderer->renderer);
}