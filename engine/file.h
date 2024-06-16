/**
 * @file file.h
 * Saving & loading system
 */

#ifndef FILE_H
#define FILE_H

#include <stdbool.h>

/**
 * fileExists - Checks if a file exists
 * @param filename Filename
 * @return bool
 */
bool fileExists(const char *filename);

/**
 * save - Saves the current game in session
 * @param flags Array that holds the flags of the current scene
 * @param grid String that holds the grid's data
 * @param tiles Array that holds each tile's data
 */
void save(short flags[256], char *grid, char **tiles);

/**
 * load - Loads the savefile
 * @param flags Array that holds the flags of the current scene
 * @param buffers Array of multiple buffers
 */
void load(short flags[256], char buffers[16][256]);

#endif
