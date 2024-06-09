#include "gui.h"

bool isOnObject(Scene *scene, int index, Input *input, int width, int height) {
    if (scene->data[index]->isVisible && input->cursor[0] >= scene->data[index]->x && input->cursor[0] <= scene->data[index]->x + width
        && input->cursor[1] >= scene->data[index]->y && input->cursor[1] <= scene->data[index]->y + height) {
        return true;
    } else return false;
}