#include "object.h"

void initObject(Object *object, SDL_Renderer *renderer, char* sprite, int x, int y, int z) {
    object->sprite = SDL_LoadBMP(sprite);
    if(object->sprite) {
        object->texture = SDL_CreateTextureFromSurface(renderer, object->sprite);
        if(object->texture) {
            object->x = x;
            object->y = y;
            object->z = z;
        } else {
            SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failure to create texture:\n%s", SDL_GetError());
            SDL_FreeSurface(object->sprite);
            return;
        }
    } else {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failure to load sprite:\n%s", SDL_GetError());
        return;
    }
}

void updateObject(Object *object, int x, int y, int z) {

}

void cleanupObject(Object *object) {
    if(object != NULL) {
        SDL_DestroyTexture(object->texture);
        SDL_FreeSurface(object->sprite);
    }
}