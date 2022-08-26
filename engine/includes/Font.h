

#ifndef GAME_FONT_H
#define GAME_FONT_H


#include <SDL_render.h>
#include <SDL2/SDL_ttf.h>

class Font {

public:
    Font(SDL_Renderer *pRenderer, TTF_Font *pFont);
    ~Font();

    SDL_Renderer *renderer;
    TTF_Font *font;
};


#endif //GAME_FONT_H
