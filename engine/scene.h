#ifndef SCENE_H
#define SCENE_H

#include "../game/constants.h"
#include "object.h"
#include "input.h"
#include "window.h"

#include <stdbool.h>

typedef struct SCENE_STRUCT {
    int id;
    int lastIndex;
    bool isReady;
    ObjectData *data[MAX_OBJECTS];
} Scene;

/** initScene - Initializes the current scene
 *
 * @param scene Pointer on the scene to initialize
 * @param id Which scene ID to load
 */

void initScene(Scene *scene, int id);

/**
 * updateScene - Updates the current scene
 * @param scene Pointer on the current scene
 * @param input Pointer on the input system
 * @param window Pointer on the current window
 */
void updateScene(Scene *scene, Input *input, Window *window);

/**
 * destroyScene - Destroys the scene and its ObjectData and frees memory
 * @param scene Pointer on the scene to destroy
 */
void destroyScene(Scene *scene);

#endif