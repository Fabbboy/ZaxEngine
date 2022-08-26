
#ifndef GAME_SYSTEM_H
#define GAME_SYSTEM_H

class Debug {
public:
    Debug();
    ~Debug();

    void log(const char* p_text, ...);
    void Warning(const char* p_text, ...);
    void Error(const char* p_text, ...);
    void Fatal(const char* p_text, ...);
    void startTimer();
    void endTimer() const;

    int startTime;
};

#endif //GAME_SYSTEM_H
