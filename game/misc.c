#include "misc.h"
#include "constants.h"

#include <string.h>

void initGridPosAndLabels(short size, int *x, int *y, char str1[96], char str2[96]) {
    if (size == 0) {
        *x = 304;
        *y = 202;
        strcpy(str1, "A   B   C   D   E   F");
        strcpy(str2, "1\n2\n3");
    } else if (size == 1) {
        *x = 208;
        *y = 154;
        strcpy(str1, "A   B   C   D   E   F   G   H   I   J   K   L");
        strcpy(str2, "1\n2\n3\n4\n5\n6");
    } else {
        *x = 112;
        *y = 106;
        strcpy(str1, "A   B   C   D   E   F   G   H   I   J   K   L   M   N   O   P   Q   R");
        strcpy(str2, "1\n2\n3\n4\n5\n6\n7\n8\n9");
    }
}

int displaySaveMessage(SDL_Window *handle, int *buttonid) {
    const SDL_MessageBoxButtonData buttons[] = {
            {0,                                       0, "Non"},
            {SDL_MESSAGEBOX_BUTTON_RETURNKEY_DEFAULT, 1, "Oui"},
    };

    const SDL_MessageBoxColorScheme colorScheme = {
            {
                    {255, 0, 0},
                    {0, 255, 0},
                    {255, 255, 0},
                    {0, 0, 255},
                    {255, 0, 255}
            }
    };

    const SDL_MessageBoxData messageboxdata = {
            SDL_MESSAGEBOX_INFORMATION,
            handle,
            WINDOW_TITLE,
            "Le jeu a été sauvegardé avec succès !\nVoulez-vous continuer la partie ?",
            SDL_arraysize(buttons),
            buttons,
            &colorScheme
    };

    if (SDL_ShowMessageBox(&messageboxdata, buttonid) < 0) {
        SDL_Log("Error displaying message box!");
        return -1;
    }

    return 0;
}