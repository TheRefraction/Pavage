#include "misc.h"
#include "constants.h"

#include <string.h>
#include <stdio.h>

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

void endGame(Scene *scene) {
    if(scene->flags[5]) { // 2 PLAYERS SCREEN
        for (int i = 2; i < 20; i++) {
            scene->data[i]->isVisible = false;
        }

        for (int i = 20; i < 28; i++) {
            scene->data[i]->isVisible = true;
        }

        sprintf(scene->data[22]->sprite, "Mode: %s", scene->flags[6] ? "Difficile" : "Facile"); // TO CHECK
        scene->data[22]->flush = true;

        sprintf(scene->data[23]->sprite, "Taille de grille: %s", (scene->flags[7] == 0) ? "Petite" : (scene->flags[7] == 1 ? "Moyenne" : "Grande")); // TO CHECK
        scene->data[23]->flush = true;

        sprintf(scene->data[24]->sprite, "Score Joueur 1: %d", scene->flags[9]); // TO CHECK
        scene->data[24]->flush = true;

        sprintf(scene->data[25]->sprite, "Score Joueur 2: %d", scene->flags[10]); // TO CHECK
        scene->data[25]->flush = true;

        if(scene->flags[15] != 0) {
            sprintf(scene->data[26]->sprite, "Le joueur %d a abandonne!", scene->flags[15]);
        } else if(scene->flags[9] == scene->flags[10]) {
            strcpy(scene->data[26]->sprite, "Aucun joueur n'a gagne!");
        } else {
            sprintf(scene->data[26]->sprite, "Le joueur %d a gagne!", scene->flags[9] > scene->flags[10] ? 1 : 2);
        }
        scene->data[26]->flush = true;

        scene->flags[4] = 4;
    } else {
        for (int i = 2; i < 14; i++) {
            scene->data[i]->isVisible = false;
        }

        for (int i = 15; i < 21; i++) {
            scene->data[i]->isVisible = true;
        }

        sprintf(scene->data[17]->sprite, "Mode: %s", scene->flags[6] ? "Difficile" : "Facile"); // TO CHECK
        scene->data[17]->flush = true;

        sprintf(scene->data[18]->sprite, "Taille de grille: %s", (scene->flags[7] == 0) ? "Petite" : (scene->flags[7] == 1 ? "Moyenne" : "Grande")); // TO CHECK
        scene->data[18]->flush = true;

        sprintf(scene->data[19]->sprite, "Nombre de tuiles posees: %d", scene->flags[9]); // TO CHECK
        scene->data[19]->flush = true;

        scene->flags[4] = 4;
    }
}