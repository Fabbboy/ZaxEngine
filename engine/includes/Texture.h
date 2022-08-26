

#ifndef GAME_TEXTURE_H
#define GAME_TEXTURE_H

#include <SDL_render.h>
#include <SDL2/SDL_ttf.h>

class Texture {
public:
    Texture(SDL_Renderer *p_renderer, SDL_Texture *texture, SDL_Rect rect, SDL_Rect sdlRect);
    ~Texture();
    SDL_Texture* getTex();

    SDL_Texture* texture;
};


#endif //GAME_TEXTURE_H
