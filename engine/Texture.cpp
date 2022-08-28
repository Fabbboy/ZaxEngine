
#include <SDL2/SDL_image.h>
#include "includes/Texture.h"

Texture::Texture(SDL_Texture *texture, const char *string, TTF_Font *pFont, SDL_Color color) {
    this->texture = texture;
}

Texture::~Texture() {
    SDL_DestroyTexture(texture);
}

SDL_Texture *Texture::getTex() {
    return texture;
}
