#include "object.h"

Object initObject(SDL_Renderer *renderer, ObjectData data) {
    Object object;
    object.sprite = SDL_LoadBMP(data.sprite);
    if(object.sprite) {
        object.texture = SDL_CreateTextureFromSurface(renderer, object.sprite);
        if(object.texture) {
            object.null = false;
            object.data.id = data.id;
            object.data.sprite = data.sprite;
            object.data.x = data.x;
            object.data.y = data.y;
            object.data.z = data.z;
            return object;
        } else {
            SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failure to create texture:\n%s", SDL_GetError());
            SDL_FreeSurface(object.sprite);
        }
    } else {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failure to load sprite:\n%s", SDL_GetError());
    }
}

void cleanupObject(Object *object) {
    /*if(object != NULL) {
        SDL_DestroyTexture(object->texture);
        SDL_FreeSurface(object->sprite);
    }*/
}