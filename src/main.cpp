#include <SDL3/SDL.h>

#include "Renderer.h"
#include "Cube.h"
#include "Vector2.h"
#include "Vector3.h"
#include "Projection.h"

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

    Cube cube;

    Vector2 projected[8]; // de nye 2d punkter

    for (int i = 0; i < 8; i++)
    {
        Vector3 point = cube.vertices[i];
        point.z += 5;
        point.x -= 2.5f;
        point.y += 1.75f;
        projected[i] = project(point);
    }
    

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
        for (int i = 0; i < 12; i++)
        {
            Edge edge = cube.edges[i];
            renderer.drawLine(projected[edge.a], projected[edge.b]);
        }
        
        
        // Vis det der er renderet
        renderer.present();
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
