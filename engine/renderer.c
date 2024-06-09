#include "renderer.h"

void initRenderer(Renderer *renderer, SDL_Window *handle) {
    renderer->renderer = SDL_CreateRenderer(handle, -1, SDL_RENDERER_SOFTWARE);

    for(int i = 0; i < MAX_OBJECTS; i++) {
        renderer->objects[i] = NULL;
    }

    for(int i = 0; i < MAX_FONTS; i++) {
        renderer->fonts[i] = NULL;
    }

    renderer->lastFontIndex = -1;
}

void addFontToRenderer(Renderer *renderer, char *filename, unsigned short size) {
    if(renderer->lastFontIndex >= MAX_FONTS - 1) { //TO CHECK !!
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Reached MAX_FONTS limit! Font has not been added!");
        return;
    }

    TTF_Font* font;
    font = TTF_OpenFont(filename, size);
    if (!font) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failed to load font: %s", TTF_GetError());
    }
    renderer->lastFontIndex++;
    renderer->fonts[renderer->lastFontIndex] = font;
}

/**
 * removeFontRenderer - Removes the selected font from the renderer
 * @param renderer Pointer on the current renderer
 * @param i Index of the font to remove
 */
void removeFontFromRenderer(Renderer *renderer, int i) {
    if(renderer->fonts[i] != NULL) {
        TTF_CloseFont(renderer->fonts[i]);
        renderer->fonts[i] = NULL;
    }
}

void addToRenderer(Renderer *renderer, ObjectData *data) {
    renderer->objects[data->id] = initObject(renderer->renderer, renderer->fonts, data);
}

/**
 * removeFromRenderer - Removes and destroys an object from the rendering list
 * @param renderer Pointer on the current renderer
 * @param i Index of the object to remove
 */
void removeFromRenderer(Renderer *renderer, int i) {
    cleanupObject(renderer->objects[i]);
    renderer->objects[i] = NULL;
}

void flushObject(Renderer *renderer, ObjectData *data) {
    removeFromRenderer(renderer, data->id);
    data->inRenderer = false;
    data->flush = false;
}

void flushRenderer(Renderer *renderer) {
    for(int i = 0; i < MAX_OBJECTS; i++) {
        removeFromRenderer(renderer, i);
    }
}

/**
 * flushFontRenderer - Removes all fonts from the renderer
 * @param renderer Pointer on the current renderer
 */
void flushFontRenderer(Renderer *renderer) {
    for(int i = 0; i < MAX_FONTS; i++) {
        removeFontFromRenderer(renderer, i);
    }
    renderer->lastFontIndex = -1;
}

void cleanupRenderer(Renderer *renderer) {
    flushRenderer(renderer);
    flushFontRenderer(renderer);
    SDL_DestroyRenderer(renderer->renderer);
}