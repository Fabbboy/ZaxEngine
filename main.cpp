//game with sdl

#include "engine/includes/RenderWindow.h"
#include "engine/includes/utils.h"
#include "engine/includes/Input.h"
#include "engine/includes/Texture.h"
#include "engine/includes/Font.h"
#include "engine/includes/UI/Colors.h"
#include "engine/includes/Sound.h"
#include "engine/includes/Audio.h"
#include "engine/includes/System.h"
#include <iostream>



RenderWindow window;
Input *input;
Audio audio;
Debug debug;
int main()
{
    init();
    window.create("Game", 1000, 600);
    Texture test(window.loadTexture("/Users/Fabboy/CLionProjects/ZaxEngine/assets/Ape.png"), nullptr, nullptr,
                 SDL_Color());
    Font fonte(window.loadFont("/Users/Fabboy/CLionProjects/ZaxEngine/assets/font.ttf", 20));
    Entity background(Vector2f(0,0), test.texture);
    Sound sound("/Users/Fabboy/CLionProjects/ZaxEngine/assets/spacegun.wav");
    //Vector2f position, Vector2f size, SDL_Renderer* p_renderer, const char* p_text, TTF_Font* p_font, Texture Background,SDL_Color p_color
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
        //render entity
        window.render(background);
        //render text
        window.render(Vector2f(0,0), "Hello World", fonte.font, White);

        window.display();
    }

    return 0;
}
