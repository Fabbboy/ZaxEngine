
#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#include <SDL_timer.h>
#include "includes/System.h"

Debug::Debug() {

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

Debug::~Debug() = default;