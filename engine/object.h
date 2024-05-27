#ifndef OBJECT_H
#define OBJECT_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdbool.h>

typedef enum OBJECT_DATA_TYPE {
    NONE,
    SPRITE,
    TEXT,
    TILE
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

Object* initObject(SDL_Renderer *renderer, TTF_Font *fonts[], ObjectData *data);
ObjectData* initObjectData(int id, ObjectType type, char *sprite, int x, int y, int z, short fontId, float angle, SDL_Color color, SDL_RendererFlip flip, bool isVisible);
void cleanupObject(Object *object);

#endif
