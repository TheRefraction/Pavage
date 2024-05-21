#include "object.h"

/**
 * initObject- initialise un objet
 * @param renderer
 * @param fonts
 * @param data
 * @return
 */
Object* initObject(SDL_Renderer *renderer, TTF_Font *fonts[], ObjectData *data) {
    Object* object = (Object*) malloc(sizeof(Object));
    if(data->type == SPRITE || data->type == BUTTON) {
        object->surface = SDL_LoadBMP(data->sprite);
    } else if(data->type == TEXT) {
        object->surface = TTF_RenderText_Solid(fonts[data->fontId], data->sprite, data->color);
    }
    if(object->surface) {
        object->texture = SDL_CreateTextureFromSurface(renderer, object->surface);
        if(object->texture) {
            if(data->type == SPRITE) {
                SDL_SetTextureColorMod(object->texture, data->color.r, data->color.g, data->color.b);
            }
            object->data = data;
            return object;
        } else {
            SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failure to create texture:\n%s", SDL_GetError());
            SDL_FreeSurface(object->surface);
        }
    } else {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failure to load surface:\n%s", SDL_GetError());
    }
}

/**
 * initObjectData- prepare les informations d un nouvel objet
 * @param id - nom de l'objet
 * @param type - type de l'objet
 * @param sprite - apparence de l'objet
 * @param x - coordonée x de l'objet
 * @param y - coordonée y de l'objet
 * @param z - profondeur de l'objet
 * @param fontId - police d'ecriture
 * @param angle - rotation de l'objet
 * @param color - couleur de l'objet
 * @param flip - retourne symetriquement l'objet si vrai
 * @param isVisible - visibilité de l'objet
 * @return
 */
ObjectData* initObjectData(int id, ObjectType type, char *sprite, int x, int y, int z, short fontId, float angle, SDL_Color color, SDL_RendererFlip flip, bool isVisible) {
    ObjectData* data = (ObjectData*) malloc(sizeof(ObjectData));
    data->id = id;
    data->type = type;
    data->sprite = sprite;
    data->x = x;
    data->y = y;
    data->z = z;
    data->fontId = fontId;
    data->angle = angle;
    data->color = color;
    data->flip = flip;
    data->isVisible = isVisible;
    data->inRenderer = false;

    return data;
}

/**
 * cleanupObject - supprime l'objet pour liberer la memoire
 * @param object - objet à supprimer
 */
void cleanupObject(Object *object) {
    if(object != NULL) {
        SDL_DestroyTexture(object->texture);
        SDL_FreeSurface(object->surface);

        free(object);
    }
}