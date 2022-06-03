//
//  main.cpp
//
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>

#include <iostream>
#include <vector>
#include <ctime>
#include <cmath>
#include <stdlib.h>

#include "Renderer.h"
#include "drunkMan.h"
#include "Component.h"

//helper func


const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 800;
const int ALIVE = 0;
const Uint8 *keyState;

Renderer window;

TTF_Font* font32;
//TTF_Font* font32_outline;
TTF_Font* font24;
TTF_Font* font16;

SDL_Color white = { 255, 255, 255 };
SDL_Color black = { 0, 0, 0 };

std::vector<SDL_Texture*> playerTex;
//std::vector<SDL_Texture*> bgTex;
bool gameRunning = true;
bool playedDeathSFX = false;
bool menu = true;

bool init()
{
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    IMG_Init(IMG_INIT_PNG);
    TTF_Init();

    window.create("Drunk Walker 1.0", SCREEN_WIDTH, SCREEN_HEIGHT);
    
    srand((unsigned)time(0));
    playerTex.push_back(window.loadTexture("/Users/user/Downloads/assets/man-1.png"));
    font32 = TTF_OpenFont("/Users/user/Downloads/demo/demo/cocogoose.ttf", 32);
    //font32_outline = TTF_OpenFont("demo/cocogoose.ttf", 32);
    font24 = TTF_OpenFont("/Users/user/Downloads/demo/demo/cocogoose.ttf", 24);
    font16 = TTF_OpenFont("/Users/user/Downloads/demo/demo/cocogoose.ttf", 16);
    //TTF_SetFontOutline(font32_outline, 3);
    
    return true;
}

bool load = init();

DrunkMan player(0, 0, playerTex);

void reset()
{
    player.reset();
}

void gameLoop()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type) {
            case SDL_QUIT:
            {
                gameRunning = false;
                break;
            }
            case SDL_MOUSEBUTTONDOWN:
            {
                if (event.button.button == SDL_BUTTON_LEFT && player.isDead() == ALIVE)
                {
                    if (player.isDead() != ALIVE){
                        reset();
                        playedDeathSFX = false;
                    }
                }
            }
        
        }
    }
    if (menu)
    {
        if (SDL_GetTicks() < 2500)
        {
            window.clear();
            window.renderCenter(0, sin(SDL_GetTicks()/100) * 2 - 4, "Drunk Man", font24, white);
            window.display();
        }
        else
        {
            window.clear();
            
            //window.render(SCREEN_WIDTH/2 - 234, SCREEN_HEIGHT/2 - 94 - 30);
            window.renderCenter(0, 90 + sin(SDL_GetTicks()/100) * 2, "Click to start", font24, white);
            /*
            for (int i = 0; i < ground.getLength(); i++)
            {
                window.render(ground.getTile(i));
            }
             */
            window.display();
        }
    }
    else
    {
        if (player.isDead() == ALIVE)
        {
            player.update();
        }
        window.clear();
        //window.render(62, 20, player.getScore(), font32_outline, black);
        window.render(65, 23, player.getScore(), font32, white);
        if (player.isDead() != ALIVE)
        {
            window.renderCenter(0, 12, "Click to retry.", font16, white);
            window.display();
        }
    }
}

//main function
int main(int argc, char* args[])
{
    while (gameRunning)
    {
        gameLoop();
        SDL_Delay(16);
    }
    
    window.cleanUp();
    TTF_CloseFont(font32);
    //TTF_CloseFont(font32_outline);
    TTF_CloseFont(font24);
    TTF_CloseFont(font16);
    TTF_Quit();
    SDL_Quit();
    
    return 0;
}


//
//  Created by Mac Air on 5/31/22.
//  Copyright © 2022 AL. All rights reserved.
//
