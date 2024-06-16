/**
 * @file misc.h
 * Miscellaneous functions
 */

#ifndef MISC_H
#define MISC_H

#include "SDL2/SDL.h"

#include "../engine/scene.h"

/**
 *
 * @param size
 * @param x
 * @param y
 * @param str1
 * @param str2
 */
void initGridPosAndLabels(short size, int *x, int *y, char str1[96], char str2[96]);

/**
 *
 * @param handle
 * @param buttonid
 * @return
 */
int displaySaveMessage(SDL_Window *handle, int *buttonid);

/**
 *
 * @param scene
 */
void endGame(Scene *scene);

#endif
