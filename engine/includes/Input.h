

#ifndef GAME_INPUT_H
#define GAME_INPUT_H

#include <SDL_events.h>
#include "Vector.h"


enum Keyboard{
    Key_None = SDL_SCANCODE_UNKNOWN,
    Key_A = SDL_SCANCODE_A,
    Key_B = SDL_SCANCODE_B,
    Key_C = SDL_SCANCODE_C,
    Key_D = SDL_SCANCODE_D,
    Key_E = SDL_SCANCODE_E,
    Key_F = SDL_SCANCODE_F,
    Key_G = SDL_SCANCODE_G,
    Key_H = SDL_SCANCODE_H,
    Key_I = SDL_SCANCODE_I,
    Key_J = SDL_SCANCODE_J,
    Key_K = SDL_SCANCODE_K,
    Key_L = SDL_SCANCODE_L,
    Key_M = SDL_SCANCODE_M,
    Key_N = SDL_SCANCODE_N,
    Key_O = SDL_SCANCODE_O,
    Key_P = SDL_SCANCODE_P,
    Key_Q = SDL_SCANCODE_Q,
    Key_R = SDL_SCANCODE_R,
    Key_S = SDL_SCANCODE_S,
    Key_T = SDL_SCANCODE_T,
    Key_U = SDL_SCANCODE_U,
    Key_V = SDL_SCANCODE_V,
    Key_W = SDL_SCANCODE_W,
    Key_X = SDL_SCANCODE_X,
    Key_Y = SDL_SCANCODE_Y,
    Key_Z = SDL_SCANCODE_Z,
    Key_0 = SDL_SCANCODE_0,
    Key_1 = SDL_SCANCODE_1,
    Key_2 = SDL_SCANCODE_2,
    Key_3 = SDL_SCANCODE_3,
    Key_4 = SDL_SCANCODE_4,
    Key_5 = SDL_SCANCODE_5,
    Key_6 = SDL_SCANCODE_6,
    Key_7 = SDL_SCANCODE_7,
    Key_8 = SDL_SCANCODE_8,
    Key_9 = SDL_SCANCODE_9,
    Key_F1 = SDL_SCANCODE_F1,
    Key_F2 = SDL_SCANCODE_F2,
    Key_F3 = SDL_SCANCODE_F3,
    Key_F4 = SDL_SCANCODE_F4,
    Key_F5 = SDL_SCANCODE_F5,
    Key_F6 = SDL_SCANCODE_F6,
    Key_F7 = SDL_SCANCODE_F7,
    Key_F8 = SDL_SCANCODE_F8,
    Key_F9 = SDL_SCANCODE_F9,
    Key_F10 = SDL_SCANCODE_F10,
    Key_F11 = SDL_SCANCODE_F11,
    Key_F12 = SDL_SCANCODE_F12,
    Key_lctrl = SDL_SCANCODE_LCTRL,
    Key_lshift = SDL_SCANCODE_LSHIFT,
    Key_lalt = SDL_SCANCODE_LALT,
    Key_lgui = SDL_SCANCODE_LGUI,
    Key_rctrl = SDL_SCANCODE_RCTRL,
    Key_rshift = SDL_SCANCODE_RSHIFT,
    Key_ralt = SDL_SCANCODE_RALT,
    Key_rgui = SDL_SCANCODE_RGUI,
    Key_escape = SDL_SCANCODE_ESCAPE,
    Key_enter = SDL_SCANCODE_RETURN,
    Key_tab = SDL_SCANCODE_TAB,
    Key_backspace = SDL_SCANCODE_BACKSPACE,
    Key_insert = SDL_SCANCODE_INSERT,
    Key_delete = SDL_SCANCODE_DELETE,
    Key_right = SDL_SCANCODE_RIGHT,
    Key_left = SDL_SCANCODE_LEFT,
    Key_down = SDL_SCANCODE_DOWN,
    Key_up = SDL_SCANCODE_UP,
    Key_pageup = SDL_SCANCODE_PAGEUP,
    Key_pagedown = SDL_SCANCODE_PAGEDOWN,
    Key_home = SDL_SCANCODE_HOME,
    Key_end = SDL_SCANCODE_END,
    Key_capslock = SDL_SCANCODE_CAPSLOCK,
    Key_comma = SDL_SCANCODE_COMMA,
    Key_period = SDL_SCANCODE_PERIOD,
    Key_slash = SDL_SCANCODE_SLASH,
    Key_backslash = SDL_SCANCODE_BACKSLASH,
    Key_minus = SDL_SCANCODE_MINUS,
    Key_equals = SDL_SCANCODE_EQUALS,
    Key_leftbracket = SDL_SCANCODE_LEFTBRACKET,
    Key_rightbracket = SDL_SCANCODE_RIGHTBRACKET,
    Key_quote = SDL_SCANCODE_APOSTROPHE,
    Key_tilde = SDL_SCANCODE_GRAVE,
    Key_space = SDL_SCANCODE_SPACE,
};

enum Mouse{
    Mouse_None = SDL_BUTTON_LEFT,
    Mouse_Left = SDL_BUTTON_LEFT,
    Mouse_Right = SDL_BUTTON_RIGHT,
    Mouse_Middle = SDL_BUTTON_MIDDLE,
    Mouse_X1 = SDL_BUTTON_X1,
    Mouse_X2 = SDL_BUTTON_X2,
};

class Input{
private:
    SDL_Event event;
    bool keys[323];
public:
    Input();
    void update();
    bool isKeyDown(Keyboard key);
    bool isKeyUp(Keyboard key);
    bool isAnyKeyDown();
    SDL_Scancode getPressedKey();


    float getMouseX();
    float getMouseY();
    bool isMouseDown(Mouse button);
    int* getMouseClick(Mouse button);
    bool isMouseUp(Mouse button);
    bool isMouseDownInRange(float x, float y, float w, float h, Mouse button);
    SDL_Scancode getPressedMouse();

    int * getMousePosition();

};

#endif //GAME_INPUT_H
