#include "game.h"

#include "../engine/window.h"
#include "constants.h"

void init() {
    SDL_version compiled, linked;

    if(SDL_Init (SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_EVENTS) != 0) {
        SDL_LogCritical(SDL_LOG_CATEGORY_APPLICATION, "Couldn't initialize SDL!\n%s", SDL_GetError());

        SDL_Quit();
        return;
    }

    SDL_VERSION(&compiled);
    SDL_GetVersion(&linked);

    if (compiled.major != linked.major){
        SDL_LogCritical(SDL_LOG_CATEGORY_APPLICATION,"SDL versions mismatch!");

        SDL_Quit();
        return;
    }

    SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION,"SDL Version %u.%u.%u", linked.major, linked.minor, linked.patch);
}

void run(bool debug) {
    init();

    Window window;
    Renderer renderer;
    Input input;
    SDL_Event event;

    initWindow(&window, WINDOW_TITLE, WINDOW_WIDTH, WINDOW_HEIGHT);
    initRenderer(&renderer, window.handle);
    initInput(&input);

    showWindow(&window);

    // testObject
    Object testObject;
    initObject(&testObject, renderer.renderer, "./resources/spr_test.bmp", 200, 200, 0);
    renderer.objects[0] = &testObject;

    while(!window.isClosing && !input.keys[SDLK_ESCAPE]) {
        while(SDL_PollEvent(&event)) {
            updateWindow(&window, event);
            updateInput(&input, event);
        }

        if(window.isVisible && window.hasMouseFocus) {
            update(&input, renderer.objects);
            render(&renderer);
        }

        SDL_Delay(1000 / FRAMERATE);
    }

    cleanupRenderer(&renderer);
    close(window.handle);
}

void update(Input *input, Object *objects[]) {
    //update everything else here
    objects[0]->x = input->cursor[0];
    objects[0]->y = input->cursor[1];
}

void render(Renderer *renderer) {
    SDL_RenderClear(renderer->renderer);

    for(int i = 0; i < 128; i++) {
        if(renderer->objects[i] != NULL) {
            Object *object = renderer->objects[i];
            SDL_Rect dest = {object->x, object->y, object->sprite->w, object->sprite->h};
            SDL_RenderCopy(renderer->renderer, renderer->objects[i]->texture, NULL, &dest);
        }
    }

    SDL_RenderPresent(renderer->renderer);

    SDL_SetRenderDrawColor(renderer->renderer, 0, 0, 0, 255);
}

void close(SDL_Window *window) {
    SDL_DestroyWindow(window);
    SDL_Quit();
}