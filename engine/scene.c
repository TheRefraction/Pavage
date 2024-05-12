#include <stddef.h>
#include "scene.h"
#include "colors.h"

void initScene(Scene *scene, int id) {
    scene->id = id;
    scene->lastIndex = -1;
    scene->isReady = false;

    for(int i = 0; i < MAX_OBJECTS; i++) {
        scene->data[i] = NULL;
    }
}

void readyScene(Scene *scene) {
    switch(scene->id) {
        case 0:
            scene->data[0] = initObjectData(0, SPRITE, "./resources/spr_back.bmp", 0, 0, 0, 0, 0, SDL_GREEN, SDL_FLIP_NONE, true);
            scene->data[1] = initObjectData(1, TEXT, "Hello world:)", 320, 240, 0, 0, 0, SDL_WHITE, SDL_FLIP_NONE, true);

            break;
    }
    scene->isReady = true;
}

void updateScene(Scene *scene, Input *input) {
    if(!scene->isReady) {
        readyScene(scene);
    } else {
        switch (scene->id) {
            case 0: // TITLE SCREEN
                scene->data[0]->angle += 2;
                //scene->data[1]->angle += 0.5;
                if (input->keys[SDL_SCANCODE_UP]) {
                    scene->data[0]->y--;
                } else if (input->keys[SDL_SCANCODE_DOWN]) {
                    scene->data[0]->y++;
                }
                break;
            case 1: // OPTION SCREEN

                break;
            case 2: // GAME SELECTION SCREEN

                break;
            case 3: // GAME 1-PLAYER

                break;
            case 4: // GAME 2-PLAYERS

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