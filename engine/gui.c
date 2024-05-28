#include "gui.h"

bool isOnObject(Scene *scene, int index, Input *input) {
    if (scene->data[index]->isVisible && input->cursor[0] >= scene->data[index]->x && input->cursor[0] <= scene->data[index]->x + 128
        && input->cursor[1] >= scene->data[index]->y && input->cursor[1] <= scene->data[index]->y + 48) {
        return true;
    } else return false;
}