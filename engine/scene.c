#include "scene.h"
#include "colors.h"
#include "gui.h"
#include "file.h"

#include "../game/tile.h"
#include "../game/misc.h"

#include <stddef.h>
#include <stdio.h>
#include <ctype.h>

void initScene(Scene *scene, short id) {
    scene->id = id;
    scene->isReady = false;

    for(int i = 0; i < MAX_OBJECTS; i++) {
        scene->data[i] = NULL;
    }

    for(int i = 0; i < MAX_FLAGS; i++) {
        scene->flags[i] = 0;
    }

    for(int i = 0; i < MAX_BUFFERS; i++) {
        initArray(scene->buffers[i], BUFFER_SIZE, 0);
    }
}

/** readyScene - Readies the scene according its ID
 * @param scene Pointer on the current scene
 */

void readyScene(Scene *scene) {
    switch(scene->id) {
        case 0: // Title screen
            initObjectData(scene->data, 0, SPRITE, "./resources/spr_back_0.bmp", 0, 0, 0, 0, 0, SDL_WHITE, SDL_FLIP_NONE, true);
            initObjectData(scene->data, 1, TEXT, "JEU DE PAVAGE", 260, 24, 0, 4, 0, SDL_WHITE, SDL_FLIP_NONE, true);

            // buttons of main screen
            initObjectData(scene->data, 2, SPRITE, "./resources/spr_btn_main_0.bmp", 336, 200, 0, 0, 0, SDL_WHITE, SDL_FLIP_NONE, true);
            initObjectData(scene->data, 3, SPRITE, "./resources/spr_btn_main_1.bmp", 336, 256, 0, 0, 0, SDL_WHITE, SDL_FLIP_NONE, true);
            initObjectData(scene->data, 4, SPRITE, "./resources/spr_btn_main_2.bmp", 336, 312, 0, 0, 0, SDL_WHITE, SDL_FLIP_NONE, true);

            // how many players buttons
            initObjectData(scene->data, 5, SPRITE, "./resources/spr_btn_play_0.bmp", 336, 202, 0, 0, 0, SDL_WHITE, SDL_FLIP_NONE, false);
            initObjectData(scene->data, 6, SPRITE, "./resources/spr_btn_play_1.bmp", 336, 258, 0, 0, 0, SDL_WHITE, SDL_FLIP_NONE, false);

            // difficulties buttons
            initObjectData(scene->data, 7, SPRITE, "./resources/spr_btn_diff_0.bmp", 336, 202, 0, 0, 0, SDL_WHITE, SDL_FLIP_NONE, false);
            initObjectData(scene->data, 8, SPRITE, "./resources/spr_btn_diff_1.bmp", 336, 258, 0, 0, 0, SDL_WHITE, SDL_FLIP_NONE, false);

            //which size ?
            initObjectData(scene->data, 9, SPRITE, "./resources/spr_btn_size_0.bmp", 336, 202, 0, 0, 0, SDL_WHITE, SDL_FLIP_NONE, false);
            initObjectData(scene->data, 10, SPRITE, "./resources/spr_btn_size_1.bmp", 336, 258, 0, 0, 0, SDL_WHITE, SDL_FLIP_NONE, false);
            initObjectData(scene->data, 11, SPRITE, "./resources/spr_btn_size_2.bmp", 336, 314, 0, 0, 0, SDL_WHITE, SDL_FLIP_NONE, false);

            // return button
            initObjectData(scene->data, 12, SPRITE, "./resources/spr_btn_undo.bmp", 16, 16, 0, 0, 0, SDL_WHITE, SDL_FLIP_NONE, true);

            break;
        case 1: // One Player
            scene->flags[4] = 0;

            int flags = 0;
            if (scene->flags[6]) flags |= 1;
            if (scene->flags[5]) flags |= 2;

            if(!scene->flags[1]) { // Do not reset score when loading a save file
                scene->flags[9] = 0;
            }

            int x_tmp, y_tmp;
            char str1[96];
            char str2[96];

            initGridPosAndLabels(scene->flags[7], &x_tmp, &y_tmp, str1, str2);

            initObjectData(scene->data, 0, SPRITE, "./resources/spr_back_1.bmp", 0, 0, 0, 0, 0, SDL_PURPLE,SDL_FLIP_NONE, true);
            initObjectData(scene->data, 1, SPRITE, "./resources/spr_btn_save.bmp", 8, 16, 0, 0, 0, SDL_WHITE,SDL_FLIP_NONE, true); // TO MOVE

            // Game Grid and labels
            initObjectData(scene->data, 2, GRID, "", x_tmp, y_tmp, scene->flags[7], 3, 0, SDL_BLACK, SDL_FLIP_NONE,true);
            initObjectData(scene->data, 3, TEXT, str1, x_tmp + 10, y_tmp - 32, 0, 3, 0, SDL_WHITE, SDL_FLIP_NONE, true);
            initObjectData(scene->data, 4, TEXT, str2, x_tmp - 32, y_tmp, 0, 3, 0, SDL_WHITE, SDL_FLIP_NONE, true);

            if(scene->flags[1]) { // reload grid when loading a save file
                strcpy(scene->data[2]->sprite, scene->buffers[0]);
            } else {
                initArray(scene->data[2]->sprite, 256, ' ');
            }

            // Hand of 5 tiles - PLAYER 1
            for (int i = 5; i < 10; i++) {
                initObjectData(scene->data, i, TILE, "", 144 + 104 * (i - 5), 500, 0, 3, 0, SDL_BLACK, SDL_FLIP_NONE, true);
                if(scene->flags[1]) {
                    strcpy(scene->data[i]->sprite, scene->buffers[i - 4]);
                } else {
                    generateTile(scene->data[i]->sprite, flags);
                }
            }

            // Texts and buttons
            initObjectData(scene->data, 10, TEXT, "SCORE: 0", 600, 12, 0, 2, 0, SDL_WHITE, SDL_FLIP_NONE, true);
            initObjectData(scene->data, 11, TEXT, "ACT: Selectionnez une tuile", 16, 440, 0, 2, 0, SDL_WHITE, SDL_FLIP_NONE, true);
            initObjectData(scene->data, 12, SPRITE, "./resources/spr_btn_stop.bmp", 64, 16, 0, 0, 0, SDL_WHITE,SDL_FLIP_NONE, true);

            // End game Screen
            initObjectData(scene->data, 15, SPRITE, "./resources/spr_back_2.bmp", 160, 96, 0, 0, 0, SDL_WHITE,SDL_FLIP_NONE, false);
            initObjectData(scene->data, 16, TEXT, "Fin de partie", 320, 108, 0, 3, 0, SDL_WHITE,SDL_FLIP_NONE, false);
            initObjectData(scene->data, 17, TEXT, "Error!", 208, 184, 0, 2, 0, SDL_BLACK,SDL_FLIP_NONE, false);
            initObjectData(scene->data, 18, TEXT, "Error!", 208, 216, 0, 2, 0, SDL_BLACK,SDL_FLIP_NONE, false);
            initObjectData(scene->data, 19, TEXT, "Error!", 208, 248, 0, 2, 0, SDL_BLACK,SDL_FLIP_NONE, false);

            initObjectData(scene->data, 20, SPRITE, "./resources/spr_btn_ok.bmp", 336, 376, 0, 0, 0, SDL_WHITE,SDL_FLIP_NONE, false);

            scene->flags[1] = 0; // Set use of buffers to false

            break;
        case 2: // Two players
            break;
    }
    scene->isReady = true;
}

void changeScene(Scene *scene, short id) {
    scene->flags[0] = 1; // Flush Renderer
    scene->id = id;
    destroyScene(scene);
}

void endGame(Scene *scene) {
    if(scene->flags[5]) { // 2 PLAYERS SCREEN

    } else {
        for (int i = 1; i < 13; i++) {
            scene->data[i]->isVisible = false;
        }

        for (int i = 15; i < 21; i++) {
            scene->data[i]->isVisible = true;
        }

        sprintf(scene->data[17]->sprite, "Mode: %s", scene->flags[6] ? "Difficile" : "Facile"); // TO CHECK
        scene->data[17]->flush = true;

        sprintf(scene->data[18]->sprite, "Taille de grille: %s", (scene->flags[7] == 0) ? "Petite" : (scene->flags[7] == 1 ? "Moyenne" : "Grande")); // TO CHECK
        scene->data[18]->flush = true;

        sprintf(scene->data[19]->sprite, "Nombre de tuiles posees: %d", scene->flags[9]); // TO CHECK
        scene->data[19]->flush = true;

        scene->flags[4] = 4;
    }
}

void updateScene(Scene *scene, Input *input, Window *window) {
    if(!scene->isReady) {
        readyScene(scene);
    } else {
        switch (scene->id) {
            case 0: // TITLE SCREEN
                if(input->mouse[SDL_BUTTON_LEFT]) {
                    if (scene->flags[2]) return;
                    scene->flags[2] = 1;

                    if (isOnObject(scene, 2, input, 128, 48)) { // New game
                        scene->data[2]->isVisible = false;
                        scene->data[3]->isVisible = false;
                        scene->data[4]->isVisible = false;

                        scene->data[5]->isVisible = true;
                        scene->data[6]->isVisible = true;
                    } else if (isOnObject(scene, 3, input, 128, 48)) { // Continue
                        if(fileExists("sav.dat")) {
                            load(scene->flags, scene->buffers);
                            scene->flags[1] = 1;

                            changeScene(scene, scene->flags[5] + 1);
                            return;
                        } else {
                            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_WARNING, WINDOW_TITLE, "Le fichier de sauvegarde est inexistant ou n'a pas pu être ouvert !", window->handle);
                        }
                    } else if (isOnObject(scene, 4, input, 128, 48)) { // Exit
                        window->isClosing = true;
                    } else if (isOnObject(scene, 5, input, 128, 48)) {
                        scene->flags[5] = 0;

                        scene->data[5]->isVisible = false;
                        scene->data[6]->isVisible = false;

                        scene->data[7]->isVisible = true;
                        scene->data[8]->isVisible = true;
                    } else if (isOnObject(scene, 6, input, 128, 48)) {
                        scene->flags[5] = 1;

                        scene->data[5]->isVisible = false;
                        scene->data[6]->isVisible = false;

                        scene->data[7]->isVisible = true;
                        scene->data[8]->isVisible = true;
                    } else if (isOnObject(scene, 7, input, 128, 48)) {
                        scene->flags[6] = 0;

                        scene->data[7]->isVisible = false;
                        scene->data[8]->isVisible = false;

                        scene->data[9]->isVisible = true;
                        scene->data[10]->isVisible = true;
                        scene->data[11]->isVisible = true;
                    } else if (isOnObject(scene, 8, input, 128, 48)) {
                        scene->flags[6] = 1;

                        scene->data[7]->isVisible = false;
                        scene->data[8]->isVisible = false;

                        scene->data[9]->isVisible = true;
                        scene->data[10]->isVisible = true;
                        scene->data[11]->isVisible = true;
                    } else if (isOnObject(scene, 9, input, 128,48)) {
                        //scene->flags[2] = 0;
                        //scene->flags[3] = 0;
                        scene->flags[7] = 0;

                        changeScene(scene, scene->flags[5] ? 2 : 1);
                    } else if (isOnObject(scene, 10, input, 128, 48)) {
                        //scene->flags[2] = 0;
                        //scene->flags[3] = 0;
                        scene->flags[7] = 1;

                        changeScene(scene, scene->flags[5] ? 2 : 1);
                    } else if (isOnObject(scene, 11, input, 128, 48)) {
                        //scene->flags[2] = 0;
                        //scene->flags[3] = 0;
                        scene->flags[7] = 2;

                        changeScene(scene, scene->flags[5] ? 2 : 1);
                    }
                } else {
                    scene->flags[2] = 0;
                }

                break;
            case 1: // GAME 1-PLAYER
                if (input->mouse[SDL_BUTTON_LEFT]) {
                    if (isOnObject(scene, 1, input, 48, 48)) {
                        if (fileExists("sav.dat")) {
                            char *tiles[5];
                            for(int i = 0; i < 5; i++) {
                                tiles[i] = scene->data[5 + i]->sprite;
                            }

                            save(scene->flags, scene->data[2]->sprite, tiles);

                            int buttonid;
                            displaySaveMessage(window->handle, &buttonid);

                            // focus here
                            //scene->flags[2] = 1;

                            if (buttonid == 0) {
                                changeScene(scene, 0);
                            }

                            return;
                        } else {
                            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_WARNING, WINDOW_TITLE,
                                                     "Le fichier de sauvegarde n'a pas pu être créé!", window->handle);
                        }
                    } else if(isOnObject(scene, 12, input, 48, 48)) {
                        endGame(scene);
                    }
                }

                short width = scene->flags[7] == 0 ? 6 : scene->flags[7] == 1 ? 12 : 18;
                short height = scene->flags[7] == 0 ? 3 : scene->flags[7] == 1 ? 6 : 9;
                short size = width * height;

                switch(scene->flags[4]) {
                    case 0: // Select a tile to set on grid
                        for (short i = 5; i < 10; i++) {
                            if(isOnObject(scene, i, input, 96, 116)) {
                                scene->data[i]->y = 480;
                                if(input->mouse[SDL_BUTTON_LEFT]) {
                                    if (scene->flags[2]) return;
                                    scene->flags[2] = 1;

                                    scene->data[i]->z = -1;
                                    scene->data[i]->flush = true;

                                    strcpy(scene->data[1]->sprite, "ACT: Selectionnez la case a placer");
                                    scene->data[11]->flush = true;

                                    scene->flags[11] = i; // save the currently selected tile for later uses
                                    scene->flags[14] = getTileCharsPosition(scene->data[i]->sprite); // TO REWORK

                                    scene->flags[4] = 1;
                                } else {
                                    scene->flags[2] = 0;
                                }
                            } else {
                                scene->data[i]->y = 500;
                            }
                        }
                        break;
                    case 1: // Select the character on the tile
                        if(input->keys[SDL_SCANCODE_ESCAPE]) {
                            if (scene->flags[3]) return;
                            scene->flags[3] = 1;

                            scene->data[scene->flags[11]]->z = 0;
                            scene->data[scene->flags[11]]->flush = true;

                            strcpy(scene->data[11]->sprite, "ACT: Selectionnez une tuile");
                            scene->data[11]->flush = true;

                            scene->flags[11] = 0;

                            scene->flags[4] = 0;
                        } else {
                            scene->flags[3] = 0;
                        }

                        if(input->mouse[SDL_BUTTON_LEFT]) {
                            if (scene->flags[2]) return;
                            scene->flags[2] = 1;

                            int tmp = 1;
                            int x = 144 + 104 * (scene->flags[11] - 5);
                            for(int i = 0; i < 9; i++) {
                                if((tmp & scene->flags[14]) != 0
                                && isInRect(input, x + 32 * (i % 3) + 2, 482 + 32 * (i / 3), 28, 28)) {
                                    scene->data[scene->flags[11]]->z = i + 1;
                                    scene->data[scene->flags[11]]->flush = true;

                                    strcpy(scene->data[11]->sprite, "ACT: Selectionnez une case sur la grille");
                                    scene->data[11]->flush = true;

                                    scene->flags[12] = i;

                                    scene->flags[4] = 2;
                                }
                                tmp *= 2;
                            }
                        } else {
                            scene->flags[2] = 0;
                        }
                        break;
                    case 2: // Select a square in the tile
                        if(input->keys[SDL_SCANCODE_ESCAPE]) {
                            if (scene->flags[3]) return;
                            scene->flags[3] = 1;

                            scene->data[scene->flags[11]]->z = -1;
                            scene->data[scene->flags[11]]->flush = true;

                            strcpy(scene->data[11]->sprite, "ACT: Selectionnez la case a placer");
                            scene->data[11]->flush = true;

                            scene->flags[12] = 0;

                            scene->flags[4] = 1;
                        } else {
                            scene->flags[3] = 0;
                        }

                        if(scene->flags[9] == 0) { // If first tile
                            if(input->mouse[SDL_BUTTON_LEFT]) {
                                if (scene->flags[2]) return;
                                scene->flags[2] = 1;

                                for(short i = 0; i < size; i++) {
                                    if(isInRect(input, scene->data[2]->x + 2 + 32 * (i % width), scene->data[2]->y + 2 + 32 * (i / width), 28, 28)) {
                                        scene->flags[13] = i;
                                        int pos = i - width * (scene->flags[12] / 3) - scene->flags[12] % 3;
                                        if(isInGrid(scene->data[scene->flags[11]]->sprite, pos, scene->flags[12], width, height)) {
                                            setTile(scene->data[2]->sprite, scene->data[scene->flags[11]]->sprite, pos, -1, width, 0);
                                            scene->data[2]->flush = true;

                                            scene->flags[4] = 3;
                                        } else {
                                            strcpy(scene->data[11]->sprite, "ACT: Tuile en dehors!");
                                            scene->data[11]->flush = true;
                                        }
                                    }
                                }

                            } else {
                                scene->flags[2] = 0;
                            }
                        } else {
                            if(input->mouse[SDL_BUTTON_LEFT]) {
                                if (scene->flags[2]) return;
                                scene->flags[2] = 1;

                                for(short i = 0; i < size; i++) {
                                    if (isdigit(scene->data[2]->sprite[i])
                                    && isInRect(input, scene->data[2]->x + 2 + 32 * (i % width), scene->data[2]->y + 2 + 32 * (i / width), 28, 28)) {
                                        scene->flags[13] = i;
                                        int pos = i - width * (scene->flags[12] / 3) - scene->flags[12] % 3;

                                        if(isValidPos(scene->data[2]->sprite, scene->data[scene->flags[11]]->sprite, pos, width, false)) {
                                            setTile(scene->data[2]->sprite, scene->data[scene->flags[11]]->sprite, pos, scene->flags[12], width, height);
                                            scene->data[2]->flush = true;

                                            scene->flags[4] = 3;
                                        } else {
                                            strcpy(scene->data[11]->sprite, "ACT: Placement incorrect!");
                                            scene->data[11]->flush = true;
                                        }
                                    }
                                }
                            } else {
                                scene->flags[2] = 0;
                            }
                        }
                        break;
                    case 3: // End of turn
                        int flags = 0;
                        if (scene->flags[6]) flags |= 1;
                        if (scene->flags[5]) flags |= 2;

                        scene->flags[9]++;
                        sprintf(scene->data[10]->sprite, "SCORE: %d", scene->flags[9]); // TO CHECK
                        scene->data[10]->flush = true;

                        scene->data[scene->flags[11]]->z = 0;
                        generateTile(scene->data[scene->flags[11]]->sprite, flags);
                        scene->data[scene->flags[11]]->flush = true;

                        strcpy(scene->data[11]->sprite, "ACT: Selectionnez une tuile");
                        scene->data[11]->flush = true;

                        scene->flags[11] = 0;
                        scene->flags[2] = 0; //

                        scene->flags[4] = 0;

                        bool res = false;
                        for(int i = 5; i < 10 ; i++) {
                            if (getNumberOfMoves(scene->data[2]->sprite, scene->data[i]->sprite, width, height, false) > 0) {
                                res = true;
                            }
                        }

                        if(!res) {
                            endGame(scene);
                        }

                        break;
                    case 4: // end of game
                        if(input->mouse[SDL_BUTTON_LEFT]) {
                            if (scene->flags[2]) return;
                            scene->flags[2] = 1;

                            if (isOnObject(scene, 20, input, 128, 48)) {
                                changeScene(scene, 0);
                                return;
                            }
                        } else {
                            scene->flags[2] = 0;
                        }
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
