//game with sdl

#include "engine/includes/RenderWindow.h"
#include "engine/includes/utils.h"
#include "engine/includes/Input.h"
#include "engine/includes/Texture.h"
#include "engine/includes/Font.h"
#include "engine/includes/Colors.h"
#include <iostream>



RenderWindow window;
Input keyboard;
int main()
{
    init();
    window.create("Game", 1000, 600);
    Texture test(window.renderer, window.loadTexture("/Users/Fabboy/CLionProject/game/assets/test.png"), SDL_Rect(),
                 SDL_Rect());
    Font fonte(window.renderer,window.loadFont("/Users/Fabboy/CLionProject/game/assets/font.ttf", 20));
    Entity background(0, 0, window.loadTexture("/Users/Fabboy/CLionProject/game/assets/test.png"));

    bool running = true;
    while(running)
    {
        SDL_Event event;

        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
                running = false;
        }
        window.clear();
        //Vector2f position,SDL_Renderer* p_renderer, const char* p_text, TTF_Font* p_font, SDL_Color p_color
        Text text(Vector2f(100,100),window.renderer,"Hello World",fonte.font, Red);
        window.render(0,0,text);
        window.render(background);
        if(background.isClicked(keyboard, Mouse_Left))
            std::cout << "clicked" << std::endl;


        window.display();
    }

    return 0;
}
