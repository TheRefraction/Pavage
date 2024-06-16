/**
 * @file window.h
 * All functions managing windows
 */

#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>
#include <stdbool.h>

typedef struct WINDOW_STRUCT {
    SDL_Window *handle;
    SDL_Surface *surface;
    SDL_Surface *icon;

    char *title;
    int width;
    int height;

    bool isClosing;
    bool isVisible;
    bool isResizable;
    bool isFullscreen;

    bool hasKeyboardFocus;
    bool hasMouseFocus;
    bool hasGrabbedCursor;
} Window;

/**
 * initWindow - Initializes a window
 * @param window Pointer to the current window
 * @param title Title of the window
 * @param width Width of the window
 * @param height Height of the window
 */
void initWindow(Window *window, char *title, int width, int height);

/**
 * updateWindow - Updates a window
 * @param window Pointer to the current window
 * @param event SDL_Event
 */
void updateWindow(Window *window, SDL_Event event);

/**
 * setTitleWindow - Sets the title of a window
 * @param window Pointer to the current window
 * @param title Title of the window
 */
void setTitleWindow(Window *window, char *title);

/**
 * setIconWindow - Sets the icon for the window
 * @param window Pointer to the current window
 * @param filename Filename of the icon
 */
void setIconWindow(Window *window, char *filename);

/**
 * setSizeWindow - Sets the size of a window
 * @param window Pointer to the current window
 * @param width Width of the window
 * @param height Height of the window
 */
void setSizeWindow(Window *window, int width, int height);

/**
 * setPositionWindow - Sets the position on the screen of a window
 * @param window Pointer to the current window
 * @param x X-Coordinate of the window
 * @param y Y-Coordinate of the window
 */
void setPositionWindow(Window *window, int x, int y);

/**
 * setInputFocusWindow - Sets the input focus on a window
 * @param window Pointer to the current window
 */
void setInputFocusWindow(Window *window);

/**
 * grabCursorWindow - Keeps the mouse cursor inside the bounds of a window
 * @param window Pointer to the current window
 */
void grabCursorWindow(Window *window);

/**
 * freeCursorWindow - Frees the mouse cursor from the bounds of a window
 * @param window Pointer to the current window
 */
void freeCursorWindow(Window *window);

/**
 * setFullscreenWindow - Sets a window in fullscreen mode
 * @param window Pointer to the current window
 * @param fullscreen Boolean
 */
void setFullscreenWindow(Window *window, bool fullscreen);

/**
 * setResizableWindow - Sets the user-resizable state of a window
 * @param window Pointer to the current window
 * @param resizable Boolean
 */
void setResizableWindow(Window *window, bool resizable);

/**
 * showWindow - Shows a window
 * @param window Pointer to the current window
 */
void showWindow(Window * window);

/**
 * hideWindow - Hides a window
 * @param window Pointer to the current window
 */
void hideWindow(Window * window);

#endif