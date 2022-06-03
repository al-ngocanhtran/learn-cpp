//
//  drunkMan.cpp
//  demo
//
//  Created by Mac Air on 6/2/22.
//  Copyright © 2022 AL. All rights reserved.
//

#include "drunkMan.h"
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <cmath>
#include <vector>
#include <string>


const float GRAVITY = 0.09f;
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 800;
const int ALIVE = 0;

DrunkMan::DrunkMan(float p_x, float p_y, std::vector<SDL_Texture*> p_tex)
: Component{ p_x, p_y, p_tex}
{
    setX(SCREEN_WIDTH/2 - getWidth()/2);
    setY(SCREEN_HEIGHT - getHeight() - 64);
};

float DrunkMan::distanceFromCursor()
{
    int mouseX = 0;
    int mouseY = 0;
    SDL_GetMouseState(&mouseX, &mouseY);
    
    return sqrt(pow((getX() + getWidth()/2) - mouseX, 2) + pow((getY() + getHeight()/2) - mouseY, 2));
}


void DrunkMan::update()
{
    timer++;
    score = timer/50;
    
    setX(getX() - 1); //autoscroll
    int mouseX = 0;
    int mouseY = 0;
    SDL_GetMouseState(&mouseX, &mouseY);
    
    //move();
    setAnimOffsetY(3, 0);
    setAnimOffsetY(4, 0);
    
    if (distanceFromCursor() < 100)
    {
        setAnimOffsetY(3, sin(SDL_GetTicks()/50) * speed - 2);
        setAnimOffsetY(4, -sin(SDL_GetTicks()/50) * speed - 2 );
        if (mouseX < getX())
        {
            speed = 1/distanceFromCursor() * 100;
        }
        else if (mouseX > getX() + getWidth())
        {
            speed = 1/distanceFromCursor() * -100;
        }
        else
        {
            speed = 0;
            /*
            if (mouseY > getY() && mouseY < getY() + getHeight())
            {
                //kill player
                dead = CURSOR_DEATH;
            }
             */
        }
    }
    else
    {
        speed = 0;
    }
    setX(getX() + speed);
    
    //setY(getY() + velocityY);
}

const char* DrunkMan::getScore()
{
    std::string s = std::to_string(score);
    s = "DISTANCE: " + s;
    return s.c_str();
}

int DrunkMan::getScoreInt()
{
    return score;
}

int DrunkMan::isDead()
{
    return dead;
}

void DrunkMan::reset()
{
    setX(SCREEN_WIDTH/2 - getWidth()/2);
    setY(SCREEN_HEIGHT - getHeight() - 64);
    score = 0;
    timer = 0;
    speed = 0;
    dead = 0;
}
