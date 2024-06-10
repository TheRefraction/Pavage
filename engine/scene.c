#include "scene.h"
#include "colors.h"
#include "gui.h"

#include "../game/tile.h"

#include <stddef.h>
#include <stdio.h>
#include <ctype.h>

void initScene(Scene *scene, short id) {
    scene->id = id;
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

            // Misc
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

            initObjectData(scene->data, 0, SPRITE, "./resources/spr_back_1.bmp", 0, 0, 0, 0, 0, SDL_PURPLE,SDL_FLIP_NONE, true);
            initObjectData(scene->data, 1, SPRITE, "./resources/spr_btn_opt.bmp", 10, 10, 0, 0, 0, SDL_WHITE,SDL_FLIP_NONE, true);

            // Game Grid
            initObjectData(scene->data, 2, GRID, "", x_tmp, y_tmp, scene->flags[4], 3, 0, SDL_BLACK, SDL_FLIP_NONE,true);
            initObjectData(scene->data, 3, TEXT, str1, x_tmp + 10, y_tmp - 32, 0, 3, 0, SDL_WHITE, SDL_FLIP_NONE, true);
            initObjectData(scene->data, 4, TEXT, str2, x_tmp - 32, y_tmp, 0, 3, 0, SDL_WHITE, SDL_FLIP_NONE, true);

            initArray(scene->data[2]->sprite, 256, ' ');

            int flags = 0;
            if (scene->flags[2]) flags |= 1;
            if (scene->flags[1]) flags |= 2;

            scene->flags[7] = 0;
            scene->flags[9] = 0;

            // Hand of 5 tiles
            for (int i = 5; i < 10; i++) {
                initObjectData(scene->data, i, TILE, "", 144 + 104 * (i - 5), 500, 0, 3, 0, SDL_BLACK, SDL_FLIP_NONE, true);
                generateTile(scene->data[i]->sprite, flags);
            }

            initObjectData(scene->data, 12, TEXT, "SCORE: 0", 600, 12, 0, 2, 0, SDL_WHITE, SDL_FLIP_NONE, true);
            initObjectData(scene->data, 13, TEXT, "ACT: Selectionnez une tuile", 16, 440, 0, 2, 0, SDL_WHITE, SDL_FLIP_NONE, true);

            break;
        case 2: // Two players

            scene->flags[7] = 0;
            scene->flags[8] = 0;
            scene->flags[9] = 0;
            break;
    }
    scene->isReady = true;
}

void changeScene(Scene *scene, short id) {
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

                    if (isOnObject(scene, 2, input, 128, 48)) { // New game
                        scene->data[2]->isVisible = false;
                        scene->data[3]->isVisible = false;
                        scene->data[4]->isVisible = false;

                        scene->data[5]->isVisible = true;
                        //scene->data[6]->isVisible = true;
                    } else if (isOnObject(scene, 3, input, 128, 48)) { // Continue

                    } else if (isOnObject(scene, 4, input, 128, 48)) { // Exit
                        window->isClosing = true;
                    } else if (isOnObject(scene, 5, input, 128, 48)) {
                        scene->data[5]->isVisible = false;
                        scene->data[6]->isVisible = false;

                        scene->data[7]->isVisible = true;
                        scene->data[8]->isVisible = true;
                    } else if (isOnObject(scene, 6, input, 128, 48)) {
                        scene->flags[1] = 1;

                        scene->data[5]->isVisible = false;
                        scene->data[6]->isVisible = false;

                        scene->data[7]->isVisible = true;
                        scene->data[8]->isVisible = true;
                    } else if (isOnObject(scene, 7, input, 128, 48)) {
                        scene->data[7]->isVisible = false;
                        scene->data[8]->isVisible = false;

                        scene->data[9]->isVisible = true;
                        scene->data[10]->isVisible = true;
                        scene->data[11]->isVisible = true;
                    } else if (isOnObject(scene, 8, input, 128, 48)) {
                        scene->flags[2] = 1;

                        scene->data[7]->isVisible = false;
                        scene->data[8]->isVisible = false;

                        scene->data[9]->isVisible = true;
                        scene->data[10]->isVisible = true;
                        scene->data[11]->isVisible = true;
                    } else if (isOnObject(scene, 9, input, 128,48)) {
                        scene->flags[3] = 0;
                        scene->flags[4] = 0;

                        changeScene(scene, scene->flags[1] ? 2 : 1);
                    } else if (isOnObject(scene, 10, input, 128, 48)) {
                        scene->flags[3] = 0;
                        scene->flags[4] = 1;

                        changeScene(scene, scene->flags[1] ? 2 : 1);
                    } else if (isOnObject(scene, 11, input, 128, 48)) {
                        scene->flags[3] = 0;
                        scene->flags[4] = 2;

                        changeScene(scene, scene->flags[1] ? 2 : 1);
                    }
                } else {
                    scene->flags[3] = 0;
                }

                break;
            case 1: // GAME 1-PLAYER
                switch(scene->flags[9]) {
                    case 0: // Select a tile to set on grid
                        for (short i = 5; i < 10; i++) {
                            if(isOnObject(scene, i, input, 96, 96)) {
                                scene->data[i]->y = 480;
                                if(input->mouse[SDL_BUTTON_LEFT]) {
                                    if (scene->flags[3]) return;
                                    scene->flags[3] = 1;

                                    scene->data[i]->z = -1;
                                    scene->data[i]->flush = true;

                                    strcpy(scene->data[13]->sprite, "ACT: Selectionnez la case a placer");
                                    scene->data[13]->flush = true;

                                    scene->flags[10] = i; // save the currently selected tile for later uses
                                    scene->flags[9] = 1;
                                    scene->flags[12] = getTileCharsPosition(scene->data[i]->sprite);
                                } else {
                                    scene->flags[3] = 0;
                                }
                            } else {
                                scene->data[i]->y = 500;
                            }
                        }
                        break;
                    case 1: // Select the character on the tile
                        if(input->keys[SDL_SCANCODE_ESCAPE]) {
                            if (scene->flags[14]) return;
                            scene->flags[14] = 1;

                            scene->data[scene->flags[10]]->z = 0;
                            scene->data[scene->flags[10]]->flush = true;

                            strcpy(scene->data[13]->sprite, "ACT: Selectionnez une tuile");
                            scene->data[13]->flush = true;

                            scene->flags[9] = 0;
                            scene->flags[10] = 0;
                        } else {
                            scene->flags[14] = 0;
                        }

                        if(input->mouse[SDL_BUTTON_LEFT]) {
                            if (scene->flags[3]) return;
                            scene->flags[3] = 1;

                            int tmp = 1;
                            int x = 144 + 104 * (scene->flags[10] - 5);
                            for(int i = 0; i < 9; i++) {
                                if((tmp & scene->flags[12]) != 0
                                && isInRect(input, x + 32 * (i % 3) + 2, 482 + 32 * (i / 3), 28, 28)) {
                                    scene->data[scene->flags[10]]->z = i + 1;
                                    scene->data[scene->flags[10]]->flush = true;

                                    strcpy(scene->data[13]->sprite, "ACT: Selectionnez une case sur la grille");
                                    scene->data[13]->flush = true;

                                    scene->flags[11] = i;
                                    scene->flags[9] = 2;
                                }
                                tmp *= 2;
                            }
                        } else {
                            scene->flags[3] = 0;
                        }
                        break;
                    case 2: // Select a square in the tile
                        short width = scene->flags[4] == 0 ? 6 : scene->flags[4] == 1 ? 12 : 18;
                        short height = scene->flags[4] == 0 ? 3 : scene->flags[4] == 1 ? 6 : 9;
                        short size = width * height;

                        if(input->keys[SDL_SCANCODE_ESCAPE]) {
                            if (scene->flags[14]) return;
                            scene->flags[14] = 1;

                            scene->data[scene->flags[10]]->z = -1;
                            scene->data[scene->flags[10]]->flush = true;

                            strcpy(scene->data[13]->sprite, "ACT: Selectionnez la case a placer");
                            scene->data[13]->flush = true;

                            scene->flags[11] = 0;
                            scene->flags[9] = 1;
                        } else {
                            scene->flags[14] = 0;
                        }

                        if(scene->flags[7] == 0) { // first tile
                            if(input->mouse[SDL_BUTTON_LEFT]) {
                                if (scene->flags[3]) return;
                                scene->flags[3] = 1;
                                for(short i = 0; i < size; i++) {
                                    if(isInRect(input, scene->data[2]->x + 2 + 32 * (i % width), scene->data[2]->y + 2 + 32 * (i / width), 28, 28)) {
                                        scene->flags[13] = i;
                                        int pos = i - width * (scene->flags[11] / 3) - scene->flags[11] % 3;
                                        if(isInGrid(scene->data[scene->flags[10]]->sprite, pos, scene->flags[11], width, height)) {
                                            setTile(scene->data[2]->sprite, scene->data[scene->flags[10]]->sprite, pos, width, 0, 0);
                                            scene->data[2]->flush = true;

                                            scene->flags[9] = 3;
                                        } else {
                                            strcpy(scene->data[13]->sprite, "ACT: Tuile en dehors!");
                                            scene->data[13]->flush = true;
                                        }
                                    }
                                }

                            } else {
                                scene->flags[3] = 0;
                            }
                        } else {
                            if(input->mouse[SDL_BUTTON_LEFT]) {
                                if (scene->flags[3]) return;
                                scene->flags[3] = 1;
                                for(short i = 0; i < size; i++) {
                                    if (isdigit(scene->data[2]->sprite[i])
                                    && isInRect(input, scene->data[2]->x + 2 + 32 * (i % width), scene->data[2]->y + 2 + 32 * (i / width), 28, 28)) {
                                        scene->flags[13] = i;
                                        int pos = i - width * (scene->flags[11] / 3) - scene->flags[11] % 3;

                                        if(isValidPos(scene->data[2]->sprite, scene->data[scene->flags[10]]->sprite, pos, width, false)) {
                                            setTile(scene->data[2]->sprite, scene->data[scene->flags[10]]->sprite, pos,
                                                    width, height, scene->flags[11]);
                                            scene->data[2]->flush = true;

                                            scene->flags[9] = 3;
                                        } else {
                                            strcpy(scene->data[13]->sprite, "ACT: Placement incorrect!");
                                            scene->data[13]->flush = true;
                                        }
                                    }
                                }
                            } else {
                                scene->flags[3] = 0;
                            }
                        }
                        break;
                    case 3: // End of turn
                        int flags = 0;
                        if (scene->flags[2]) flags |= 1;
                        if (scene->flags[1]) flags |= 2;

                        scene->flags[7]++;
                        sprintf(scene->data[12]->sprite, "SCORE: %d", scene->flags[7]);
                        scene->data[12]->flush = true;

                        scene->data[scene->flags[10]]->z = 0;
                        generateTile(scene->data[scene->flags[10]]->sprite, flags);
                        scene->data[scene->flags[10]]->flush = true;

                        strcpy(scene->data[13]->sprite, "ACT: Selectionnez une tuile");
                        scene->data[13]->flush = true;

                        scene->flags[3] = 0;
                        scene->flags[9] = 0;
                        scene->flags[10] = 0;
                        break;
                }
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
    scene->isReady = false;
}
