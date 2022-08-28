
#ifndef GAME_AUDIO_H
#define GAME_AUDIO_H

#include "Sound.h"
//include sdl and sdl_mixer
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

class Audio{
public:
    Audio();
    ~Audio();

    static void play(Sound *sound);
    static void stopAll();

    Mix_Music *music{};
    Mix_Chunk *sound{};
};

#endif //GAME_AUDIO_H
