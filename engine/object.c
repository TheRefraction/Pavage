#include "object.h"

Object* initObject(SDL_Renderer *renderer, ObjectData *data) {
    Object* object = (Object*) malloc(sizeof(Object));
    object->sprite = SDL_LoadBMP(data->sprite);
    if(object->sprite) {
        object->texture = SDL_CreateTextureFromSurface(renderer, object->sprite);
        if(object->texture) {
            object->data = data;
            return object;
        } else {
            SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failure to create texture:\n%s", SDL_GetError());
            SDL_FreeSurface(object->sprite);
        }
    } else {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failure to load sprite:\n%s", SDL_GetError());
    }
}

ObjectData* initObjectData(int id, char *sprite, int x, int y, int z, float angle, SDL_RendererFlip flip, bool isVisible, bool isUpdatable) {
    ObjectData* data = (ObjectData*) malloc(sizeof(ObjectData));
    data->id = id;
    data->sprite = sprite;
    data->x = x;
    data->y = y;
    data->z = z;
    data->angle = angle;
    data->flip = flip;
    data->isVisible = isVisible;
    data->isUpdatable = isUpdatable;
    data->inRenderer = false;

    return data;
}

void cleanupObject(Object *object) {
    if(object != NULL) {
        SDL_DestroyTexture(object->texture);
        SDL_FreeSurface(object->sprite);

        free(object);
    }
}