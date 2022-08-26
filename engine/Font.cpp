
#include "includes/Font.h"

Font::Font(SDL_Renderer *pRenderer, TTF_Font *pFont) {
    renderer = pRenderer;
    font = pFont;
}

Font::~Font() {
    TTF_CloseFont(font);
}
