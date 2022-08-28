

#ifndef GAME_FONT_H
#define GAME_FONT_H


#include <SDL_render.h>
#include <SDL2/SDL_ttf.h>

class Font {

public:
    Font(TTF_Font *pFont);
    ~Font();
    TTF_Font *font;
};


#endif //GAME_FONT_H
