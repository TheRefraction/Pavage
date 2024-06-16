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
        for(int i = 5; i < 11; i++) {
            fprintf(file, "%d\n", flags[i]);
        }

        fprintf(file, "%d\n", flags[16]);

        size_t sizeGrid = (flags[7] == 0) ? 18 : (flags[7] == 1) ? 72 : 162;
        size_t numTiles = flags[5] ? 10 : 5;

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
    while((flags[5] && i < 18) || (!flags[5] && i < 13)) {
        fgets(buffer, 256, file);

        if(i > 6) {
            strcpy(buffers[i - 7], buffer);
        } else if(i == 6) {
            flags[16] = atoi(buffer);
        } else {
            flags[5 + i] = atoi(buffer);
        }

        i++;
    }
    fclose(file);
}
