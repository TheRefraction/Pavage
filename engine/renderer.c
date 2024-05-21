#include "renderer.h"

/**
 * initRenderer - Initialize the Rendering system
 * @param renderer - Pointer towards a Renderer STRUCT
 * @param handle - Window handle to use the renderer in
 */
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

/**
 * addFontToRenderer -
 * @param renderer
 * @param filename
 * @param size
 */
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
 * removeFontRenderer-
 * @param renderer
 * @param i
 */
void removeFontFromRenderer(Renderer *renderer, int i) {
    if(renderer->fonts[i] != NULL) {
        TTF_CloseFont(renderer->fonts[i]);
        renderer->fonts[i] = NULL;
    }
}

/**
 * addToRenderer-
 * @param renderer
 * @param data
 */
void addToRenderer(Renderer *renderer, ObjectData *data) {
    renderer->objects[data->id] = initObject(renderer->renderer, renderer->fonts, data);
}


/**
 * removeFromRenderer- supprime un element du rendu
 * @param renderer-rendu
 * @param i
 */
void removeFromRenderer(Renderer *renderer, int i) {
    cleanupObject(renderer->objects[i]);
    renderer->objects[i] = NULL;
}

/**
 * flushRenderer-
 * @param renderer
 */
void flushRenderer(Renderer *renderer) {
    for(int i = 0; i < MAX_OBJECTS; i++) {
        removeFromRenderer(renderer, i);
    }
}

/**
 * flushFontRenderer-
 * @param renderer
 */
void flushFontRenderer(Renderer *renderer) {
    for(int i = 0; i < MAX_FONTS; i++) {
        removeFontFromRenderer(renderer, i);
    }
    renderer->lastFontIndex = -1;
}

/**
 * cleanupRenderer- supprime pour liberer de la memoire
 * @param renderer
 */
void cleanupRenderer(Renderer *renderer) {
    flushRenderer(renderer);
    flushFontRenderer(renderer);
    SDL_DestroyRenderer(renderer->renderer);
}