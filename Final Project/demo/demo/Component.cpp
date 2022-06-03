//
//  component.cpp
//  demo
//
//  Created by Mac Air on 6/2/22.
//  Copyright © 2022 AL. All rights reserved.
//

#include "Component.h"
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <vector>


Component::Component(float p_x, float p_y, std::vector<SDL_Texture*> p_tex)
:x(p_x), y(p_y), tex(p_tex)
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

Component::Component(float p_x, float p_y, SDL_Texture* p_tex)
:x(p_x), y(p_y)
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

float Component::getX()
{
    return x;
}

float Component::getY()
{
    return y;
}

int Component::getWidth()
{
    return currentFrame.w;
}

int Component::getHeight()
{
    return currentFrame.h;
}

int Component::getSize()
{
    return tex.size();
}

void Component::setX(float p_x)
{
    x = p_x;
}

void Component::setY(float p_y)
{
    y = p_y;
}

float Component::getAnimOffsetX(int p_index)
{
    return animOffsetsX.at(p_index);
}

float Component::getAnimOffsetY(int p_index)
{
    return animOffsetsY.at(p_index);
}

void Component::setAnimOffsetX(int p_index, int p_value)
{
    animOffsetsX[p_index] = p_value;
}

void Component::setAnimOffsetY(int p_index, int p_value)
{
    animOffsetsY[p_index] = p_value;
}

SDL_Texture* Component::getTex(int p_index)
{
    return tex.at(p_index);
}

SDL_Rect Component::getCurrentFrame()
{
    return currentFrame;
}

void Component::setTex(SDL_Texture* p_tex)
{
    tex[0] = p_tex;
}

