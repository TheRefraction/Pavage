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

void initScene(Scene *scene, int id);
void updateScene(Scene *scene, Input *input);
void destroyScene(Scene *scene);

#endif
