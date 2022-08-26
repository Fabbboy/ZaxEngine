
#include "includes/Input.h"



void Input::update() {
    SDL_PumpEvents();
    const Uint8* state = SDL_GetKeyboardState(NULL);
    for (int i = 0; i < 323; i++) {
        if (state[i]) {
            keys[i] = true;
        } else {
            keys[i] = false;
        }
    }
}

bool Input::isKeyDown(Keyboard key) {
    if(SDL_GetKeyboardState(NULL)[key]) {
        return true;
    } else {
        return false;
    }
}

bool Input::isKeyUp(Keyboard key) {
    if(!SDL_GetKeyboardState(NULL)[key]) {
        return true;
    } else {
        return false;
    }
}

bool Input::isAnyKeyDown() {
    for (int i = 0; i < 323; i++) {
        if (keys[i]) {
            return true;
        }
    }
    return false;
}

SDL_Scancode Input::getPressedKey() {
    for (int i = 0; i < 323; i++) {
        if (keys[i]) {
            return SDL_Scancode(i);
        }
    }
    return SDL_Scancode(0);
}

Input::Input() {
    for (int i = 0; i < 323; i++) {
        keys[i] = false;
    }
}

bool Input::isMouseDown(Mouse button) {
    if(SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(button)) {
        return true;
    } else {
        return false;
    }
}

bool Input::isMouseUp(Mouse button) {
    if(!(SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(button))) {
        return true;
    } else {
        return false;
    }
}

float Input::getMouseX() {
    int x;
    SDL_GetMouseState(&x, NULL);
    return x;
}

float Input::getMouseY() {
    int y;
    SDL_GetMouseState(NULL, &y);
    return y;
}


SDL_Scancode Input::getPressedMouse() {
    for (int i = 0; i < 323; i++) {
        if (keys[i]) {
            return SDL_Scancode(i);
        }
    }
    return SDL_Scancode(0);
}

bool Input::isMouseDownInRange(float x, float y, float w, float h, Mouse button) {
    //check if mous was clicked in a rectangle
    if(SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(button) && getMouseX() > x && getMouseX() < x + w && getMouseY() > y && getMouseY() < y + h) {
        return true;
    } else {
        return false;
    }
}

int *Input::getMousePosition() {
    int *mousePosition = new int[2];
    SDL_GetMouseState(&mousePosition[0], &mousePosition[1]);
    return mousePosition;
}

