#include "tile.h"

#include <stdlib.h>
#include <ctype.h>


char digitToChar(int i) {
    if (i > 0 && i <= 9) {
        return 48 + i;
    } else if (i >= -9 && i < 0) {
        return 38 - i;
    } else {
        return 48;
    }
}

int charToDigit(char c) {
    if(c >= 39 && c <= 47) {
        return 38 - c;
    } else if(c >= 48 && c <= 57) {
        return c - 48;
    } else {
        return 0;
    }
}

char adjustChar(char c) {
    if(c >= 39 && c <= 47) {
        return c + 10;
    } else {
        return c;
    }
}

bool isNegativeDigit(char c) {
    if(c >= 39 && c <= 47) {
        return true;
    } else {
        return false;
    }
}

void initArray(char *arr, int size, char e) {
    for (int i = 0; i < size; i++) {
        arr[i] = e;
    }
}

bool isInTile(char *arr, char c) {
    int i = 0;
    bool res = false;
    while(i < 9 && !res) {
        if(arr[i] == c) {
            res = true;
        }
        i++;
    }
    return res;
}

bool isInGrid(char *arr, int pos, int choice, int gridSize) {
    int width, height;
    if(gridSize == 0) {
        width = 6;
        height = 3;
    } else if (gridSize == 1) {
        width = 12;
        height = 6;
    } else if (gridSize == 2) {
        width = 18;
        height = 9;
    }

    int xPos = pos % width;
    int yPos = pos / width;
    // si yPos < 0 faire -1 à yPos (à cause de division euclidienne)

    if(xPos == (width - 2)) {
        if(choice % 3 == 2) { // tronquer les colonnes 0 et 1
            if(arr[0] != ' ' || arr[1] != ' ' || arr[3] != ' ' || arr[4] != ' ' || arr[6] != ' ' || arr[7] != ' ') {
                return false;
            }
        } else { // tronquer la colonne 2
            if(arr[2] != ' ' || arr[5] != ' ' || arr[8] != ' ') {
                return false;
            }
        }
    } else if(xPos == (width - 1)) {
        if(choice % 3 == 0) { // tronquer les colonnes 1 et 2
            if(arr[1] != ' ' || arr[2] != ' ' || arr[4] != ' ' || arr[5] != ' ' || arr[7] != ' ' || arr[8] != ' ') {
                return false;
            }
        } else { // tronquer la colonne 0
            if(arr[0] != ' ' || arr[3] != ' ' || arr[6] != ' ') {
                return false;
            }
        }
    }

    if(yPos == -2) { // tronquer les lignes 0 et 1
        if(arr[0] != ' ' || arr[1] != ' ' || arr[2] != ' ' || arr[3] != ' ' || arr[4] != ' ' || arr[5] != ' ') {
            return false;
        }
    } else if(yPos == -1) { // tronquer la ligne 0
        if(arr[0] != ' ' || arr[1] != ' ' || arr[2] != ' ') {
            return false;
        }
    } else if(yPos == (height - 2)) { // tronquer la ligne 2
        if(arr[6] != ' ' || arr[7] != ' ' || arr[8] != ' ') {
            return false;
        }
    } else if(yPos == (height - 1)) { // tronquer les lignes 1 et 2
        if(arr[3] != ' ' || arr[4] != ' ' || arr[5] != ' ' || arr[6] != ' ' || arr[7] != ' ' || arr[8] != ' ') {
            return false;
        }
    }

    return true;
}

void populateTile(char *str, bool *set, int flags, bool digit) {
    bool hard = (1 & flags) != 0;
    bool multi = (2 & flags) != 0;
    bool playerTwo = (4 & flags) != 0;

    int n;
    if(digit) {
        n = rand() % 3 + 1;
        if(hard) n++;
    } else {
        n = hard + 1;
    }

    for(int k = 0; k < n; k++) {
        int i;
        do {
            i = rand() % 9;
        } while (set[i]);

        set[i] = true;
        char c;
        do {
            if(digit) {
                if(playerTwo) {
                    c = rand() % 3 + 39;
                } else {
                    c = rand() % 3 + 49;
                }
            } else {
                if(multi) {
                    if(playerTwo) {
                        c = rand() % 2 + 88;
                    } else {
                        c = rand() % 2 + 65;
                    }
                } else {
                    c = rand() % 26 + 65;
                }
            }
        } while (isInTile(str, c) && !digit);

        str[i] = c;
    }
}

void generateTile(char *str, int flags) {
    bool set[9] = {false};

    initArray(str, 9, ' ');

    populateTile(str, set, flags, false);
    populateTile(str, set, flags, true);
}

int setTile(char plateau[], char tuile[]) {
    int XisFalse = 0, ligneplateau, colonneplateau, numTuile, pi, pinit, i = 0;//enlever les valeurs de ligneplateau et colonneplateau pour les remplacer par celles choisis par le joueur
    int c, l,k; //valeur a remplacer par celles du plateau
    //char tuile[9] = {'X', ' ', ' ', '1', ' ', '1', ' ', ' ', '1'};//valeurs test
    //char plateau[16] = {'X', '1', ' ', ' ', ' ', ' ', ' ', '1', 'X', ' ', ' ', ' ', ' ', '1', ' ', ' '};// valeurs test
    char caractere;

    do{
        k=0;
        //printf("quel caractere de la tuile %d voulez vous placer\n",numTuile);
        //scanf(" %c",&caractere);
        caractere=toupper(caractere);

        for (int z=0;z<=8;z++){
            if(tuile[i]==caractere){
                k=1;
            }
        }
    }while(k=0);

    /*do {
        printf("ligne ou voulez vous placer la case sup gauche de la tuile\n ");
        scanf("%d", &ligneplateau);
    }while(ligneplateau<0||ligneplateau>c);

    do{
        printf("colonne ou voulez vous placer la case sup gauche de la tuile\n");
        scanf("%d", &colonneplateau);
    }while (colonneplateau<0||colonneplateau>l);*/

    pinit = (colonneplateau - 1) + (ligneplateau - 1)*c; //initialise la position p1 dans lquelle on vient placer t1 (meme valeur pour tout le programme

    //la boucle for ci dessous permet de verifier que tous les X sont placer sur un '1' (voir pour les autres nombres){commence par regarder si une case d'une tuile est égal à X

    // si c'est le case ça regarde si la case pi correspondante est égal à '1' et si c'est différent cela met le compteur Xisfalse à 1;

    for (i = 0; i <= 8; i++) {

        pi = pinit + i % 3 + (i / 3) * c;//modifie la valeur de pi
        if (tuile[i] == caractere) {
            if (plateau[pi] != '1') {//marche seulement pour 1
                XisFalse = 1;
            }
        }
    }
    if (XisFalse ==0) {//si Xisfalse est égal à 0 cela veut dire que tous les X sont placés sur des nombres donc on peut enchainer avec la suite du programme
        for (int j = 0; j <= 8; j++) {//meme debut que avant
            pi = pinit + j % 3 + (j / 3) * c;
            switch (plateau[pi]) {//en fonction de la valeur du plateau on modifie les données du plateau
                case '1':
                    if (tuile[j] == caractere) {
                        plateau[pi] = caractere;
                    } else {
                        plateau[pi] = digitToChar(charToDigit(plateau[pi]) + charToDigit(tuile[j - 1]));//trop fatigué pour verrifier
                    }
                    break;
                case ' ':
                    plateau[pi] = tuile[j];
                    break;
                case '2':
                    if (tuile[j] == caractere) {
                        plateau[pi] = caractere;
                    } else {
                        plateau[pi] = plateau[pi] + tuile[j] - 48;
                    }
                    break;
                default:
                    break;
            }
        }

    // IMPORTANT// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //generer une nouvelle tuile
    // score augmente de 1

    } else {
        //si Xisfalse est égal à 1 le placement est faux donc message d'erreur et retry
        //printf("le placement est faux"); ====== a remplacer
    }
    return 0;
}