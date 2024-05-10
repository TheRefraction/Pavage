#ifndef OBJECT_H
#define OBJECT_H

#include <SDL2/SDL.h>
#include <stdbool.h>

typedef struct OBJECT_DATA_STRUCT {
    int id;
    char *sprite;
    int x;
    int y;
    int z;
    float angle;
    SDL_RendererFlip flip;
    bool inRenderer;
    bool isVisible;
    bool isUpdatable;
} ObjectData;

typedef struct OBJECT_STRUCT {
    ObjectData *data;
    SDL_Surface *sprite;
    SDL_Texture *texture;
} Object;

Object* initObject(SDL_Renderer *renderer, ObjectData *data);
ObjectData* initObjectData(int id, char *sprite, int x, int y, int z, float angle, SDL_RendererFlip flip, bool isVisible, bool isUpdatable);
void cleanupObject(Object *object);

#endif
