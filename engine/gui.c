#include "gui.h"

bool isInRect(Input *input, int x, int y, int width, int height) {
    return input->cursor[0] >= x && input->cursor[0] <= x + width && input->cursor[1] >= y && input->cursor[1] <= y + height;
}

bool isOnObject(Scene *scene, int index, Input *input, int width, int height) {
    return scene->data[index]->isVisible && isInRect(input, scene->data[index]->x, scene->data[index]->y, width, height);
}

