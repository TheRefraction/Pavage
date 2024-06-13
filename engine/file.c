#include "file.h"
#include "memory.h"

#include <stdio.h>
#include <stdlib.h>
#include <intrin.h>

bool fileExists(const char *filename) {
    FILE *f = fopen(filename, "r");
    if(f != NULL) {
        fclose(f);
        return true;
    } else {
        return false;
    }
}

void save(short flags[256], char *grid, char **tiles) {
    FILE* file = fopen("sav.dat", "w");
    if(file != NULL) {
        fprintf(file, "%d\n%d\n%d\n%d\n%d\n%d\n", flags[1], flags[6], flags[7], flags[8], flags[2], flags[4]);

        size_t sizeGrid = (flags[4] == 0) ? 18 : (flags[4] == 1) ? 72 : 162;
        size_t numTiles = flags[1] ? 10 : 5;

        for(int i = 0; i < sizeGrid; i++) {
            fprintf(file, "%c", grid[i]);
        }
        fprintf(file, "\n");

        for(int i = 0; i < numTiles; i++) {
            for(int j = 0; j < 9; j++) {
                fprintf(file, "%c", tiles[i][j]);
            }
            fprintf(file, "\n");
        }
    }
    fclose(file);
}

void load(short flags[256], char buffers[16][256]) {
    char buffer[256];
    int i = 0;

    FILE* file = fopen("sav.dat", "r");
    while((flags[1] && i < 17) || (!flags[1] && i < 12)) {
        fgets(buffer, 256, file);

        switch(i) {
            case 0:
                flags[1] = atoi(buffer);
                break;
            case 1:
                flags[6] = atoi(buffer);
                break;
            case 2:
                flags[7] = atoi(buffer);
                break;
            case 3:
                flags[8] = atoi(buffer);
                break;
            case 4:
                flags[2] = atoi(buffer);
                break;
            case 5:
                flags[4] = atoi(buffer);
                break;
            default:
                strcpy(buffers[i - 6], buffer);
                break;
        }
        i++;
    }
    fclose(file);
}
