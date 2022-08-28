#include "../includes/UI/Text.h"
#include "../includes/Vector.h"

Text::Text(Vector2f position,SDL_Renderer *p_renderer, const char *p_text, TTF_Font *p_font, SDL_Color p_color) {
    SDL_Surface *surfaceMessage = TTF_RenderText_Blended(p_font, p_text, p_color);
    tex = SDL_CreateTextureFromSurface(p_renderer, surfaceMessage);
    SDL_FreeSurface(surfaceMessage);
    pos = position;
}

SDL_Texture *Text::getTex() {
    return tex;
}

