/**
 * @file renderer.h
 * concerns renderer
 */

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

/**
 * initRenderer - Initializes the Rendering system
 * @param renderer Pointer to the renderer to initialize
 * @param handle Window handle to use the renderer in
 */
void initRenderer(Renderer *renderer, SDL_Window *handle);

/**
* addToRenderer - Creates and pushes an new object onto the rendering list
* @param renderer Pointer to the current renderer
* @param data Pointer to the ObjectData to add in
*/
void addToRenderer(Renderer *renderer, ObjectData *data);

/**
 * addFontToRenderer - Pushes a new font onto the fonts list
 * @param renderer Pointer to the current renderer
 * @param filename Filename of the font to add in
 * @param size Size (in px) of the font
 */
void addFontToRenderer(Renderer *renderer, char *filename, unsigned short size);

/**
 * flushRenderer - Destroys all objects in rendering list
 * @param renderer Pointer to the current renderer
 */
void flushRenderer(Renderer *renderer);

/**
 * flushObject - Flush an object from the rendering list to allow updates
 * @param renderer Pointer to the current renderer
 * @param data  Pointer to the current ObjectData to flush
 */
void flushObject(Renderer *renderer, ObjectData *data);

/**
 * cleanupRenderer - Destroys the current renderer and frees memory
 * @param renderer Pointer to the current renderer
 */
void cleanupRenderer(Renderer *renderer);

#endif