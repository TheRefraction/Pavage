#include <stddef.h>
#include "scene.h"

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
            scene->data[0] = initObjectData(0, "./resources/spr_back.bmp", 0, 30, 0, 0, SDL_FLIP_NONE, true, false);

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