
#ifndef GAME_RENDERWINDOW_H
#define GAME_RENDERWINDOW_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "entity.h"

class RenderWindow
{
public:
    SDL_Window* window;
    SDL_Renderer* renderer;
    int SCREENWIDTH;
    int SCREENHEIGHT;


    RenderWindow();
    void create(const char* p_title, int p_w, int p_h);
    SDL_Texture* loadTexture(const char* p_filePath);
    void clear();
    void render(Entity& p_entity);
    void render(float p_x, float p_y, SDL_Texture* p_tex);
    void render(SDL_Texture* p_tex);
    void render(int x, int y, Texture p_tex);
    void render(float p_x, float p_y, const char* p_text, TTF_Font* font, SDL_Color textColor);
    void renderCenter(float p_x, float p_y, const char* p_text, TTF_Font* font, SDL_Color textColor);

    void display();
    void cleanUp();

    TTF_Font* loadFont(const char* p_filePath, int p_size);
    //override function "onUpdate" that will be called every frame
};
#endif //GAME_RENDERWINDOW_H
