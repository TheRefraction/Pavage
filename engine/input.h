#ifndef INPUT_H
#define INPUT_H
/**
 * @file input.h
 * concerne les imputs
 */
#include <stdbool.h>
#include "SDL2/SDL.h"

typedef struct INPUT_STRUCT {
    bool keys[256];
    bool mouse[5];
    int scroll;
    int cursor[2];
} Input;

/**
 * initInput - Initialize the input system
 * @param input Pointer on the input system
 */
void initInput(Input *input);

/**
 * updateInput - Updates keyboard and mouse inputs
 * @param input Pointer on the input system
 * @param event The SDL_Event of the current window
 */
void updateInput(Input *input, SDL_Event event);

#endif
