

#ifndef GAME_TEXTURE_H
#define GAME_TEXTURE_H

#include <SDL_render.h>
#include <SDL2/SDL_ttf.h>

class Texture {
public:
    Texture(SDL_Texture *texture, const char *string, TTF_Font *pFont, SDL_Color color);
    ~Texture();
    SDL_Texture* getTex();

    SDL_Texture* texture;
};


#endif //GAME_TEXTURE_H
