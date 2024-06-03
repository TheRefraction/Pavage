#ifndef OBJECT_H
#define OBJECT_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdbool.h>

typedef enum OBJECT_DATA_TYPE {
    NONE,
    SPRITE,
    TEXT,
    TILE,
    GRID
} ObjectType;

typedef struct OBJECT_DATA_STRUCT {
    int id;
    ObjectType type;
    char *sprite;
    int x;
    int y;
    int z;
    short fontId;
    float angle;
    SDL_Color color;
    SDL_RendererFlip flip;
    bool inRenderer;
    bool isVisible;
} ObjectData;

typedef struct OBJECT_STRUCT {
    ObjectData *data;
    SDL_Surface *surface;
    SDL_Texture *texture;
} Object;

/**
 * initObject - Initializes a new object
 * @param renderer The SDL_Renderer used in the current window
 * @param fonts Array of TTF_Font to use
 * @param data ObjectData of the object to create
 * @return Object*
 */
Object* initObject(SDL_Renderer *renderer, TTF_Font *fonts[], ObjectData *data);

/**
 * initObjectData - Initializes the data of a new object
 * @param id ID in the scene
 * @param type Type of object
 * @param sprite String that contains either a filename, or a text to render
 * @param x X-Coordinate
 * @param y Y-Coordinate
 * @param z Depth (unused)
 * @param fontId The font ID to use (0 when SPRITE)
 * @param angle Angle in degrees of rotation around the center of the sprite
 * @param color Blend of the sprite
 * @param flip Flip the sprite
 * @param isVisible Visibility of the object
 * @return ObjectData*
 */
ObjectData* initObjectData(int id, ObjectType type, char *sprite, int x, int y, int z, short fontId, float angle, SDL_Color color, SDL_RendererFlip flip, bool isVisible);

/**
 * cleanupObject - Destroys the object specified and frees memory
 * @param object Object to destroy
 */
void cleanupObject(Object *object);

#endif