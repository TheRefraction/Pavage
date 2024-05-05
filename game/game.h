#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <stdbool.h>
#include "../engine/renderer.h"
#include "../engine/input.h"

void run(bool debug);
void update(Input *input, Object *objects[]);
void render(Renderer *renderer);
void close(SDL_Window *window);

#endif
