#include "input.h"

void initInput(Input *input) {
    for(int i = 0; i < 256; i++) {
        input->keys[i] = false;
    }

    for(int i = 0; i < 5; i++) {
        input->mouse[i] = false;
    }
    input->cursor[0] = -1;
    input->cursor[1] = -1;

    input->scroll = 0;
}

void updateInput(Input *input, SDL_Event event) {
    switch(event.type)
    {
        case SDL_KEYDOWN:
            input->keys[SDL_GetScancodeFromKey(event.key.keysym.sym)] = true;
            break;
        case SDL_KEYUP:
            input->keys[SDL_GetScancodeFromKey(event.key.keysym.sym)] = false;
            break;
        case SDL_MOUSEBUTTONDOWN:
            input->mouse[event.button.button] = true;
            break;
        case SDL_MOUSEBUTTONUP:
            input->mouse[event.button.button] = false;
            break;
        case SDL_MOUSEWHEEL:
            input->scroll = event.wheel.y;
            break;
        case SDL_MOUSEMOTION:
            input->cursor[0] = event.motion.x;
            input->cursor[1] = event.motion.y;
            break;
    }
}

