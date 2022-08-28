
#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#include <SDL_timer.h>
#include "includes/System.h"
#include <filesystem>
#include <SDL2/SDL.h>

//namespace filesystem as fs
using namespace std::__fs::filesystem;

Debug::Debug() {
    //create dir DebugLog if not exists
    if (!exists("DebugLog")) {
        create_directory("DebugLog");
    }
}

void Debug::log(const char *p_text, ...) {
    va_list args;
    va_start(args, p_text);
    vprintf(p_text, args);
    va_end(args);
}

void Debug::Warning(const char *p_text, ...) {
    printf("\033[1;33m");
    va_list args;
    va_start(args, p_text);
    vprintf(p_text, args);
    va_end(args);
    printf("\033[0m");
}

void Debug::Error(const char *p_text, ...) {
    printf("\033[1;31m");
    va_list args;
    va_start(args, p_text);
    vprintf(p_text, args);
    va_end(args);
    printf("\033[0m");
}

void Debug::Fatal(const char *p_text, ...) {
    printf("\033[1;31m");
    va_list args;
    va_start(args, p_text);
    vprintf(p_text, args);
    va_end(args);
    printf("\033[0m");
    exit(1);
}

void Debug::startTimer() {
    startTime = SDL_GetTicks();
}

void Debug::endTimer() const {
    int endTime = SDL_GetTicks();
    printf("\033[1;32m");
    printf("Time taken: %d ms\n", endTime - startTime);
    printf("\033[0m");
}

void Debug::takeScreenshot(RenderWindow Window) {
    SDL_Surface *screenshot = SDL_CreateRGBSurface(0, Window.SCREENWIDTH, Window.SCREENHEIGHT, 32, 0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);
    SDL_RenderReadPixels(Window.renderer, nullptr, SDL_PIXELFORMAT_ARGB8888, screenshot->pixels, screenshot->pitch);
    long timestamp = SDL_GetTicks();
    //store screen at DebugLog/Screenshot-timestamp.bmp
    SDL_SaveBMP(screenshot, ("DebugLog/Screenshot-" + std::to_string(timestamp) + ".bmp").c_str());
    SDL_FreeSurface(screenshot);
}


Debug::~Debug() = default;