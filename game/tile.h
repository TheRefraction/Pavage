#ifndef TILE_H
#define TILE_H

#include <stdbool.h>

/**
 * digitToChar - Converts a digit number to its ASCII code (39->47: -1...9, 48->0:, 49->57:1...9)
 * @param i The number to convert
 * @return char
 */
char digitToChar(int i);

/**
 * charToDigit - Converts a character from a tile or a grid to its digit value
 * @param c The character to convert
 * @return int
 */
int charToDigit(char c);

/**
 * adjustChar - Converts a negative digit character to a positive digit character
 * @param c The character to adjust
 * @return char
 */
char adjustChar(char c);

/**
 * isNegativeDigit - Checks if a character represents a negative digit
 * @param c
 * @return bool
 */
bool isNegativeDigit(char c);

/**
 * initArray - Initializes a string
 * @param arr The string to initialize
 * @param size Size of the array
 * @param e Character to initialize the array with
 */
void initArray(char *arr, int size, char e);

/**
 * isInTile - Checks if a character belongs to a tile
 * @param arr The string that holds the tile's data
 * @param c The character to check
 * @return bool
 */
bool isInTile(char *arr, char c);

/**
 * populateTile - Randomly populates a tile
 * @param str The string that holds the tile's data
 * @param set Array that keeps in memory which tile's squares are empty
 * @param flags Current flags
 * @param digit Generates digits?
 */
void populateTile(char *str, bool *set, int flags, bool digit);

/**
 * generateTile - Randomly generates a tile depending on the current mode
 * @param str The string that holds the tile's data
 * @param flags Current mode
 */
void generateTile(char *str, int flags);

#endif