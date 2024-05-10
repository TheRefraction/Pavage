#include "renderer.h"

void initRenderer(Renderer *renderer, SDL_Window *handle) {
    renderer->renderer = SDL_CreateRenderer(handle, -1, SDL_RENDERER_SOFTWARE);

    for(int i = 0; i < MAX_OBJECTS; i++) {
        renderer->objects[i] = NULL;
    }
}

void addToRenderer(Renderer *renderer, ObjectData *data) {
    renderer->objects[data->id] = initObject(renderer->renderer, data);
}

void removeFromRenderer(Renderer *renderer, int i) {
    cleanupObject(renderer->objects[i]);
    renderer->objects[i] = NULL;
}

void flushRenderer(Renderer *renderer) {
    for(int i = 0; i < MAX_OBJECTS; i++) {
        removeFromRenderer(renderer, i);
    }
}

void cleanupRenderer(Renderer *renderer) {
    flushRenderer(renderer);
    SDL_DestroyRenderer(renderer->renderer);
}