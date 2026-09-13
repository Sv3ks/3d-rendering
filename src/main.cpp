#include <SDL3/SDL.h>

#include "Renderer.h"

void drawLine(SDL_Renderer* renderer, int x1, int y1, int x2, int y2) {
    SDL_RenderLine(
        renderer,
        x1,
        y1,
        x2,
        y2
    );
}

int main() {
    // init projekt
    SDL_Init(SDL_INIT_VIDEO);

    // vindue
    char* title = "Window";
    int width = 800, height = 600;

    SDL_Window* window = SDL_CreateWindow(
        title,
        width,
        height,
        0
    );

    // lav renderer
    SDL_Renderer* sdlRenderer = SDL_CreateRenderer(
        window,
        nullptr
    );
    
    Renderer renderer(sdlRenderer);

    bool running = true;

    SDL_Event event; // input

    // game loop
    while (running) {
        while (SDL_PollEvent(&event)) { // loop events hvis nogen
            if (event.type == SDL_EVENT_QUIT) { // Window luk knap
                running = false;
            }
        }

        renderer.clear(); // ryd skærm med farve

        renderer.drawColor(255,0,0,255);
        renderer.drawLine(300, 200, 500, 200);
        renderer.drawLine(500, 200, 500, 400);
        renderer.drawLine(500, 400, 300, 400);
        renderer.drawLine(300, 400, 300, 200);
        
        // Vis det der er renderet
        renderer.present();
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
