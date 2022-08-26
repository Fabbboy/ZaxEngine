//game with sdl

#include "engine/includes/RenderWindow.h"
#include "engine/includes/utils.h"
#include "engine/includes/Input.h"
#include "engine/includes/Texture.h"
#include "engine/includes/SimpleShapes.h"
#include <iostream>



RenderWindow window;
Input keyboard;
int main()
{
    init();
    window.create("Game", 1000, 600);
    Texture test(window.renderer, window.loadTexture("/Users/Fabboy/CLionProject/game/assets/test.png"), SDL_Rect(),
                 SDL_Rect());
    //Font font(window.renderer,window.loadFont("/Users/Fabboy/CLionProject/game/assets/font.ttf"));

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
        window.renderCenter(0,0,"Hello World",window.loadFont("/Users/Fabboy/CLionProject/game/assets/font.ttf", 20),{255,255,255});

        window.display();
    }

    return 0;
}
