/**
 * @file tile.h
 * concerns tiles
 */

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
 * getTileCharsPosition - Returns a number that holds the position in the tile of each "letter"
 * @param arr The string that holds the tile's data
 * @return short
 */
short getTileCharsPosition(char *arr);

/**
 * isInTile - Checks if a character belongs to a tile
 * @param arr The string that holds the tile's data
 * @param c The character to check
 * @return bool
 */
bool isInTile(char *arr, char c);

/**
 * isInGrid - Checks if each non-space character is in bounds
 * @param arr The string that holds the tile's data
 * @param pos The absolute position of the upper-left square of the tile
 * @param choice The square selected in the tile by the user
 * @param width Width of the grid
 * @param height Height of the grid
 * @return bool
 * @retval true tile is in the grid
 */
bool isInGrid(char *arr, int pos, int choice, int width, int height);

/**
 * isValidPos - Checks if the tile has a valid position on the grid
 * @param grid The string that holds the grid's data
 * @param tile The string that holds the tile's data
 * @param pos The absolute position of the upper-left square of the tile
 * @param width Width of the grid
 * @param p2 Is Player 2?
 * @return bool
 * @retval true (valide position )
 */
bool isValidPos(char *grid, char *tile, int pos, int width, bool p2);

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

/**
 * setTile - Set the tile in the grid
 * @param grid The string that holds the grid's data
 * @param tile The string that holds the tile's data
 * @param pos Position to set the tile on
 * @param choice The square selected in the tile by the user
 * @param width Width of the grid
 * @param height Height of the grid
 */
void setTile(char *grid, char *tile, int pos, int choice, int width, int height);

/**
 * getNumberOfMoves - Gets the number of remaining moves for one tile
 * @param grid The string that holds the grid's data
 * @param tile The string that holds the tile's data
 * @param width Width of the grid
 * @param height Height of the grid
 * @param p2 Is player 2 ?
 * @return
 */
int getNumberOfMoves(char *grid, char *tile, int width, int height, bool p2);

#endif