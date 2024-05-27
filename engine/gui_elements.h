#ifndef BUTTON_H
#define BUTTON_H

#include <stdbool.h>

#include "scene.h"

/**
 * isOnObject - Checks if the mouse cursor is on an object
 * @param scene Pointer on the current scene
 * @param index Index of the object to check
 * @param input Pointer on the input system
 * @return boolean
 */
bool isOnObject(Scene *scene, int index, Input *input);

#endif
