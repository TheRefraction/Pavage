#ifndef OBJECTDATA_H
#define OBJECTDATA_H

#include <stdbool.h>

typedef struct OBJECT_DATA_STRUCT {
    int id;
    int x;
    int y;
    int z;
    bool null;
    bool renderered;
    bool isVisible;
    bool isUpdatable;
    char *sprite;
} ObjectData;

#endif
