#include <SDL2/SDL.h>
#include <stdio.h>

void init(SDL_Window **window, SDL_Renderer **renderer) {
   SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS);

   SDL_Window *windowTmp = SDL_CreateWindow(
            "Pavage",
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            640,
            480,
            SDL_WINDOW_SHOWN
    );

    SDL_Renderer *rendererTmp = SDL_CreateRenderer(windowTmp, -1, SDL_RENDERER_SOFTWARE);

    SDL_SetRenderDrawColor(rendererTmp, 0, 0, 255, 255);
    SDL_RenderClear(rendererTmp);
    SDL_RenderPresent(rendererTmp);

    *window = windowTmp;
    *renderer = rendererTmp;
}

void input(char *keys, char *mouse, int *mousePos, char *events) {
    SDL_Event event;
    while(SDL_PollEvent(&event))
    {
        switch(event.type)
        {
            case SDL_KEYDOWN:
                keys[event.key.keysym.sym] = 0;
                break;
            case SDL_KEYUP:
                keys[event.key.keysym.sym] = 1;
                break;
            case SDL_MOUSEBUTTONDOWN:
                mouse[event.button.button] = 1;
                break;
            case SDL_MOUSEBUTTONUP:
                mouse[event.button.button] = 0;
                break;
            case SDL_MOUSEMOTION:
                mousePos[0] = event.motion.x;
                mousePos[1] = event.motion.y;
                break;
            case SDL_WINDOWEVENT: //not really correct; always set to 1
                events[event.window.event] = 1;
                break;
        }
    }
}

void update(char *keys, char *mouse, int *mousePos) {
    printf("MousePos : %d ; %d\n", mousePos[0], mousePos[1]);
}

void render(SDL_Renderer *renderer) {
    SDL_RenderClear(renderer);

    int x, y;
    SDL_GetMouseState(&x, &y);

    SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);
    SDL_Rect rect = {x, y, 10, 10};
    SDL_RenderFillRect(renderer, &rect);

    SDL_RenderPresent(renderer);

    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
}

void cleanup(SDL_Window* window) {
    SDL_DestroyWindow(window);
    SDL_Quit();
}

int main(int argc, char *argv[])
{
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    init(&window, &renderer);

    char keys[256] = {0};
    char mouse[5] = {0};
    int mousePos[2] = {0};
    char events[20] = {0};

    const short FRAMERATE = 60;

    while(!keys[27] && !events[SDL_WINDOWEVENT_CLOSE]) {
        input(keys, mouse, mousePos, events);
        update(keys, mouse, mousePos);
        render(renderer);

        SDL_Delay(1000 / FRAMERATE);
    }

    cleanup(window);

    return 0;
}