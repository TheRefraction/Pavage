#include "scene.h"
#include "colors.h"
#include "gui.h"

#include "../game/tile.h"

#include <stddef.h>

void initScene(Scene *scene, int id) {
    scene->id = id;
    scene->lastIndex = -1;
    scene->isReady = false;

    for(int i = 0; i < MAX_OBJECTS; i++) {
        scene->data[i] = NULL;
    }

    for(int i = 0; i < 256; i++) {
        scene->flags[i] = 0;
    }
}

/** readyScene - Readies the scene according its ID
 * @param scene Pointer on the current scene
 */

void readyScene(Scene *scene) {
    switch(scene->id) {
        case 0: // Title screen
            initObjectData(scene->data, 0, SPRITE, "./resources/spr_back.bmp", 0, 0, 0, 0, 0, SDL_WHITE, SDL_FLIP_NONE, true);
            initObjectData(scene->data, 1, TEXT, "PAVAGE", 260, 24, 0, 4, 0, SDL_WHITE, SDL_FLIP_NONE, true);

            // buttons of main screen
            initObjectData(scene->data, 2, SPRITE, "./resources/spr_btn_newgame.bmp", 336, 200, 0, 0, 0, SDL_WHITE, SDL_FLIP_NONE, true);
            initObjectData(scene->data, 3, SPRITE, "./resources/spr_btn_continue.bmp", 336, 256, 0, 0, 0, SDL_GRAY, SDL_FLIP_NONE, true);
            initObjectData(scene->data, 4, SPRITE, "./resources/spr_btn_exit.bmp", 336, 312, 0, 0, 0, SDL_WHITE, SDL_FLIP_NONE, true);

            // how many players buttons
            initObjectData(scene->data, 5, SPRITE, "./resources/spr_btn_onep.bmp", 336, 202, 0, 0, 0, SDL_WHITE, SDL_FLIP_NONE, false);
            initObjectData(scene->data, 6, SPRITE, "./resources/spr_btn_twop.bmp", 336, 258, 0, 0, 0, SDL_WHITE, SDL_FLIP_NONE, false);

            // difficulties buttons
            initObjectData(scene->data, 7, SPRITE, "./resources/spr_btn_d1.bmp", 336, 202, 0, 0, 0, SDL_WHITE, SDL_FLIP_NONE, false);
            initObjectData(scene->data, 8, SPRITE, "./resources/spr_btn_d2.bmp", 336, 258, 0, 0, 0, SDL_WHITE, SDL_FLIP_NONE, false);

            //which size ?
            initObjectData(scene->data, 9, SPRITE, "./resources/spr_btn_s1.bmp", 336, 202, 0, 0, 0, SDL_WHITE, SDL_FLIP_NONE, false);
            initObjectData(scene->data, 10, SPRITE, "./resources/spr_btn_s2.bmp", 336, 258, 0, 0, 0, SDL_WHITE, SDL_FLIP_NONE, false);
            initObjectData(scene->data, 11, SPRITE, "./resources/spr_btn_s3.bmp", 336, 314, 0, 0, 0, SDL_WHITE, SDL_FLIP_NONE, false);

            break;
        case 1: // One Player
            int x_tmp, y_tmp;
            char *str1, *str2;

            if (scene->flags[4] == 0) {
                x_tmp = 304;
                y_tmp = 202;
                str1 = "A   B   C   D   E   F";
                str2 = "1\n2\n3";
            } else if (scene->flags[4] == 1) {
                x_tmp = 208;
                y_tmp = 154;
                str1 = "A   B   C   D   E   F   G   H   I   J   K   L";
                str2 = "1\n2\n3\n4\n5\n6";
            } else {
                x_tmp = 112;
                y_tmp = 106;
                str1 = "A   B   C   D   E   F   G   H   I   J   K   L   M   N   O   P   Q   R";
                str2 = "1\n2\n3\n4\n5\n6\n7\n8\n9";
            }

            initObjectData(scene->data, 0, SPRITE, "./resources/spr_back.bmp", 0, 0, 0, 0, 0, SDL_PURPLE, SDL_FLIP_NONE, true);
            initObjectData(scene->data, 1, SPRITE, "./resources/spr_btn_opt.bmp", 10, 10, 0, 0, 0, SDL_WHITE, SDL_FLIP_NONE, true);

            initObjectData(scene->data, 2, GRID, "", x_tmp, y_tmp, scene->flags[4], 3, 0, SDL_BLACK, SDL_FLIP_NONE, true);
            initObjectData(scene->data, 3, TEXT, str1, x_tmp + 10, y_tmp - 32, 0, 3, 0, SDL_WHITE, SDL_FLIP_NONE, true);
            initObjectData(scene->data, 4, TEXT, str2, x_tmp - 32, y_tmp, 0, 3, 0, SDL_WHITE, SDL_FLIP_NONE, true);

            // Hand of 5 tiles
            initObjectData(scene->data, 5, TILE, "", 144, 500, 0, 3, 0, SDL_BLACK, SDL_FLIP_NONE, true);
            initObjectData(scene->data, 6, TILE, "", 248, 500, 0, 3, 0, SDL_BLACK, SDL_FLIP_NONE, true);
            initObjectData(scene->data, 7, TILE, "", 352, 500, 0, 3, 0, SDL_BLACK, SDL_FLIP_NONE, true);
            initObjectData(scene->data, 8, TILE, "", 456, 500, 0, 3, 0, SDL_BLACK, SDL_FLIP_NONE, true);
            initObjectData(scene->data, 9, TILE, "", 560, 500, 0, 3, 0, SDL_BLACK, SDL_FLIP_NONE, true);

            initArray(scene->data[2]->sprite, 256, ' ');

            int flags = 0;
            if (scene->flags[2]) flags |= 1;
            if (scene->flags[1]) flags |= 2;

            for(int i = 5; i < 10; i++) {
                generateTile(scene->data[i]->sprite, flags);
            }

            break;
        case 2: // Two players
            break;
    }
    scene->isReady = true;
}

void changeScene(Scene *scene, int id) {
    scene->flags[0] = 1;
    scene->id = id;
    destroyScene(scene);
}

void updateScene(Scene *scene, Input *input, Window *window) {
    if(!scene->isReady) {
        readyScene(scene);
    } else {
        switch (scene->id) {
            case 0: // TITLE SCREEN
                if(input->mouse[SDL_BUTTON_LEFT]) {
                    if (scene->flags[3]) return;
                    scene->flags[3] = 1;

                    if (isOnObject(scene, 2, input)) { // New game
                        scene->data[2]->isVisible=false;
                        scene->data[3]->isVisible=false;
                        scene->data[4]->isVisible=false;

                        scene->data[5]->isVisible=true;
                        scene->data[6]->isVisible=true;
                    } else if (isOnObject(scene, 3, input)) { // Continue

                    } else if (isOnObject(scene, 4, input)) { // Exit
                        window->isClosing = true;
                    } else if (isOnObject(scene, 5, input)) {
                        scene->data[5]->isVisible=false;
                        scene->data[6]->isVisible=false;

                        scene->data[7]->isVisible=true;
                        scene->data[8]->isVisible=true;
                    } else if (isOnObject(scene, 6, input)) {
                        scene->flags[1] = 1;

                        scene->data[5]->isVisible=false;
                        scene->data[6]->isVisible=false;

                        scene->data[7]->isVisible=true;
                        scene->data[8]->isVisible=true;
                    } else if (isOnObject(scene, 7, input)) {
                        scene->data[7]->isVisible=false;
                        scene->data[8]->isVisible=false;

                        scene->data[9]->isVisible=true;
                        scene->data[10]->isVisible=true;
                        scene->data[11]->isVisible=true;
                    } else if (isOnObject(scene, 8, input)) {
                        scene->flags[2] = 1;

                        scene->data[7]->isVisible=false;
                        scene->data[8]->isVisible=false;

                        scene->data[9]->isVisible=true;
                        scene->data[10]->isVisible=true;
                        scene->data[11]->isVisible=true;
                    } else if (isOnObject(scene, 9, input)) {
                        scene->flags[3] = 0;
                        scene->flags[4] = 0;

                        changeScene(scene, scene->flags[1] ? 2 : 1);
                    } else if (isOnObject(scene, 10, input)) {
                        scene->flags[3] = 0;
                        scene->flags[4] = 1;

                        changeScene(scene, scene->flags[1] ? 2 : 1);
                    } else if (isOnObject(scene, 11, input)) {
                        scene->flags[3] = 0;
                        scene->flags[4] = 2;

                        changeScene(scene, scene->flags[1] ? 2 : 1);
                    }
                } else {
                    scene->flags[3] = 0;
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
            if(scene->data[i]->sprite != NULL) {
                free(scene->data[i]->sprite);
                scene->data[i]->sprite = NULL;
            }
            free(scene->data[i]);
            scene->data[i] = NULL;
        }
    }
    scene->lastIndex = -1;
    scene->isReady = false;
}
