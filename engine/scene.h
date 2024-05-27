#ifndef SCENE_H
#define SCENE_H

#include "../game/constants.h"
#include "object.h"
#include "input.h"

#include <stdbool.h>

typedef struct SCENE_STRUCT {
    int id;
    int lastIndex;
    bool isReady;
    ObjectData *data[MAX_OBJECTS];
} Scene;

/** initScene - initialise une nouvelle scène
 *
 * @param scene - scene à preparer
 * @param id - nom de la scene
 */

void initScene(Scene *scene, int id);

/**
 * updateScene- met à jour la scène
 * @param scene - scène à modifier
 * @param input - action à effectuer
 */
void updateScene(Scene *scene, Input *input);

/**
 * destroyScene - supprime la scène pour liberer de la memoire
 * @param scene - nom de la scène à detruire
 */
void destroyScene(Scene *scene);

#endif
