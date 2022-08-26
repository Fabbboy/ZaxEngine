

#ifndef GAME_TEXTURE_H
#define GAME_TEXTURE_H

#include <SDL_render.h>

class Texture {
public:
    Texture(SDL_Renderer* p_renderer, SDL_Texture* texture);
    ~Texture();
    SDL_Texture* getTex();

    SDL_Texture* texture;
};


#endif //GAME_TEXTURE_H
