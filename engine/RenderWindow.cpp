#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>

#include "includes/RenderWindow.h"
#include "includes/Entity.h"
#include "includes/Text.h"


RenderWindow::RenderWindow()
{

}

void RenderWindow::create(const char* p_title, int p_w, int p_h)
{
    window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_w, p_h, SDL_WINDOW_SHOWN);

    if (window == NULL)
        std::cout << "Window failed to init. Error: " << SDL_GetError() << std::endl;

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SCREENHEIGHT = p_h;
    SCREENWIDTH = p_w;
}


SDL_Texture* RenderWindow::loadTexture(const char* p_filePath)
{
    SDL_Texture* texture = NULL;
    texture = IMG_LoadTexture(renderer, p_filePath);

    if (texture == NULL)
        std::cout << "Failed to load texture. Error: " << SDL_GetError() << std::endl;

    return texture;
}

void RenderWindow::clear()
{
    SDL_SetRenderDrawColor(renderer, 90, 90, 90, 255);
    SDL_RenderClear(renderer);
}

void RenderWindow::render(Entity& p_entity)
{

    for (int i = p_entity.getSize() - 1; i >= 0; i--)
    {
        SDL_Rect src;
        src.x = p_entity.getCurrentFrame().x;
        src.y = p_entity.getCurrentFrame().y;
        src.w = p_entity.getCurrentFrame().w;
        src.h = p_entity.getCurrentFrame().h;

        SDL_Rect dst;
        dst.x = p_entity.getX() + p_entity.getAnimOffsetX(i);
        dst.y = p_entity.getY() + p_entity.getAnimOffsetY(i);
        dst.w = p_entity.getCurrentFrame().w;
        dst.h = p_entity.getCurrentFrame().h;

        SDL_RenderCopy(renderer, p_entity.getTex(i), &src, &dst);
    }
}


void RenderWindow::render(Vector2f pos,SDL_Texture* p_tex)
{
    SDL_Rect src;
    src.x = 0;
    src.y = 0;
    SDL_QueryTexture(p_tex, NULL, NULL, &src.w, &src.h);

    SDL_Rect dst;
    dst.x = pos.x;
    dst.y = pos.y;
    dst.w = src.w;
    dst.h = src.h;

    SDL_RenderCopy(renderer, p_tex, &src, &dst);
}

void RenderWindow::render(Vector2f pos,const char* p_text, TTF_Font* font, SDL_Color textColor)
{
    SDL_Surface* surfaceMessage = TTF_RenderText_Blended( font, p_text, textColor);
    SDL_Texture* message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);

    SDL_Rect src;
    src.x = 0;
    src.y = 0;
    src.w = surfaceMessage->w;
    src.h = surfaceMessage->h;

    SDL_Rect dst;
    dst.x = pos.x;
    dst.y = pos.y;
    dst.w = src.w;
    dst.h = src.h;

    SDL_RenderCopy(renderer, message, &src, &dst);
    SDL_FreeSurface(surfaceMessage);
}

void RenderWindow::renderCenter(Vector2f pos, const char* p_text, TTF_Font* font, SDL_Color textColor)
{
    SDL_Surface* surfaceMessage = TTF_RenderText_Blended( font, p_text, textColor);
    SDL_Texture* message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);

    SDL_Rect src;
    src.x = 0;
    src.y = 0;
    src.w = surfaceMessage->w;
    src.h = surfaceMessage->h;

    SDL_Rect dst;
    dst.x = SCREENWIDTH/2 - src.w/2 + pos.x;
    dst.y = SCREENHEIGHT/2 - src.h/2 + pos.y;
    dst.w = src.w;
    dst.h = src.h;

    SDL_RenderCopy(renderer, message, &src, &dst);
    SDL_FreeSurface(surfaceMessage);
}

void RenderWindow::display()
{
    SDL_RenderPresent(renderer);
}

void RenderWindow::cleanUp()
{
    SDL_DestroyWindow(window);
}

TTF_Font *RenderWindow::loadFont(const char *p_filePath, int p_size) {
    TTF_Font *font = TTF_OpenFont(p_filePath, p_size);
    if (font == NULL)
        std::cout << "Failed to load font. Error: " << TTF_GetError() << std::endl;
    return font;
}


void RenderWindow::render(Vector2f pos, Text p_tex) {
    SDL_Rect src;
    src.x = 0;
    src.y = 0;
    SDL_QueryTexture(p_tex.getTex(), NULL, NULL, &src.w, &src.h);

    SDL_Rect dst;
    dst.x = pos.x;
    dst.y = pos.y;
    dst.w = src.w;
    dst.h = src.h;

    SDL_RenderCopy(renderer, p_tex.getTex(), &src, &dst);
}

