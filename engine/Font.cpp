
#include "includes/Font.h"

Font::Font(TTF_Font *pFont) {
    font = pFont;
}

Font::~Font() {
    TTF_CloseFont(font);
}
