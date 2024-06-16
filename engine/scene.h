/**
 * @file scene.h
 * concerns scene
 */

#ifndef SCENE_H
#define SCENE_H

#include "../game/constants.h"
#include "object.h"
#include "input.h"
#include "window.h"

#include <stdbool.h>

typedef struct SCENE_STRUCT {
    short id;
    bool isReady;
    short flags[MAX_FLAGS];
    // 0: Flush Renderer | 1: Buffers used? | 2: Has pressed LEFT_BUTTON? | 3: Has pressed ESC? |
    // 4: Scene controller | 5: 2 players? | 6: Difficulty | 7: Grid size |
    // 8: Turn | 9: Score 1 | 10: Score 2 | 11: Selected tile |
    // 12: Selected character on tile | 13: Selected square on grid | 14: Position of each char on tile (TO REWORK)
    char buffers[MAX_BUFFERS][BUFFER_SIZE];
    ObjectData *data[MAX_OBJECTS];
} Scene;

/** initScene - Initializes the current scene
 *
 * @param scene Pointer on the scene to initialize
 * @param id Which scene ID to load
 */
void initScene(Scene *scene, short id);

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