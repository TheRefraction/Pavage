#include "gui_elements.h"

bool isOnObject(Scene *scene, int index, Input *input) {
    if (input->cursor[0] >= scene->data[index]->x && input->cursor[0] <= scene->data[index]->x + 96
        && input->cursor[1] >= scene->data[index]->y && input->cursor[1] <= scene->data[index]->y + 32) {
        return true;
    } else return false;
}