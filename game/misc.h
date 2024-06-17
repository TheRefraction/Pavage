/**
 * @file misc.h
 * Miscellaneous functions
 */

#ifndef MISC_H
#define MISC_H

#include "SDL2/SDL.h"

#include "../engine/scene.h"

/**
 * initGridPosAndLabels - Initializes the position and the labels around the grid
 * @param size Size of the grid
 * @param x Pointer to the X-Coordinate of the grid
 * @param y Pointer to the Y-Coordinate of the grid
 * @param str1 String that holds "A, B, C, ..."
 * @param str2 String that holds "1, 2, 3, ..."
 */
void initGridPosAndLabels(short size, int *x, int *y, char str1[96], char str2[96]);

/**
 * displaySaveMessage - Displays a message when saving and asks if the player wants to continue
 * @param handle Window handle
 * @param buttonid Result of message box
 * @return int (-1 if error when displaying)
 */
int displaySaveMessage(SDL_Window *handle, int *buttonid);

/**
 * endGame - Ends the current game session
 * @param scene Pointer to the current scene
 */
void endGame(Scene *scene);

#endif
