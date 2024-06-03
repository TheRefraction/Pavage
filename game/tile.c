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