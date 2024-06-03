#include "object.h"
#include "colors.h"

Object* initObject(SDL_Renderer *renderer, TTF_Font *fonts[], ObjectData *data) {
    Object* object = (Object*) malloc(sizeof(Object));
    if(data->type == SPRITE) {
        object->surface = SDL_LoadBMP(data->sprite);
    } else if(data->type == TEXT) {
        object->surface = TTF_RenderText_Blended_Wrapped(fonts[data->fontId], data->sprite, data->color, 0);
    } else if(data->type == TILE || data->type == GRID) {
        int width = 96;
        int height = 96;
        int sizeData = 9;

        if(data->type == GRID) {
            if(data->z == 0) {
                width = 192;
                height = 96;
                sizeData = 18;
            } else if(data->z == 1) {
                width = 384;
                height = 192;
                sizeData = 72;
            } else if(data->z == 2) {
                width = 576;
                height = 288;
                sizeData = 162;
            }
        }

        int pitch = 3 * width;
        Uint8 *pixels = (Uint8*) malloc(pitch * height * sizeof(Uint8));

        for (int dy = 0; dy < height; dy++) {
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

        SDL_Surface *surf_tmp;
        object->surface = SDL_CreateRGBSurfaceFrom(pixels, width, height, 24, pitch, 0x000000ff, 0x0000ff00, 0x00ff0000, 0xff000000);

        for(int i = 0; i < sizeData; i++) {
            char c[2] = {data->sprite[i], '\0'};
            int line = width / 32;
            SDL_Rect dest = {10 + 32 * (i % line), 32 * (i / line), 32, 32};
            surf_tmp = TTF_RenderText_Blended(fonts[data->fontId], c, SDL_BLACK);
            SDL_BlitSurface(surf_tmp, NULL, object->surface, &dest);
        }

        SDL_FreeSurface(surf_tmp);
        free(pixels);
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