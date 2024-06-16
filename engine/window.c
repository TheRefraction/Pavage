#include "window.h"

void initWindow(Window *window, char *title, int width, int height) {
    window->handle = SDL_CreateWindow(title,SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,width,height,SDL_WINDOW_HIDDEN);
    window->surface = SDL_GetWindowSurface(window->handle);
    window->icon = NULL;

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

void updateWindow(Window *window, SDL_Event event) {
    if(event.type == SDL_QUIT) {
        window->isClosing = true;
    } else if(event.type == SDL_WINDOWEVENT) {
        switch(event.window.event) {
            case SDL_WINDOWEVENT_HIDDEN: {
                window->isVisible = false;
                break;
            }
            case SDL_WINDOWEVENT_SHOWN: {
                window->isVisible = true;
                break;
            }
            case SDL_WINDOWEVENT_ENTER: {
                window->hasMouseFocus = true;
                break;
            }
            case SDL_WINDOWEVENT_LEAVE: {
                window->hasMouseFocus = false;
                break;
            }
            case SDL_WINDOWEVENT_FOCUS_GAINED: {
                window->hasKeyboardFocus = true;
                break;
            }
            case SDL_WINDOWEVENT_FOCUS_LOST: {
                window->hasKeyboardFocus = false;
                break;
            }
            case SDL_WINDOWEVENT_RESIZED: {
                window->width = event.window.data1;
                window->height = event.window.data2;
                break;
            }
        }
    }
}

void setTitleWindow(Window *window, char *title) {
    SDL_SetWindowTitle(window->handle, title);
    window->title = title;
}

void setIconWindow(Window *window, char *filename) {
    window->icon = SDL_LoadBMP(filename);
    if(window->icon) {
        SDL_SetWindowIcon(window->handle, window->icon);
    } else {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failure to load surface:\n%s", SDL_GetError());
    }
}

void setSizeWindow(Window *window, int width, int height) {
    SDL_SetWindowSize(window->handle, width, height);
}

void setPositionWindow(Window *window, int x, int y) {
    SDL_SetWindowPosition(window->handle, x, y);
}

void setInputFocusWindow(Window *window) {
    SDL_SetWindowInputFocus(window->handle);
}

void grabCursorWindow(Window *window) {
    SDL_SetWindowMouseGrab(window->handle, SDL_TRUE);
    window->hasGrabbedCursor = true;
}

void freeCursorWindow(Window *window) {
    SDL_SetWindowMouseGrab(window->handle, SDL_FALSE);
    window->hasGrabbedCursor = false;
}

void setFullscreenWindow(Window *window, bool fullscreen) {
    if(fullscreen) {
        SDL_SetWindowFullscreen(window->handle, SDL_WINDOW_FULLSCREEN_DESKTOP);
    } else {
        SDL_SetWindowFullscreen(window->handle, 0);
    }
    window->isFullscreen = fullscreen;
}

void setResizableWindow(Window *window, bool resizable) {
    SDL_SetWindowResizable(window->handle, resizable ? SDL_TRUE : SDL_FALSE);
    window->isResizable = resizable;
}

void showWindow(Window * window) {
    SDL_ShowWindow(window->handle);
    window->isVisible = true;
}

void hideWindow(Window * window) {
    SDL_HideWindow(window->handle);
    window->isVisible = false;
}