#include "game/game.h"

int main(int argc, char *argv[]) {
    SDL_Log("Starting game thread!");

    bool debug = false;
    if(argc == 2) {
        debug = (argv[1]) ? true : false;
        SDL_Log("Debug mode set to %d", debug);
    } else if(argc >= 3) {
        SDL_LogCritical(SDL_LOG_CATEGORY_APPLICATION, "Too many arguments! Process halted!");
        return -1;
    }

    run(debug);

    return 0;
}