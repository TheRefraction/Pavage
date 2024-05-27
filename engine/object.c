#include "object.h"

Object* initObject(SDL_Renderer *renderer, TTF_Font *fonts[], ObjectData *data) {
    Object* object = (Object*) malloc(sizeof(Object));
    if(data->type == SPRITE) {
        object->surface = SDL_LoadBMP(data->sprite);
    } else if(data->type == TEXT) {
        object->surface = TTF_RenderText_Blended_Wrapped(fonts[data->fontId], data->sprite, data->color, 0);
    } else if(data->type == TILE) {
        Uint8 pixels[96 * 96 * 3] = {0};
        int pitch = 3 * 96;
        for (int dy = 0; dy < 96; dy++) {
            for (int dx = 0; dx < pitch; dx += 3) {
                int index = dx + pitch * dy;
                if (dy % 32 == 0 || dx % 96 == 0) {
                    pixels[index] = 0;
                    pixels[index + 1] = 0;
                    pixels[index + 2] = 0;
                } else {
                    pixels[index] = 255;
                    pixels[index + 1] = 255;
                    pixels[index + 2] = 255;
                }
            }
        }

        Uint32 rmask = 0x000000ff;
        Uint32 gmask = 0x0000ff00;
        Uint32 bmask = 0x00ff0000;
        Uint32 amask = 0xff000000;

        SDL_Surface *surf_tmp = TTF_RenderText_Blended_Wrapped(fonts[data->fontId], data->sprite, data->color, 0);
        object->surface = SDL_CreateRGBSurfaceFrom(pixels, 96, 96, 24, pitch, rmask, gmask, bmask, amask);
        SDL_BlitSurface(surf_tmp, NULL, object->surface, NULL);
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

void cleanupObject(Object *object) {
    if(object != NULL) {
        SDL_DestroyTexture(object->texture);
        SDL_FreeSurface(object->surface);

        free(object);
    }
}