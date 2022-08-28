

#ifndef GAME_SOUND_H
#define GAME_SOUND_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <string>

class Sound{
public:
    explicit Sound(std::string wav_file);
    ~Sound();
    Mix_Chunk* chunk;
};

#endif //GAME_SOUND_H
