#include "file.h"
#include <stdio.h>
#include <string.h>

void save(int nb_players, int difficulty, int grid_size[2], int score[2], int isP1Turn) {
    FILE* file = fopen("sav.dat", "w");
    if(file != NULL) {
        fprintf(file, "%d\n%d\n%d %d\n%d %d\n%d\n", nb_players, difficulty, grid_size[0], grid_size[1], score[0], score[1], isP1Turn);
        // how many players ?
        // | difficulty
        // | grid size
        // | scores
        // | p1 or p2 turn


        // TO DO : SAVE EACH PLAYERS' TILES
    }
    fclose(file);
}

void load() {
    FILE* file = fopen("sav.dat", "r");
    if(file != NULL) {
        //strtok
    }
    fclose(file);
}
