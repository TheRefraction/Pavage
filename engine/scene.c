#include <stddef.h>
#include "scene.h"
#include "colors.h"
#include "gui_elements.h"


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
        case 0: // Title screen
            scene->data[0] = initObjectData(0, SPRITE, "./resources/spr_back.bmp", 0, 0, 0, 0, 0, SDL_FUCHSIA, SDL_FLIP_NONE, true);
            scene->data[1] = initObjectData(1, TEXT, "PAVAGE", 260, 24, 0, 4, 0, SDL_WHITE, SDL_FLIP_NONE, true);
            scene->data[2] = initObjectData(2, TILE, "  X  -1  X\n  X        X\n  1   X   X", 320, 240, 0, 3, 0, SDL_BLACK, SDL_FLIP_NONE, true);
            scene->data[3] = initObjectData(3, SPRITE, "./resources/spr_btn.bmp", 0, 0, 0, 0, 0, SDL_WHITE, SDL_FLIP_NONE, true);
            scene->data[4] = initObjectData(4, SPRITE, "./resources/spr_btn.bmp", 97, 0, 0, 0, 0, SDL_WHITE, SDL_FLIP_NONE, true);
            scene->data[5] = initObjectData(5, SPRITE, "./resources/spr_btn.bmp", 194, 0, 0, 0, 0, SDL_WHITE, SDL_FLIP_NONE, true);
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
                /*scene->data[0]->angle += 2;
                if (input->keys[SDL_SCANCODE_UP]) {
                    scene->data[0]->y--;
                } else if (input->keys[SDL_SCANCODE_DOWN]) {
                    scene->data[0]->y++;
                }*/

                if (isOnObject(scene, 3, input) && input->mouse[SDL_BUTTON_LEFT]) { //si on est le boutton 1 et qu'on clique dessus :
                    scene->data[3]->angle++;  //alors le boutton tourne
                }
                if (isOnObject(scene, 4, input) && input->mouse[SDL_BUTTON_LEFT]) { //si on est le boutton 2 et qu'on clique dessus :
                    scene->data[4]->angle++;  //alors le boutton tourne
                }
                if (isOnObject(scene, 5, input) && input->mouse[SDL_BUTTON_LEFT]) { //si on est le boutton 3 et qu'on clique dessus :
                    scene->data[5]->angle++;  //alors le boutton tourne
                }

                break;
            case 1: // GAME SELECTION SCREEN

                break;
            case 2: // GAME 1-PLAYER

                break;
            case 3: // GAME 2-PLAYERS

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