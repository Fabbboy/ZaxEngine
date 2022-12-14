#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>
#include "includes/Entity.h"


Entity::Entity(Vector2f pos, std::vector<SDL_Texture*> p_tex)
        :x(pos.x), y(pos.y), tex(p_tex)
{
    currentFrame.x = 0;
    currentFrame.y = 0;
    SDL_QueryTexture(p_tex.at(0), NULL, NULL, &currentFrame.w, &currentFrame.h);
    for (int i = 0; i < getSize(); i++)
    {
        animOffsetsX.push_back(0);
        animOffsetsY.push_back(0);
    }
}

Entity::Entity(Vector2f pos, SDL_Texture* p_tex)
        :x(pos.x), y(pos.y)
{
    tex.push_back(p_tex);
    currentFrame.x = 0;
    currentFrame.y = 0;
    SDL_QueryTexture(p_tex, NULL, NULL, &currentFrame.w, &currentFrame.h);
    for (int i = 0; i < getSize(); i++)
    {
        animOffsetsX.push_back(0);
        animOffsetsY.push_back(0);
    }
}

float Entity::getX()
{
    return x;
}

float Entity::getY()
{
    return y;
}

int Entity::getWidth()
{
    return currentFrame.w;
}

int Entity::getHeight()
{
    return currentFrame.h;
}

int Entity::getSize()
{
    return tex.size();
}

void Entity::setX(float p_x)
{
    x = p_x;
}

void Entity::setY(float p_y)
{
    y = p_y;
}

float Entity::getAnimOffsetX(int p_index)
{
    return animOffsetsX.at(p_index);
}

float Entity::getAnimOffsetY(int p_index)
{
    return animOffsetsY.at(p_index);
}

void Entity::setAnimOffsetX(int p_index, int p_value)
{
    animOffsetsX[p_index] = p_value;
}

void Entity::setAnimOffsetY(int p_index, int p_value)
{
    animOffsetsY[p_index] = p_value;
}

SDL_Texture* Entity::getTex(int p_index)
{
    return tex.at(p_index);
}

SDL_Rect Entity::getCurrentFrame()
{
    return currentFrame;
}

void Entity::setTex(SDL_Texture* p_tex)
{
    tex[0] = p_tex;
}

void Entity::setHeight(float p_x) {
    currentFrame.h = p_x;
}

void Entity::setWidth(float p_y) {
    currentFrame.w = p_y;

}


bool Entity::checkCollision(Entity &p_entity) {
    if (getX() + getWidth() > p_entity.getX() && getX() < p_entity.getX() + p_entity.getWidth() && getY() + getHeight() > p_entity.getY() && getY() < p_entity.getY() + p_entity.getHeight()) {
        return true;
    }
    return false;
}

void Entity::destroy() {
    for (int i = 0; i < getSize(); i++) {
        SDL_DestroyTexture(tex.at(i));
    }
}

bool Entity::isHover(Input input) {
    Vector2f currentEntityPosition = Vector2f(getX(), getY());
    int* mousePosition = input.getMousePosition();
    Vector2f mousePositionVector = Vector2f(mousePosition[0], mousePosition[1]);
    if (mousePositionVector.x > currentEntityPosition.x && mousePositionVector.x < currentEntityPosition.x + getWidth() && mousePositionVector.y > currentEntityPosition.y && mousePositionVector.y < currentEntityPosition.y + getHeight()) {
        return true;
    }
    return false;
}

bool Entity::isClicked(Input input, Mouse key) {
    if (input.isMouseDown(key) && isHover(input)) {
        return true;
    }
    return false;
}
