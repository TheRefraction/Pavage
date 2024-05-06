#ifndef SCENE_H
#define SCENE_H

#include "object.h"
#include "../game/constants.h"

typedef struct SCENE_STRUCT {
    int id;
    Object *objects[MAX_OBJECTS];
} Scene;

#endif
