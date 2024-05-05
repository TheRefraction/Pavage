#ifndef INPUT_H
#define INPUT_H

#include <stdbool.h>
#include "SDL2/SDL.h"

typedef struct INPUT_STRUCT {
    bool keys[256];
    bool mouse[5];
    int scroll;
    int cursor[2];
} Input;

void initInput(Input *input);
void updateInput(Input *input, SDL_Event event);

#endif
