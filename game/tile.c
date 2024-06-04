#include "tile.h"

#include <stdlib.h>

bool isInGrid(char **tile, int x, int y, int w, int h) {
    for (int i=0; i<=2; i++){
        for (int j=0; j<=2; j++){
            if (tile[i][j] == 0) {
                continue;
            } else if(y+i >= 0 && y+i <= h+2 && x+j >= 0 && x+j <= w+2){
                return true;
            }
        }
    }
    return false;
}

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

bool isInTile(char *tab, char c) {
    int i = 0;
    bool res = false;
    while(i < 9 || res) {
        if(tab[i] == c) {
            res = true;
        }
        i++;
    }
    return res;
}

int setTile() {
    int XisFalse = 0, ligneplateau, colonneplateau, numTuile, pi, pinit, i = 0;//enlever les valeurs de ligneplateau et colonneplateau pour les remplacer par celles choisis par le joueur
    int c, l; //valeur a remplacer par celles du plateau
    char tuile[9] = {'X', ' ', ' ', '1', ' ', '1', ' ', ' ', '1'};//valeurs test
    char plateau[16] = {'X', '1', ' ', ' ', ' ', ' ', ' ', '1', 'X', ' ', ' ', ' ', ' ', '1', ' ', ' '};// valeurs test
    /*
    do{
        printf("quelle tuile voulez vous placer?(entre 1 et 5)\n");
        scanf("%d",&numTuile);
    }while(numTuile<1||numTuile>5);

    do {
        printf("ligne ou voulez vous placer la case sup gauche de la tuile\n ");
        scanf("%d", &ligneplateau);
    }while(ligneplateau<0||ligneplateau>c);

    do{
        printf("colonne ou voulez vous placer la case sup gauche de la tuile\n");
        scanf("%d", &colonneplateau);
    }while (colonneplateau<0||colonneplateau>l);*/

    pinit = (colonneplateau - 1) + (ligneplateau - 1) *
                                   c; //initialise la position p1 dans lquelle on vient placer t1 (meme valeur pour tout le programme

    //la boucle for ci dessous permet de verifier que tous les X sont placer sur un '1' (voir pour les autres nombres){commence par regarder si une case d'une tuile est égal à X

    // si c'est le case ça regarde si la case pi correspondante est égal à '1' et si c'est différent cela met le compteur Xisfalse à 1;
    for (i = 0; i <= 8; i++) {

        pi = pinit + i % 3 + (i / 3) * c;//modifie la valeur de pi
        if (tuile[i] == 'X') {
            if (plateau[pi] != '1') {
                XisFalse = 1;
            }
        }

    }
    if (XisFalse ==
        0) {//si Xisfalse est égal à 0 cela veut dire que tous les X sont placés sur des nombres donc on peut enchainer avec la suite du programme
        for (int j = 0; j <= 8; j++) {//meme debut que avant
            pi = pinit + j % 3 + (j / 3) * c;
            switch (plateau[pi]) {//en fonction de la valeur du plateau on modifie les données du plateau
                case 'X': //si la case du plateau =X ras
                    break;
                case '1':
                    if (tuile[j - 1] == 'X') {
                        plateau[pi] = 'X';

                    } else {
                        plateau[pi] = plateau[pi] + tuile[j - 1] - 48;
                    }
                    break;
                case ' ':
                    plateau[pi] = tuile[j];
                    break;
                case '2':
                    if (tuile[j] == 'X') {
                        plateau[pi] = 'X';
                    } else {
                        plateau[pi] = plateau[pi] + tuile[j] - 48;
                    }
                    break;
                default:
                    break;

            }

        }

// IMPORTANT// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

        //GenerationTuile();//modifier et mettre la fct plus haut

    } else {//si Xisfalse est égal à1 le placement est faux

    }
    return 0;
}

void generateTile(char *str, int difficulty) {
    int i = rand() % 9; //65 -> 90
    str[i] = 'X';

    /*int combien=rand()%3+1;
    int index[combien];*/
    /*for(int i=0; i<combien; i++) {
        int marcel=rand()%9;
        while(marcel == chiffre) { //|| isInIndex(index, marcel, combien)) {
            marcel=rand()%9;
        }
        index[i]=marcel;
        tile1[index[i]]=1;
    }*/
}