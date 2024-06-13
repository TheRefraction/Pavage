#include "tile.h"
#include "SDL2/SDL_log.h"

#include <stdlib.h>
#include <ctype.h>

char digitToChar(int i) {
    if (i > 0 && i <= 9) { //nombres positifs
        return 48 + i; //48 est le code ASCII du zéro
    } else if (i >= -9 && i < 0) { //nombres négatifs
        return 38 - i; //39 est le code de -1 définit arbitrairement
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
    if(c >= 39 && c <= 47) { //si le nombre est négatif on le convertit en nombre positif
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

short getTileCharsPosition(char *arr) {
    short res = 0;
    short tmp = 1;
    for(int i = 0; i < 9; i++) {
        if(arr[i] != ' ' && !isdigit(arr[i])) {
            res |= tmp;
        }
        tmp *= 2;
    }
    return res;
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

bool isInGrid(char *arr, int pos, int choice, int width, int height) {
    int xPos = pos % width; //coordonnée de x de la case la plus en haut à gauche
    int yPos = (pos < 0) ? pos / width - 1 : pos / width; // coordonnée de y de la case la plus en haut à gauche

    if(xPos < 0) {
        xPos = width + xPos;
    }

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

bool isValidPos(char *grid, char *tile, int pos, int width, bool p2) {
    for (int i = 0; i < 9; i++) {
        int pi = pos + i % 3 + (i / 3) * width;
        if(isalpha(tile[i]) && (grid[pi] == '0' || (!p2 && !isdigit(grid[pi])) || (p2 && !isNegativeDigit(grid[pi])))) {
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

void setTile(char *grid, char *tile, int pos, int choice, int width, int height) {
    bool col[3] = {false, false, false};
    bool lin[3] = {false, false, false};

    if(choice != -1) {
        int xPos = pos % width;
        int yPos = (pos < 0) ? pos / width - 1 : pos / width;

        if (xPos < 0) {
            xPos = width + xPos;
        }

        if(xPos == (width - 2)) {
            if(choice % 3 == 2) {
                col[0] = true;
                col[1] = true;
            } else {
                col[2] = true;
            }
        } else if(xPos == (width - 1)) {
            if(choice % 3 == 0) {
                col[1] = true;
                col[2] = true;
            } else {
                col[0] = true;
            }
        }

        if(yPos == -2) {
            lin[0] = true;
            lin[1] = true;
        } else if(yPos == -1) {
            lin[0] = true;
        } else if(yPos == (height - 2)) {
            lin[2] = true;
        } else if(yPos == (height - 1)) {
            lin[1] = true;
            lin[2] = true;
        }
    }

    for (int i = 0; i < 9; i++) {
        if(col[i % 3] || lin[i / 3]) {
            continue;
        }

        int pi = pos + i % 3 + (i / 3) * width;

        if(grid[pi] == ' ') {
            grid[pi] = tile[i];
        } else if(isdigit(adjustChar(grid[pi]))) {
            if(isdigit(adjustChar(tile[i]))) {
                int tmp = charToDigit(grid[pi]) + charToDigit(tile[i]);
                if(tmp > 9) {
                    tmp = 9;
                } else if(tmp < -9) {
                    tmp = -9;
                }
                grid[pi] = digitToChar(tmp);
            } else if (tile[i] != ' ') {
                grid[pi] = tile[i];
            }
        }
    }
}

int getNumberOfMoves(char *grid, char *tile, int width, int height, bool p2) {
    int size = width * height;
    int res = 0;
    for (int i = -2 * width; i < size + 2 * width; i++){
        if (isValidPos(grid, tile, i, width, p2)) {
            res++;
        }
    }
    return res;
}