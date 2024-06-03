#include "tile.h"

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