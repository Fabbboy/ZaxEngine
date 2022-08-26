
#ifndef GAME_ENTITY_H
#define GAME_ENTITY_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>
#include "Texture.h"

class Entity
{
private:
    float x, y;
    std::vector<float> animOffsetsX;
    std::vector<float> animOffsetsY;
    SDL_Rect currentFrame;
    std::vector<SDL_Texture*> tex;
public:
    Entity(float p_x, float p_y, std::vector<SDL_Texture*> p_tex);
    Entity(float p_x, float p_y, SDL_Texture* p_tex);
    Entity(float p_x, float p_y, Texture p_tex);
    void init();
    float getX();
    float getY();
    int getWidth();
    int getHeight();
    int getSize();
    void setX(float p_x);
    void setY(float p_y);
    void setHeight(float p_x);
    void setWidth(float p_y);
    float getAnimOffsetX(int p_index);
    float getAnimOffsetY(int p_index);
    void setAnimOffsetX(int p_index, int p_value);
    void setAnimOffsetY(int p_index, int p_value);
    SDL_Texture* getTex(int p_index);
    SDL_Rect getCurrentFrame();
    void setTex(SDL_Texture* p_tex);
    bool checkCollision(Entity& p_entity);
    void destroy();
};
#endif //GAME_ENTITY_H
