#include "window.h"

/**
 * initWindow- initialise une fenetre
 * @param window -
 * @param title - titre de la fenetre
 * @param width - largeur de la fenetre
 * @param height - hauteur de la fenetre
 */
void initWindow(Window *window, char *title, int width, int height) {
    window->handle = SDL_CreateWindow(title,SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,width,height,SDL_WINDOW_HIDDEN);
    window->surface = SDL_GetWindowSurface(window->handle);

    window->title = title;
    window->width = width;
    window->height = height;

    window->isClosing = false;
    window->isVisible = false;
    window->isResizable = false;
    window->isFullscreen = false;

    window->hasMouseFocus = false;
    window->hasKeyboardFocus = false;
    window->hasGrabbedCursor = false;
}

/**
 * updateWindow-met à jour la fenetre
 * @param window - nom de la fenetre
 * @param event - evenement à effectuer sur la fenetre
 */
void updateWindow(Window *window, SDL_Event event) {
    if(event.type == SDL_QUIT) {
        window->isClosing = true;
    } else if(event.type == SDL_WINDOWEVENT) {
        switch(event.window.event) {
            case SDL_WINDOWEVENT_HIDDEN:
                window->isVisible = false;
                break;
            case SDL_WINDOWEVENT_SHOWN:
                window->isVisible = true;
                break;
            case SDL_WINDOWEVENT_ENTER:
                window->hasMouseFocus = true;
                break;
            case SDL_WINDOWEVENT_LEAVE:
                window->hasMouseFocus = false;
                break;
            case SDL_WINDOWEVENT_FOCUS_GAINED:
                window->hasKeyboardFocus = true;
                break;
            case SDL_WINDOWEVENT_FOCUS_LOST:
                window->hasKeyboardFocus = false;
                break;
            case SDL_WINDOWEVENT_RESIZED:
                window->width = event.window.data1;
                window->height = event.window.data2;
                break;
        }
    }
}

/**
 * setTitleWindow- definit le titre de la fenetre
 * @param window - nom de la fenetre
 * @param title - titre de la fenetre
 */
void setTitleWindow(Window *window, char *title) {
    SDL_SetWindowTitle(window->handle, title);
    window->title = title;
}


/**
 * setSizeWindow-definit la taille de la fenetre
 * @param window-nom de la fenetre
 * @param width-largeur de la fenetre
 * @param height-hauteur de la fenetre
 */
void setSizeWindow(Window *window, int width, int height) {
    SDL_SetWindowSize(window->handle, width, height);
}


/**
 * setPositionWindow-definit la position de la fenetre
 * @param window - nom de la fenetre
 * @param x - position en x de la fenetre
 * @param y - position en y de la fenetre
 */
void setPositionWindow(Window *window, int x, int y) {
    SDL_SetWindowPosition(window->handle, x, y);
}


/**
 *grabCursorWindow-
 * @param window
 */
void grabCursorWindow(Window *window) {
    SDL_SetWindowMouseGrab(window->handle, SDL_TRUE);
    window->hasGrabbedCursor = true;
}


/**
 *freeCursorWindow-
 * @param window
 */
void freeCursorWindow(Window *window) {
    SDL_SetWindowMouseGrab(window->handle, SDL_FALSE);
    window->hasGrabbedCursor = false;
}

/**
 *setFullscreenWindow-
 * @param window
 * @param fullscreen
 */
void setFullscreenWindow(Window *window, bool fullscreen) {
    if(fullscreen) {
        SDL_SetWindowFullscreen(window->handle, SDL_WINDOW_FULLSCREEN_DESKTOP);
    } else {
        SDL_SetWindowFullscreen(window->handle, 0);
    }
    window->isFullscreen = fullscreen;
}


/**
 *setResizableWindow-
 * @param window
 * @param resizable
 */
void setResizableWindow(Window *window, bool resizable) {
    SDL_SetWindowResizable(window->handle, resizable ? SDL_TRUE : SDL_FALSE);
    window->isResizable = resizable;
}

/**
 * showWindow - affiche la fenetre
 * @param window - nom de la fenetre
 */
void showWindow(Window * window) {
    SDL_ShowWindow(window->handle);
    window->isVisible = true;
}

/**
 * hideWindow- cache la fenetre
 * @param window - nom de la fenetre
 */
void hideWindow(Window * window) {
    SDL_HideWindow(window->handle);
    window->isVisible = false;
}
