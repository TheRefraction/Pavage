#include "button.h"

bool isOnButton(Scene *scene, int index, Input *input) {  //fonction qui renvoie un booléen pour savoir sur quel boutton est le curseur
    if (input->cursor[0] >= scene->data[index]->x && input->cursor[0] <= scene->data[index]->x + 96
        && input->cursor[1] >= scene->data[index]->y && input->cursor[1] <= scene->data[index]->y + 32)
    {
        return true;
    } else return false;
}