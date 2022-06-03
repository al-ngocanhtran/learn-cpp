//
//  renderer.cpp
//  demo
//
//  Created by Mac Air on 6/2/22.
//  Copyright © 2022 AL. All rights reserved.
//
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>
#include "Renderer.h"
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 800;


Renderer::Renderer()
{
    
}

void Renderer::create(const char* p_title, int p_w, int p_h)
{
    window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_w, p_h, SDL_WINDOW_SHOWN);
    
    if (window == NULL)
        std::cout << "Window failed to init. Error: " << SDL_GetError() << std::endl;
    
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}


SDL_Texture* Renderer::loadTexture(const char* p_filePath)
{
    SDL_Texture* texture = NULL;
    texture = IMG_LoadTexture(renderer, p_filePath);
    
    if (texture == NULL)
        std::cout << "Failed to load texture. Error: " << SDL_GetError() << std::endl;
    
    return texture;
}

void Renderer::clear()
{
    SDL_SetRenderDrawColor(renderer, 90, 90, 90, 255);
    SDL_RenderClear(renderer);
}

void Renderer::render(Component& p_component)
{
    
    for (int i = p_component.getSize() - 1; i >= 0; i--)
    {
        SDL_Rect src;
        src.x = p_component.getCurrentFrame().x;
        src.y = p_component.getCurrentFrame().y;
        src.w = p_component.getCurrentFrame().w;
        src.h = p_component.getCurrentFrame().h;
        
        SDL_Rect dst;
        dst.x = p_component.getX() + p_component.getAnimOffsetX(i);
        dst.y = p_component.getY() + p_component.getAnimOffsetY(i);
        dst.w = p_component.getCurrentFrame().w;
        dst.h = p_component.getCurrentFrame().h;
        
        SDL_RenderCopy(renderer, p_component.getTex(i), &src, &dst);
    }
}

void Renderer::render(float p_x, float p_y, SDL_Texture* p_tex)
{
    SDL_Rect src;
    src.x = 0;
    src.y = 0;
    SDL_QueryTexture(p_tex, NULL, NULL, &src.w, &src.h);
    
    SDL_Rect dst;
    dst.x = p_x;
    dst.y = p_y;
    dst.w = src.w;
    dst.h = src.h;
    
    SDL_RenderCopy(renderer, p_tex, &src, &dst);
}

void Renderer::render(SDL_Texture* p_tex)
{
    render(0, 0, p_tex);
}

void Renderer::render(float p_x, float p_y, const char* p_text, TTF_Font* font, SDL_Color textColor)
{
    SDL_Surface* surfaceMessage = TTF_RenderText_Blended( font, p_text, textColor);
    SDL_Texture* message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
    
    SDL_Rect src;
    src.x = 0;
    src.y = 0;
    src.w = surfaceMessage->w;
    src.h = surfaceMessage->h;
    
    SDL_Rect dst;
    dst.x = p_x;
    dst.y = p_y;
    dst.w = src.w;
    dst.h = src.h;
    
    SDL_RenderCopy(renderer, message, &src, &dst);
    SDL_FreeSurface(surfaceMessage);
}

void Renderer::renderCenter(float p_x, float p_y, const char* p_text, TTF_Font* font, SDL_Color textColor)
{
    SDL_Surface* surfaceMessage = TTF_RenderText_Blended( font, p_text, textColor);
    SDL_Texture* message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
    
    SDL_Rect src;
    src.x = 0;
    src.y = 0;
    src.w = surfaceMessage->w;
    src.h = surfaceMessage->h;
    
    SDL_Rect dst;
    dst.x = SCREEN_WIDTH/2 - src.w/2 + p_x;
    dst.y = SCREEN_HEIGHT/2 - src.h/2 + p_y;
    dst.w = src.w;
    dst.h = src.h;
    
    SDL_RenderCopy(renderer, message, &src, &dst);
    SDL_FreeSurface(surfaceMessage);
}

void Renderer::display()
{
    SDL_RenderPresent(renderer);
}

void Renderer::cleanUp()
{
    SDL_DestroyWindow(window);
}


