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

#endif