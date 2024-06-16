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
        case 0: { // Title screen
            scene->flags[4] = 0;
            initObjectData(scene->data, 0, SPRITE, "./resources/spr_back_0.bmp", 0, 0, 0, 0, 0, SDL_LIGHT_PURPLE, SDL_FLIP_NONE, true);
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
            initObjectData(scene->data, 12, SPRITE, "./resources/spr_btn_undo.bmp", 16, 16, 0, 0, 0, SDL_WHITE, SDL_FLIP_NONE, false);

            break;
        }
        case 1: { // One Player
            scene->flags[4] = 0;

            int flags = 0;
            if (scene->flags[6]) flags |= 1;
            if (scene->flags[5]) flags |= 2;

            if (!scene->flags[1]) { // Do not reset score when loading a save file
                scene->flags[9] = 0;
            }

            int x_tmp, y_tmp;
            char str1[96];
            char str2[96];

            initGridPosAndLabels(scene->flags[7], &x_tmp, &y_tmp, str1, str2);

            initObjectData(scene->data, 0, SPRITE, "./resources/spr_back_1.bmp", 0, 0, 0, 0, 0, SDL_PURPLE, SDL_FLIP_NONE, true);

            // Game Grid and labels
            initObjectData(scene->data, 2, GRID, "", x_tmp, y_tmp, scene->flags[7], 3, 0, SDL_BLACK, SDL_FLIP_NONE, true);
            initObjectData(scene->data, 3, TEXT, str1, x_tmp + 10, y_tmp - 32, 0, 3, 0, SDL_WHITE, SDL_FLIP_NONE, true);
            initObjectData(scene->data, 4, TEXT, str2, x_tmp - 32, y_tmp, 0, 3, 0, SDL_WHITE, SDL_FLIP_NONE, true);

            if (scene->flags[1]) { // reload grid when loading a save file
                strcpy(scene->data[2]->sprite, scene->buffers[0]);
            } else {
                initArray(scene->data[2]->sprite, 256, ' ');
            }

            // Hand of 5 tiles - PLAYER 1
            for (int i = 5; i < 10; i++) {
                initObjectData(scene->data, i, TILE, "", 144 + 104 * (i - 5), 500, 0, 3, 0, SDL_BLACK, SDL_FLIP_NONE, true);
                if (scene->flags[1]) {
                    strcpy(scene->data[i]->sprite, scene->buffers[i - 4]);
                } else {
                    generateTile(scene->data[i]->sprite, flags);
                }
            }

            // Texts and buttons
            initObjectData(scene->data, 10, TEXT, "", 600, 12, 0, 2, 0, SDL_WHITE, SDL_FLIP_NONE, true);
            initObjectData(scene->data, 11, TEXT, "ACT: Selectionnez une tuile", 16, 440, 0, 2, 0, SDL_WHITE, SDL_FLIP_NONE, true);
            initObjectData(scene->data, 12, SPRITE, "./resources/spr_btn_stop.bmp", 64, 16, 0, 0, 0, SDL_WHITE, SDL_FLIP_NONE, true);
            initObjectData(scene->data, 13, SPRITE, "./resources/spr_btn_save.bmp", 8, 16, 0, 0, 0, SDL_WHITE, SDL_FLIP_NONE, true);

            sprintf(scene->data[10]->sprite, "SCORE: %d", scene->flags[9]); // TO CHECK

            // End game Screen
            initObjectData(scene->data, 15, SPRITE, "./resources/spr_back_2.bmp", 160, 96, 0, 0, 0, SDL_WHITE, SDL_FLIP_NONE, false);
            initObjectData(scene->data, 16, TEXT, "Fin de partie", 320, 108, 0, 3, 0, SDL_WHITE, SDL_FLIP_NONE, false);
            initObjectData(scene->data, 17, TEXT, "Error!", 208, 184, 0, 2, 0, SDL_BLACK, SDL_FLIP_NONE, false);
            initObjectData(scene->data, 18, TEXT, "Error!", 208, 216, 0, 2, 0, SDL_BLACK, SDL_FLIP_NONE, false);
            initObjectData(scene->data, 19, TEXT, "Error!", 208, 248, 0, 2, 0, SDL_BLACK, SDL_FLIP_NONE, false);

            initObjectData(scene->data, 20, SPRITE, "./resources/spr_btn_ok.bmp", 336, 376, 0, 0, 0, SDL_WHITE, SDL_FLIP_NONE, false);

            scene->flags[1] = 0; // Set use of buffers to false

            break;
        }
        case 2: { // Two players
            scene->flags[4] = 0;

            int flags = 0;
            if (scene->flags[6]) flags |= 1;
            if (scene->flags[5]) flags |= 2;

            if (!scene->flags[1]) { // Do not reset score when loading a save file
                scene->flags[8] = rand() % 2; // Select which player shall begin
                scene->flags[9] = 0;
                scene->flags[10] = 0;
            }

            scene->flags[15] = 0;
            scene->flags[16] = 0;

            int x_tmp, y_tmp;
            char str1[96];
            char str2[96];

            initGridPosAndLabels(scene->flags[7], &x_tmp, &y_tmp, str1, str2);

            initObjectData(scene->data, 0, SPRITE, "./resources/spr_back_1.bmp", 0, 0, 0, 0, 0, SDL_PURPLE,SDL_FLIP_NONE, true);

            // Game Grid and labels
            initObjectData(scene->data, 2, GRID, "", x_tmp, y_tmp, scene->flags[7], 3, 0, SDL_BLACK, SDL_FLIP_NONE,true);
            initObjectData(scene->data, 3, TEXT, str1, x_tmp + 10, y_tmp - 32, 0, 3, 0, SDL_WHITE, SDL_FLIP_NONE, true);
            initObjectData(scene->data, 4, TEXT, str2, x_tmp - 32, y_tmp, 0, 3, 0, SDL_WHITE, SDL_FLIP_NONE, true);

            if (scene->flags[1]) { // reload grid when loading a save file
                strcpy(scene->data[2]->sprite, scene->buffers[0]);
            } else {
                initArray(scene->data[2]->sprite, 256, ' ');
            }

            // Hand of 5 tiles - PLAYER 1
            for (int i = 5; i < 10; i++) {
                initObjectData(scene->data, i, TILE, "", 144 + 104 * (i - 5), 500, 0, 3, 0, SDL_BLACK, SDL_FLIP_NONE,scene->flags[8] ? false : true);
                if (scene->flags[1]) {
                    strcpy(scene->data[i]->sprite, scene->buffers[i - 4]);
                } else {
                    generateTile(scene->data[i]->sprite, flags);
                }
            }
            flags |= 4; // enables tile generation for second player
            // Hand of 5 tiles - PLAYER 2
            for (int i = 10; i < 15; i++) {
                initObjectData(scene->data, i, TILE, "", 144 + 104 * (i - 10), 500, 0, 3, 0, SDL_BLACK, SDL_FLIP_NONE,scene->flags[8] ? true : false);
                if (scene->flags[1]) {
                    strcpy(scene->data[i]->sprite, scene->buffers[i - 4]);
                } else {
                    generateTile(scene->data[i]->sprite, flags);
                }
            }

            // Texts and buttons
            initObjectData(scene->data, 15, TEXT, "", 600, 12, 0, 2, 0, SDL_WHITE, SDL_FLIP_NONE, true);
            initObjectData(scene->data, 16, TEXT, "", 600, 32, 0, 2, 0, SDL_WHITE, SDL_FLIP_NONE, true);
            initObjectData(scene->data, 17, TEXT, "", 16, 440, 0, 2, 0, SDL_WHITE,SDL_FLIP_NONE, true);
            initObjectData(scene->data, 18, SPRITE, "./resources/spr_btn_stop.bmp", 64, 16, 0, 0, 0, SDL_WHITE,SDL_FLIP_NONE, true);
            initObjectData(scene->data, 19, SPRITE, "./resources/spr_btn_save.bmp", 8, 16, 0, 0, 0, SDL_WHITE,SDL_FLIP_NONE, true);

            sprintf(scene->data[15]->sprite, "SCORE 1: %d", scene->flags[9]);
            sprintf(scene->data[16]->sprite, "SCORE 2: %d", scene->flags[10]);
            sprintf(scene->data[17]->sprite, "JOUEUR %d: Selectionnez une tuile", scene->flags[8] + 1);

            // End game Screen
            initObjectData(scene->data, 20, SPRITE, "./resources/spr_back_2.bmp", 160, 96, 0, 0, 0, SDL_WHITE,SDL_FLIP_NONE, false);
            initObjectData(scene->data, 21, TEXT, "Fin de partie", 320, 108, 0, 3, 0, SDL_WHITE, SDL_FLIP_NONE, false);
            initObjectData(scene->data, 22, TEXT, "Error!", 208, 184, 0, 2, 0, SDL_BLACK, SDL_FLIP_NONE, false);
            initObjectData(scene->data, 23, TEXT, "Error!", 208, 216, 0, 2, 0, SDL_BLACK, SDL_FLIP_NONE, false);
            initObjectData(scene->data, 24, TEXT, "Error!", 208, 248, 0, 2, 0, SDL_BLACK, SDL_FLIP_NONE, false);
            initObjectData(scene->data, 25, TEXT, "Error!", 208, 280, 0, 2, 0, SDL_BLACK, SDL_FLIP_NONE, false);
            initObjectData(scene->data, 26, TEXT, "Error!", 208, 312, 0, 2, 0, SDL_BLACK, SDL_FLIP_NONE, false);

            initObjectData(scene->data, 27, SPRITE, "./resources/spr_btn_ok.bmp", 336, 376, 0, 0, 0, SDL_WHITE,SDL_FLIP_NONE, false);
            initObjectData(scene->data, 28, SPRITE, "./resources/spr_btn_yes.bmp", 264, 376, 0, 0, 0, SDL_WHITE,SDL_FLIP_NONE, false);
            initObjectData(scene->data, 29, SPRITE, "./resources/spr_btn_no.bmp", 408, 376, 0, 0, 0, SDL_WHITE,SDL_FLIP_NONE, false);

            scene->flags[1] = 0; // Set use of buffers to false

            break;
        }
    }
    scene->isReady = true;
}

void changeScene(Scene *scene, short id) {
    scene->flags[0] = 1; // Flush Renderer
    scene->id = id;
    destroyScene(scene); // Destroys all data objects from scene
}

void updateScene(Scene *scene, Input *input, Window *window) {
    if(!scene->isReady) {
        readyScene(scene);
    } else {
        switch (scene->id) {
            case 0: { // TITLE SCREEN
                if (input->mouse[SDL_BUTTON_LEFT]) {
                    if (scene->flags[2]) return;
                    scene->flags[2] = 1;

                    if (isOnObject(scene, 2, input, 128, 48)) { // New game
                        scene->data[2]->isVisible = false;
                        scene->data[3]->isVisible = false;
                        scene->data[4]->isVisible = false;

                        scene->data[5]->isVisible = true;
                        scene->data[6]->isVisible = true;
                        scene->data[12]->isVisible = true;

                        scene->flags[4] = 1;
                    } else if (isOnObject(scene, 3, input, 128, 48)) { // Continue
                        if (fileExists("sav.dat")) {
                            load(scene->flags, scene->buffers);
                            scene->flags[1] = 1;

                            changeScene(scene, scene->flags[5] + 1);
                            return;
                        } else {
                            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_WARNING, WINDOW_TITLE, "Le fichier de sauvegarde est inexistant ou n'a pas pu être ouvert !", window->handle);

                            // Only way to recover the input focus in this case!
                            hideWindow(window);
                            showWindow(window);
                        }
                    } else if (isOnObject(scene, 4, input, 128, 48)) { // Exit
                        window->isClosing = true;
                    } else if (isOnObject(scene, 5, input, 128, 48)) { // ONE PLAYER
                        scene->flags[5] = 0;

                        scene->data[5]->isVisible = false;
                        scene->data[6]->isVisible = false;

                        scene->data[7]->isVisible = true;
                        scene->data[8]->isVisible = true;

                        scene->flags[4] = 2;
                    } else if (isOnObject(scene, 6, input, 128, 48)) { // TWO PLAYER
                        scene->flags[5] = 1;

                        scene->data[5]->isVisible = false;
                        scene->data[6]->isVisible = false;

                        scene->data[7]->isVisible = true;
                        scene->data[8]->isVisible = true;

                        scene->flags[4] = 2;
                    } else if (isOnObject(scene, 7, input, 128, 48)) { // EASY
                        scene->flags[6] = 0;

                        scene->data[7]->isVisible = false;
                        scene->data[8]->isVisible = false;

                        scene->data[9]->isVisible = true;
                        scene->data[10]->isVisible = true;
                        scene->data[11]->isVisible = true;

                        scene->flags[4] = 3;
                    } else if (isOnObject(scene, 8, input, 128, 48)) { // DIFFICULT
                        scene->flags[6] = 1;

                        scene->data[7]->isVisible = false;
                        scene->data[8]->isVisible = false;

                        scene->data[9]->isVisible = true;
                        scene->data[10]->isVisible = true;
                        scene->data[11]->isVisible = true;

                        scene->flags[4] = 3;
                    } else if (isOnObject(scene, 9, input, 128, 48)) { // SMALL GRID
                        // Reset inputs flags 2 & 3
                        scene->flags[2] = 0;
                        scene->flags[3] = 0;

                        scene->flags[7] = 0;

                        changeScene(scene, scene->flags[5] ? 2 : 1);
                    } else if (isOnObject(scene, 10, input, 128, 48)) { // MEDIUM GRID
                        // Reset inputs flags 2 & 3
                        scene->flags[2] = 0;
                        scene->flags[3] = 0;

                        scene->flags[7] = 1;

                        changeScene(scene, scene->flags[5] ? 2 : 1);
                    } else if (isOnObject(scene, 11, input, 128, 48)) { // LARGE GRID
                        // Reset inputs flags 2 & 3
                        scene->flags[2] = 0;
                        scene->flags[3] = 0;

                        scene->flags[7] = 2;

                        changeScene(scene, scene->flags[5] ? 2 : 1);
                    } else if (isOnObject(scene, 12, input, 48, 48)) {
                        switch (scene->flags[4]) {
                            case 1: {
                                scene->data[5]->isVisible = false;
                                scene->data[6]->isVisible = false;
                                scene->data[12]->isVisible = false;

                                scene->data[2]->isVisible = true;
                                scene->data[3]->isVisible = true;
                                scene->data[4]->isVisible = true;
                                break;
                            }
                            case 2: {
                                scene->data[7]->isVisible = false;
                                scene->data[8]->isVisible = false;

                                scene->data[5]->isVisible = true;
                                scene->data[6]->isVisible = true;
                                break;
                            }
                            case 3: {
                                scene->data[9]->isVisible = false;
                                scene->data[10]->isVisible = false;
                                scene->data[11]->isVisible = false;

                                scene->data[7]->isVisible = true;
                                scene->data[8]->isVisible = true;
                                break;
                            }
                        }
                        scene->flags[4]--;
                    }
                } else {
                    scene->flags[2] = 0;
                }

                break;
            }
            case 1: { // GAME 1-PLAYER
                if (input->mouse[SDL_BUTTON_LEFT]) {
                    if (isOnObject(scene, 13, input, 48, 48)) {
                        char *tiles[5];
                        for (int i = 0; i < 5; i++) {
                            tiles[i] = scene->data[5 + i]->sprite;
                        }

                        save(scene->flags, scene->data[2]->sprite, tiles);

                        int buttonid;
                        if (displaySaveMessage(window->handle, &buttonid) == -1) {
                            buttonid = -1;
                        }

                        // Only way to recover the input focus in this case!
                        hideWindow(window);
                        showWindow(window);

                        scene->flags[2] = 1;

                        if (buttonid == 0) {
                            changeScene(scene, 0);
                        }

                        return;
                    } else if (isOnObject(scene, 12, input, 48, 48)) {
                        endGame(scene);
                    }
                }

                short width = scene->flags[7] == 0 ? 6 : scene->flags[7] == 1 ? 12 : 18;
                short height = scene->flags[7] == 0 ? 3 : scene->flags[7] == 1 ? 6 : 9;
                short size = width * height;

                switch (scene->flags[4]) { // SCENE CONTROLLER
                    case 0: { // Select a tile to set on grid
                        for (short i = 5; i < 10; i++) {
                            if (isOnObject(scene, i, input, 96, 116)) {
                                scene->data[i]->y = 480;
                                if (input->mouse[SDL_BUTTON_LEFT]) {
                                    if (scene->flags[2]) return;
                                    scene->flags[2] = 1;

                                    scene->data[i]->z = -1;
                                    scene->data[i]->flush = true;

                                    strcpy(scene->data[11]->sprite, "ACT: Selectionnez la case a placer");
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
                    }
                    case 1: { // Select the character on the tile
                        if (input->keys[SDL_SCANCODE_ESCAPE]) {
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

                        if (input->mouse[SDL_BUTTON_LEFT]) {
                            if (scene->flags[2]) return;
                            scene->flags[2] = 1;

                            int tmp = 1;
                            int x = 144 + 104 * (scene->flags[11] - 5);
                            for (short i = 0; i < 9; i++) {
                                if ((tmp & scene->flags[14]) != 0 && isInRect(input, x + 32 * (i % 3) + 2, 482 + 32 * (i / 3), 28, 28)) {
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
                    }
                    case 2: { // Select a square in the grid
                        if (input->keys[SDL_SCANCODE_ESCAPE]) {
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

                        if (scene->flags[9] == 0) { // If first tile
                            if (input->mouse[SDL_BUTTON_LEFT]) {
                                if (scene->flags[2]) return;
                                scene->flags[2] = 1;

                                for (short i = 0; i < size; i++) {
                                    if (isInRect(input, scene->data[2]->x + 2 + 32 * (i % width), scene->data[2]->y + 2 + 32 * (i / width), 28, 28)) {
                                        scene->flags[13] = i;
                                        int pos = i - width * (scene->flags[12] / 3) - scene->flags[12] % 3;

                                        if (isInGrid(scene->data[scene->flags[11]]->sprite, pos, scene->flags[12], width, height)) {
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
                            if (input->mouse[SDL_BUTTON_LEFT]) {
                                if (scene->flags[2]) return;
                                scene->flags[2] = 1;

                                for (short i = 0; i < size; i++) {
                                    if (isdigit(scene->data[2]->sprite[i])
                                        && isInRect(input, scene->data[2]->x + 2 + 32 * (i % width),scene->data[2]->y + 2 + 32 * (i / width), 28, 28)) {
                                        scene->flags[13] = i;
                                        int pos = i - width * (scene->flags[12] / 3) - scene->flags[12] % 3;

                                        if (isValidPos(scene->data[2]->sprite, scene->data[scene->flags[11]]->sprite, pos, width, size, false)) {
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
                    }
                    case 3: { // End of turn
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
                        scene->flags[2] = 0;

                        scene->flags[4] = 0;

                        bool res = false;
                        for (int i = 5; i < 10; i++) {
                            if (getNumberOfMoves(scene->data[2]->sprite, scene->data[i]->sprite, width, height, false) > 0) {
                                res = true;
                            }
                        }

                        if (!res) {
                            endGame(scene);
                        }

                        break;
                    }
                    case 4: { // end of game
                        if (input->mouse[SDL_BUTTON_LEFT]) {
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
                }
                break;
            }
            // =============================================================================================================
            case 2: { // GAME 2-PLAYERS
                if (input->mouse[SDL_BUTTON_LEFT]) {
                    if (isOnObject(scene, 19, input, 48, 48)) {
                        char *tiles[10];
                        for (int i = 0; i < 10; i++) {
                            tiles[i] = scene->data[5 + i]->sprite;
                        }

                        save(scene->flags, scene->data[2]->sprite, tiles);

                        int buttonid;
                        if (displaySaveMessage(window->handle, &buttonid) == -1) {
                            buttonid = -1;
                        }

                        // Only way to recover the input focus in this case!
                        hideWindow(window);
                        showWindow(window);

                        scene->flags[2] = 1;

                        if (buttonid == 0) {
                            changeScene(scene, 0);
                        }

                        return;
                    } else if (isOnObject(scene, 18, input, 48, 48)) {
                        scene->flags[15] = 1 + scene->flags[8];
                        endGame(scene);
                    }
                }

                short width = scene->flags[7] == 0 ? 6 : scene->flags[7] == 1 ? 12 : 18;
                short height = scene->flags[7] == 0 ? 3 : scene->flags[7] == 1 ? 6 : 9;
                short size = width * height;

                switch(scene->flags[4]) { // SCENE CONTROLLER
                    case 0: { // Select a tile to set on grid
                        short startHand = scene->flags[8] ? 10 : 5;
                        for (short i = startHand; i < startHand + 5; i++) {
                            if (isOnObject(scene, i, input, 96, 116)) {
                                scene->data[i]->y = 480;
                                if (input->mouse[SDL_BUTTON_LEFT]) {
                                    if (scene->flags[2]) return;
                                    scene->flags[2] = 1;

                                    scene->data[i]->z = -1;
                                    scene->data[i]->flush = true;

                                    sprintf(scene->data[17]->sprite, "JOUEUR %d: Selectionnez la case a placer", scene->flags[8] + 1);
                                    scene->data[17]->flush = true;

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
                    }
                    case 1: { // Select the character on the tile
                        if (input->keys[SDL_SCANCODE_ESCAPE]) {
                            if (scene->flags[3]) return;
                            scene->flags[3] = 1;

                            scene->data[scene->flags[11]]->z = 0;
                            scene->data[scene->flags[11]]->flush = true;

                            sprintf(scene->data[17]->sprite, "JOUEUR %d: Selectionnez une tuile", scene->flags[8] + 1);
                            scene->data[17]->flush = true;

                            scene->flags[11] = 0;

                            scene->flags[4] = 0;
                        } else {
                            scene->flags[3] = 0;
                        }

                        if (input->mouse[SDL_BUTTON_LEFT]) {
                            if (scene->flags[2]) return;
                            scene->flags[2] = 1;

                            short startHand = scene->flags[8] ? 10 : 5;

                            int tmp = 1;
                            int x = 144 + 104 * (scene->flags[11] - startHand);
                            for (short i = 0; i < 9; i++) {
                                if ((tmp & scene->flags[14]) != 0
                                    && isInRect(input, x + 32 * (i % 3) + 2, 482 + 32 * (i / 3), 28, 28)) {
                                    scene->data[scene->flags[11]]->z = i + 1;
                                    scene->data[scene->flags[11]]->flush = true;

                                    sprintf(scene->data[17]->sprite, "JOUEUR %d: Selectionnez une case sur la grille", scene->flags[8] + 1);
                                    scene->data[17]->flush = true;

                                    scene->flags[12] = i;

                                    scene->flags[4] = 2;
                                }
                                tmp *= 2;
                            }
                        } else {
                            scene->flags[2] = 0;
                        }
                        break;
                    }
                    case 2: { // Select a square in the grid
                        if (input->keys[SDL_SCANCODE_ESCAPE]) {
                            if (scene->flags[3]) return;
                            scene->flags[3] = 1;

                            scene->data[scene->flags[11]]->z = -1;
                            scene->data[scene->flags[11]]->flush = true;

                            sprintf(scene->data[17]->sprite, "JOUEUR %d: Selectionnez la case a placer", scene->flags[8] + 1);
                            scene->data[17]->flush = true;

                            scene->flags[12] = 0;

                            scene->flags[4] = 1;
                        } else {
                            scene->flags[3] = 0;
                        }

                        if (scene->flags[9] == 0 || scene->flags[10] == 0) { // If first tile for current player
                            if (input->mouse[SDL_BUTTON_LEFT]) {
                                if (scene->flags[2]) return;
                                scene->flags[2] = 1;

                                for (short i = 0; i < size; i++) {
                                    if (isInRect(input, scene->data[2]->x + 2 + 32 * (i % width),scene->data[2]->y + 2 + 32 * (i / width), 28, 28)) {
                                        scene->flags[13] = i;
                                        int pos = i - width * (scene->flags[12] / 3) - scene->flags[12] % 3;

                                        if (isInGrid(scene->data[scene->flags[11]]->sprite, pos, scene->flags[12], width, height)
                                        && isValidPosFirstTurn(scene->data[2]->sprite, scene->data[scene->flags[11]]->sprite, pos, width)) {
                                            setTile(scene->data[2]->sprite, scene->data[scene->flags[11]]->sprite, pos, -1, width, 0);
                                            scene->data[2]->flush = true;

                                            scene->flags[4] = 3;
                                        } else {
                                            strcpy(scene->data[17]->sprite, "ACT: Tuile en dehors!");
                                            scene->data[17]->flush = true;
                                        }
                                    }
                                }

                            } else {
                                scene->flags[2] = 0;
                            }
                        } else {
                            if (input->mouse[SDL_BUTTON_LEFT]) {
                                if (scene->flags[2]) return;
                                scene->flags[2] = 1;

                                for (short i = 0; i < size; i++) {
                                    if (isdigit(adjustChar(scene->data[2]->sprite[i])) && isInRect(input, scene->data[2]->x + 2 + 32 * (i % width),scene->data[2]->y + 2 + 32 * (i / width), 28, 28)) {
                                        scene->flags[13] = i;
                                        int pos = i - width * (scene->flags[12] / 3) - scene->flags[12] % 3;

                                        if (isValidPos(scene->data[2]->sprite, scene->data[scene->flags[11]]->sprite, pos, width, size, scene->flags[8])) {
                                            setTile(scene->data[2]->sprite, scene->data[scene->flags[11]]->sprite, pos,scene->flags[12], width, height);
                                            scene->data[2]->flush = true;

                                            scene->flags[4] = 3;
                                        } else {
                                            strcpy(scene->data[17]->sprite, "ACT: Placement incorrect!");
                                            scene->data[17]->flush = true;
                                        }
                                    }
                                }
                            } else {
                                scene->flags[2] = 0;
                            }
                        }

                        break;
                    }
                    case 3: { // End of turn
                        int flags = 0;
                        if (scene->flags[6]) flags |= 1;
                        if (scene->flags[5]) flags |= 2;
                        if (scene->flags[8]) flags |= 4;

                        if(scene->flags[8]) {
                            scene->flags[10]++;

                            sprintf(scene->data[16]->sprite, "SCORE 2: %d", scene->flags[10]);
                            scene->data[16]->flush = true;
                        } else {
                            scene->flags[9]++;

                            sprintf(scene->data[15]->sprite, "SCORE 1: %d", scene->flags[9]);
                            scene->data[15]->flush = true;
                        }

                        scene->data[scene->flags[11]]->z = 0;
                        generateTile(scene->data[scene->flags[11]]->sprite, flags);
                        scene->data[scene->flags[11]]->flush = true;

                        scene->flags[11] = 0;
                        scene->flags[2] = 0;
                        scene->flags[4] = 0;

                        bool canP1Play = false;
                        bool canP2Play = false;

                        for (int i = 5; i < 10; i++) {
                            if (getNumberOfMoves(scene->data[2]->sprite, scene->data[i]->sprite, width, height, false) > 0) {
                                canP1Play = true;
                            }
                        }

                        for (int i = 10; i < 15; i++) {
                            if (getNumberOfMoves(scene->data[2]->sprite, scene->data[i]->sprite, width, height, true) > 0) {
                                canP2Play = true;
                            }
                        }

                        if(!scene->flags[16]) { // Change player when all can play
                            scene->flags[8] = !scene->flags[8];
                            for (int i = 5; i < 15; i++) {
                                scene->data[i]->isVisible = !scene->data[i]->isVisible;
                            }
                        }

                        if (!canP1Play && !canP2Play) {
                            endGame(scene);
                            return;
                        } else if (!canP1Play && scene->flags[9] > 0 && !scene->flags[16]) {
                            scene->flags[16] = 1;

                            scene->data[18]->isVisible = false;
                            scene->data[19]->isVisible = false;

                            scene->data[20]->isVisible = true;
                            scene->data[22]->isVisible = true;
                            scene->data[23]->isVisible = true;
                            scene->data[28]->isVisible = true;
                            scene->data[29]->isVisible = true;

                            strcpy(scene->data[22]->sprite, "Joueur 1 ne peut plus jouer!");
                            scene->data[22]->flush = true;

                            strcpy(scene->data[23]->sprite, "Joueur 2, voulez-vous continuer?");
                            scene->data[23]->flush = true;

                            scene->flags[4] = 5;
                        } else if (!canP2Play && scene->flags[10] > 0 && !scene->flags[16]) {
                            scene->flags[16] = 1;

                            scene->data[18]->isVisible = false;
                            scene->data[19]->isVisible = false;

                            scene->data[20]->isVisible = true;
                            scene->data[22]->isVisible = true;
                            scene->data[23]->isVisible = true;
                            scene->data[28]->isVisible = true;
                            scene->data[29]->isVisible = true;

                            strcpy(scene->data[22]->sprite, "Joueur 2 ne peut plus jouer!");
                            scene->data[22]->flush = true;

                            strcpy(scene->data[23]->sprite, "Joueur 1, voulez-vous continuer?");
                            scene->data[23]->flush = true;

                            scene->flags[4] = 5;
                        }

                        sprintf(scene->data[17]->sprite, "JOUEUR %d: Selectionnez une tuile", scene->flags[8] + 1);
                        scene->data[17]->flush = true;

                        break;
                    }
                    case 4: { // end of game
                        if (input->mouse[SDL_BUTTON_LEFT]) {
                            if (scene->flags[2]) return;
                            scene->flags[2] = 1;

                            if (isOnObject(scene, 27, input, 128, 48)) {
                                changeScene(scene, 0);
                                return;
                            }
                        } else {
                            scene->flags[2] = 0;
                        }

                        break;
                    }
                    case 5: { // end of game for one player
                        if (input->mouse[SDL_BUTTON_LEFT]) {
                            if (scene->flags[2]) return;
                            scene->flags[2] = 1;

                            if (isOnObject(scene, 29, input, 128, 48)) {
                                changeScene(scene, 0);
                                return;
                            } else if (isOnObject(scene, 28, input, 128, 48)) {
                                scene->flags[4] = 0;

                                scene->data[18]->isVisible = true;
                                scene->data[19]->isVisible = true;

                                scene->data[20]->isVisible = false;
                                scene->data[22]->isVisible = false;
                                scene->data[23]->isVisible = false;
                                scene->data[28]->isVisible = false;
                                scene->data[29]->isVisible = false;
                            }
                        } else {
                            scene->flags[2] = 0;
                        }

                        break;
                    }
                }
                break;
            }
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
