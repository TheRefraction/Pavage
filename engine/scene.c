#include "scene.h"

#include <SDL2/SDL.h>

void initScene(Scene *scene, int id) {
    scene->id = id;
    scene->lastIndex = -1;
    scene->isReady = false;

    for(int i = 0; i < MAX_OBJECTS; i++) {
        ObjectData data;
        data.null = true;
        scene->objects[i] = data;
    }
}
void readyScene(Scene *scene) {
    switch(scene->id) {
        case 0:
            scene->objects[0].id = 0;
            scene->objects[0].x = 0;
            scene->objects[0].y = 0;
            scene->objects[0].z = 0;
            scene->objects[0].null = false;
            scene->objects[0].renderered = false;
            scene->objects[0].isVisible = true;
            scene->objects[0].isUpdatable = false;
            scene->objects[0].sprite = "./resources/spr_back.bmp";

            break;
    }
    scene->isReady = true;
}

void updateScene(Scene *scene) {
    if(!scene->isReady) {
        readyScene(scene);
    }

    switch(scene->id) {
        case 0: // TITLE SCREEN
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