//game with sdl

#include "engine/includes/RenderWindow.h"
#include "engine/includes/utils.h"
#include "engine/includes/Keyboard.h"
#include "engine/includes/Texture.h"
#include <iostream>



RenderWindow window;
Input keyboard;
int main()
{
    init();
    window.create("Game", 800, 600);
    Texture test(window.renderer,window.loadTexture("/Users/Fabboy/CLionProject/game/assets/test.png"));
    Entity background(0, 0, test.getTex());

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

        window.render(background);
        window.renderCenter(0, 0, "H", window.loadFont("/Users/Fabboy/CLionProject/game/assets/font.ttf", 32), {255, 255, 255});
        background.setHeight(600);
        background.setWidth(800);

        //use override function "onUpdate" that will be called every frame that is defined in window class
        window.display();
    }

    return 0;
}
