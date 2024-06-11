#ifndef WINDOW_H
#define WINDOW_H
/**
 * @file window.h
 * concernant la fenetre
 */
#include <SDL2/SDL.h>
#include <stdbool.h>

typedef struct WINDOW_STRUCT {
    SDL_Window *handle;
    SDL_Surface *surface;

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
 * initWindow- initialise une fenetre
 * @param window -
 * @param title - titre de la fenetre
 * @param width - largeur de la fenetre
 * @param height - hauteur de la fenetre
 */
void initWindow(Window *window, char *title, int width, int height);

/**
 * updateWindow-met à jour la fenetre
 * @param window - nom de la fenetre
 * @param event - evenement à effectuer sur la fenetre
 */
void updateWindow(Window *window, SDL_Event event);

/**
 * setTitleWindow- definit le titre de la fenetre
 * @param window - nom de la fenetre
 * @param title - titre de la fenetre
 */
void setTitleWindow(Window *window, char *title);

/**
 * setSizeWindow-definit la taille de la fenetre
 * @param window-nom de la fenetre
 * @param width-largeur de la fenetre
 * @param height-hauteur de la fenetre
 */
void setSizeWindow(Window *window, int width, int height);

/**
 * setPositionWindow-definit la position de la fenetre
 * @param window - nom de la fenetre
 * @param x - position en x de la fenetre
 * @param y - position en y de la fenetre
 */
void setPositionWindow(Window *window, int x, int y);

/**
 *grabCursorWindow-
 * @param window
 */
void grabCursorWindow(Window *window);

/**
 *freeCursorWindow-
 * @param window
 */
void freeCursorWindow(Window *window);

/**
 *setFullscreenWindow-
 * @param window
 * @param fullscreen
 */
void setFullscreenWindow(Window *window, bool fullscreen);

/**
 *setResizableWindow-
 * @param window
 * @param resizable
 */
void setResizableWindow(Window *window, bool resizable);

/**
 * showWindow - affiche la fenetre
 * @param window - nom de la fenetre
 */
void showWindow(Window * window);

/**
 * hideWindow- cache la fenetre
 * @param window - nom de la fenetre
 */
void hideWindow(Window * window);

#endif
