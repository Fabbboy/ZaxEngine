#include "includes/Sound.h"
Sound::Sound(std::string wav_file) {
    chunk = Mix_LoadWAV(wav_file.c_str());
}

Sound::~Sound() {
    Mix_FreeChunk(chunk);
}
