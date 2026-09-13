#pragma once

#include <SDL3/SDL.h>
#include "Vector2.h"

class Renderer {
    private:
        SDL_Renderer* renderer;
    
    public:
        Renderer(SDL_Renderer* renderer); // constructor

        void clear();
        void present();
        void drawColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);

        void drawLine(int x1, int y1, int x2, int y2);
        void drawLine(Vector2 a, Vector2 b);
};