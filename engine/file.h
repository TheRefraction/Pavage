#ifndef FILE_H
#define FILE_H
/**
 * @file file.h
 * concerne la sauvegarde
 */

#include <stdbool.h>

bool fileExists(const char *filename);

void save(short flags[256], char *grid, char **tiles);

void load(short flags[256], char buffers[16][256]);

#endif
