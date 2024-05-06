#ifndef SCENE_H
#define SCENE_H

#include "../game/constants.h"
#include "objectdata.h"

#include <stdbool.h>

typedef struct SCENE_STRUCT {
    int id;
    int lastIndex;
    bool isReady;
    ObjectData objects[MAX_OBJECTS];
} Scene;

void initScene(Scene *scene, int id);
void updateScene(Scene *scene);
void destroyScene(Scene *scene);

void pushScene(Scene *scene, ObjectData object);
ObjectData* popScene(Scene *scene);

#endif
