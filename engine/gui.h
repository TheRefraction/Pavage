#ifndef BUTTON_H
#define BUTTON_H
/**
 * @file gui.h
 * concerne gui
 */
#include <stdbool.h>

#include "scene.h"

/**
 * isInRect - Checks if the mouse cursor is in a region
 * @param input Pointer on the input system
 * @param x X Coordinate
 * @param y Y Coordinate
 * @param width Width
 * @param height Height
 * @return bool
 */
bool isInRect(Input *input, int x, int y, int width, int height);

/**
 * isOnObject - Checks if the mouse cursor is on an object
 * @param scene Pointer on the current scene
 * @param index Index of the object to check
 * @param input Pointer on the input system
 * @param width Width of object
 * @param height Height of object
 * @return boolean
 */
bool isOnObject(Scene *scene, int index, Input *input, int width, int height);

#endif
