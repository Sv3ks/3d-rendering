#pragma once

#include <SDL3/SDL.h>

class Renderer {
    private:
        SDL_Renderer* renderer;
    
    public:
        Renderer(SDL_Renderer* renderer); // constructor

        void clear();
        void present();
        void drawColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);

        void drawLine(
            int x1,
            int y1,
            int x2,
            int y2
        );
};