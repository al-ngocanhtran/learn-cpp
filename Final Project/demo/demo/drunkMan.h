//
//  drunkMan.hpp
//  demo
//
//  Created by Mac Air on 6/2/22.
//  Copyright © 2022 AL. All rights reserved.
//

#ifndef drunkMan_h
#define drunkMan_h

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <vector>
#include <string>
#include <cmath>
#include "Component.h"

class DrunkMan: public Component{

public:
    DrunkMan(float p_x, float p_y, std::vector<SDL_Texture*> p_tex);
    float distanceFromCursor();
    void update(); //update position
    const char* getScore();
    int getScoreInt();
    int isDead();
    void reset();

private:
    float speed;
    //void move(); //aka move
    int score = 0;
    int timer = 0;
    int dead = 0;
};


#include <stdio.h>

#endif /* drunkMan_h */
