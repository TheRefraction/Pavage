#include "scene.h"

void initScene(Scene *scene, int id) {
    scene->id = id;

    for(int i = 0; i < MAX_OBJECTS; i++) {
        scene->objects[i] = NULL;
    }
}

void updateScene(Scene *scene) {
    if(scene->id == -1) {
        return;
    }

    for(int i = 0; i < MAX_OBJECTS; i++) {
        updateObject(scene->objects[i], 0, 0, 0); //TO REDO
    }
}

void destroyScene(Scene *scene) {
    scene->id = -1;
    for(int i = 0; i < MAX_OBJECTS; i++) {
        cleanupObject(scene->objects[i]);
        scene->objects[i] = NULL;
    }
}