#ifndef MISC_H
#define MISC_H

#include "SDL2/SDL.h"

void initGridPosAndLabels(short size, int *x, int *y, char str1[96], char str2[96]);

int displaySaveMessage(SDL_Window *handle, int *buttonid);

#endif
