

#ifndef GAME_TEXT_H
#define GAME_TEXT_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string>
#include "../Input.h"
#include "../Vector.h"

class Text{
public:
    std::string text;
    Text(Vector2f position,SDL_Renderer* p_renderer, const char* p_text, TTF_Font* p_font, SDL_Color p_color);


    SDL_Texture *tex;

    SDL_Texture *getTex();

    Vector2f pos;
};
#endif //GAME_TEXT_H
