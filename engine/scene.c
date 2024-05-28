#include <stddef.h>
#include "scene.h"
#include "colors.h"
#include "gui.h"

void initScene(Scene *scene, int id) {
    scene->id = id;
    scene->lastIndex = -1;
    scene->isReady = false;

    for(int i = 0; i < MAX_OBJECTS; i++) {
        scene->data[i] = NULL;
    }
}

/** readyScene - Readies the scene according its ID
 * @param scene Pointer on the current scene
 */

void readyScene(Scene *scene) {
    switch(scene->id) {
        case 0: // Title screen
            scene->data[0] = initObjectData(0, SPRITE, "./resources/spr_back.bmp", 0, 0, 0, 0, 0, SDL_WHITE, SDL_FLIP_NONE, true);
            scene->data[1] = initObjectData(1, TEXT, "PAVAGE", 260, 24, 0, 4, 0, SDL_WHITE, SDL_FLIP_NONE, true);
            scene->data[2] = initObjectData(2, TILE, "  X  -1  X\n  X        X\n  1   X   X", 320, 240, 0, 3, 0, SDL_BLACK, SDL_FLIP_NONE, true);
            scene->data[3] = initObjectData(3, SPRITE, "./resources/spr_btn.bmp", 0, 0, 0, 0, 0, SDL_WHITE, SDL_FLIP_NONE, true);
            scene->data[4] = initObjectData(4, SPRITE, "./resources/spr_btn.bmp", 97, 0, 0, 0, 0, SDL_WHITE, SDL_FLIP_NONE, true);
            scene->data[5] = initObjectData(5, SPRITE, "./resources/spr_btn.bmp", 194, 0, 0, 0, 0, SDL_WHITE, SDL_FLIP_NONE, true);
            scene->data[6] = initObjectData(6, SPRITE, "./resources/spr_btn.bmp", 300, 300, 0, 0, 0, SDL_WHITE, SDL_FLIP_NONE, false);
            scene->data[7] = initObjectData(7, SPRITE, "./resources/spr_btn.bmp", 400, 400, 0, 0, 0, SDL_WHITE, SDL_FLIP_NONE, false);
            break;
    }
    scene->isReady = true;
}

void updateScene(Scene *scene, Input *input, Window *window) {
    if(!scene->isReady) {
        readyScene(scene);
    } else {
        switch (scene->id) {
            case 0: // TITLE SCREEN
                if(input->mouse[SDL_BUTTON_LEFT]) {
                    if (isOnObject(scene, 2, input)) { // New game
                        scene->data[2]->isVisible=false;
                        scene->data[3]->isVisible=false;
                        scene->data[4]->isVisible=false;

                        scene->data[6]->isVisible=true;
                        scene->data[7]->isVisible=true;
                    } else if (isOnObject(scene, 3, input)) { // Continue

                    } else if (isOnObject(scene, 4, input)) { // Exit
                        window->isClosing = true;
                    }
                }

                break;
            case 1: // GAME 1-PLAYER

                break;
            case 2: // GAME 2-PLAYERS

                break;
            default: // NULL SCENE
                return;
        }
    }
}

void destroyScene(Scene *scene) {
    for(int i = 0; i < MAX_OBJECTS; i++) {
        if(scene->data[i] != NULL) {
            free(scene->data[i]);
            scene->data[i] = NULL;
        }
    }
}
