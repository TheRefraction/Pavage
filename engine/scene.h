#ifndef SCENE_H
#define SCENE_H

#include "../game/constants.h"
#include "object.h"
#include "input.h"
#include "window.h"

#include <stdbool.h>

typedef struct SCENE_STRUCT {
    int id;
    bool isReady;
    short flags[256]; // 0: flush Renderer | 1: Players | 2 : Difficulty | 3: has pressed button |
    // 4: size grid | 5: first turn | 6: player 2 turn | 7: score 1 | 8: score 2
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