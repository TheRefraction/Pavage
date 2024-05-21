#include <stddef.h>
#include "scene.h"
#include "colors.h"

/** initScene - initialise une nouvelle scène
 *
 * @param scene - scene à preparer
 * @param id - nom de la scene
 */
void initScene(Scene *scene, int id) {
    scene->id = id;
    scene->lastIndex = -1;
    scene->isReady = false;

    for(int i = 0; i < MAX_OBJECTS; i++) {
        scene->data[i] = NULL;
    }
}

/** readyScene - Prépare les objets sur la scène selon son identifiant
 * @param scene - La scène à préparer
 */
void readyScene(Scene *scene) {
    switch(scene->id) {
        case 0: // écran titre
            scene->data[0] = initObjectData(0, SPRITE, "./resources/spr_back.bmp", 0, 0, 0, 0, 0, SDL_GREEN, SDL_FLIP_NONE, true);
            scene->data[1] = initObjectData(1, TEXT, "Hello world", 320, 240, 0, 0, 0, SDL_WHITE, SDL_FLIP_NONE, true);
            scene->data[2] = initObjectData(2, BUTTON, "./resources/spr_btn.bmp", 20, 20, 0, 0, 0, SDL_FUCHSIA, SDL_FLIP_NONE, true);

            break;
    }
    scene->isReady = true;
}

/**
 * updateScene- met à jour la scène
 * @param scene - scène à modifier
 * @param input - action à effectuer
 */
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

/**
 * destroyScene - supprime la scène pour liberer de la memoire
 * @param scene - nom de la scène à detruire
 */
void destroyScene(Scene *scene) {
    for(int i = 0; i < MAX_OBJECTS; i++) {
        if(scene->data[i] != NULL) {
            free(scene->data[i]);
            scene->data[i] = NULL;
        }
    }
}