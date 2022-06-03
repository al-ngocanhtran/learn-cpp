//
//  renderer.hpp
//  demo
//
//  Created by Mac Air on 6/2/22.
//  Copyright © 2022 AL. All rights reserved.
//

#ifndef renderer_h
#define renderer_h

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <iostream>
#include <stdio.h>

#include "Component.h"

class Renderer
{
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
public:
    Renderer();
    void create(const char* p_title, int p_w, int p_h);
    SDL_Texture* loadTexture(const char* p_filePath);
    void clear();
    void render(Component& p_component); //render  entity  at  current  position
    void render(float p_x, float p_y, SDL_Texture* p_tex);
    void render(SDL_Texture* p_tex);
    void render(float p_x, float p_y, const char* p_text, TTF_Font* font, SDL_Color textColor);
    void renderCenter(float p_x, float p_y, const char* p_text, TTF_Font* font, SDL_Color textColor);
    void display();
    void cleanUp();
};
#endif /* renderer_h */
