#include "includes/Audio.h"


Audio::Audio() {
    // Initialize SDL_mixer
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
        exit(1);
    }

}

void Audio::play(Sound *sound) {
    Mix_PlayChannel(-1, sound->chunk, 0);
}

Audio::~Audio() {
    // Close the mixer
    Mix_Quit();
}

void Audio::stopAll() {
    Mix_HaltChannel(-1);
}
