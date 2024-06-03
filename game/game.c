#include "game.h"

#include "../engine/window.h"
#include "constants.h"

void init(Window *window, Renderer *renderer, Input *input, Scene *scene) {
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

    if (TTF_Init() < 0){
        SDL_LogCritical(SDL_LOG_CATEGORY_APPLICATION, "Couldn't initialize SDL_ttf!\n%s", TTF_GetError());

        SDL_Quit();
        return;
    }

    TTF_VERSION(&compiled);

    if (compiled.major != linked.major){
        SDL_LogCritical(SDL_LOG_CATEGORY_APPLICATION,"SDL_ttf versions mismatch!");

        SDL_Quit();
        return;
    }

    initWindow(window, WINDOW_TITLE, WINDOW_WIDTH, WINDOW_HEIGHT);
    initRenderer(renderer, window->handle);
    initInput(input);
    initScene(scene, 0);
}

void run(bool debug) {
    Window window;
    Renderer renderer;
    Input input;
    Scene scene;
    SDL_Event event;

    init(&window, &renderer, &input, &scene);

    addFontToRenderer(&renderer, "./resources/default.ttf", 12);
    addFontToRenderer(&renderer, "./resources/default.ttf", 20);
    addFontToRenderer(&renderer, "./resources/default.ttf", 24);
    addFontToRenderer(&renderer, "./resources/default.ttf", 32);
    addFontToRenderer(&renderer, "./resources/default.ttf", 48);

    showWindow(&window);

    while(!window.isClosing) {
        while(SDL_PollEvent(&event)) {
            updateWindow(&window, event);
            updateInput(&input, event);
        }

        if(window.isVisible && window.hasMouseFocus && !scene.flags[0]) {
            updateScene(&scene, &input, &window);

            if(scene.flags[0]) {
                flushRenderer(&renderer);
                scene.flags[0] = false;
            } else {
                render(&renderer, &scene);
            }
        }

        SDL_Delay(1000 / FRAMERATE);
    }

    cleanupRenderer(&renderer);
    destroyScene(&scene); // Maybe unnecessary

    close(window.handle);
}

void render(Renderer *renderer, Scene *scene) {
    SDL_RenderClear(renderer->renderer);

    for(int i = 0; i < MAX_OBJECTS; i++) {
        if(scene->data[i] != NULL && !scene->data[i]->inRenderer) {
            addToRenderer(renderer, scene->data[i]);
            scene->data[i]->inRenderer = true;
        }

        if(renderer->objects[i] != NULL && scene->data[i]->isVisible) {
            Object* object = renderer->objects[i];
            SDL_Rect dest = {object->data->x, object->data->y, object->surface->w, object->surface->h};
            SDL_RenderCopyEx(renderer->renderer, renderer->objects[i]->texture, NULL, &dest, object->data->angle, NULL, object->data->flip);
        }
    }

    SDL_RenderPresent(renderer->renderer);

    SDL_SetRenderDrawColor(renderer->renderer, 0, 0, 0, 255);
}

void close(SDL_Window *window) {
    TTF_Quit();
    SDL_DestroyWindow(window);
    SDL_Quit();
}