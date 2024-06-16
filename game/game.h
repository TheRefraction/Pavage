/**
 * @file game.h
 * concerns game
 */

#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include <stdbool.h>
#include <time.h>

#include "../engine/renderer.h"
#include "../engine/input.h"
#include "../engine/scene.h"
#include "../engine/window.h"

void run(bool debug);
void render(Renderer *renderer, Scene *scene);
void close(SDL_Window *window);

#endif