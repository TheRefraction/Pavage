#ifndef WINDOW_H
#define WINDOW_H

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

void initWindow(Window *window, char *title, int width, int height);
void updateWindow(Window *window, SDL_Event event);

void setTitleWindow(Window *window, char *title);
void setSizeWindow(Window *window, int width, int height);
void setPositionWindow(Window *window, int x, int y);

void grabCursorWindow(Window *window);
void freeCursorWindow(Window *window);

void setFullscreenWindow(Window *window, bool fullscreen);
void setResizableWindow(Window *window, bool resizable);

void showWindow(Window * window);
void hideWindow(Window * window);

#endif
