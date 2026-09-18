#include <iostream>
#include <iomanip>

#include <SDL3/SDL.h>

#include "Renderer.h"
#include "Cube.h"
#include "Vector2.h"
#include "Vector3.h"
#include "Projection.h"
#include "Transform.h"

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
    std::cout << std::fixed;
    std::cout << std::setprecision(2);


    // init projekt
    SDL_Init(SDL_INIT_VIDEO);

    // vindue
    char* title = "Window";
    int width = 800, height = 600;
    float aspectRatio = (float)width/(float)height;

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
    Vector3 cubePos = {0,0,5};
    Vector3 cubeRotation = {0,0,0};
    Vector2 projected[8]; // de nye 2d punkter

    Vector3 camPos = {0,0,0};
    Vector2 camRotation = {0,0};

    bool running = true;
    SDL_Event event; // input

    // game loop
    while (running) {
        while (SDL_PollEvent(&event)) { // loop events hvis nogen
            if (event.type == SDL_EVENT_QUIT) { // Window luk knap
                running = false;
            }
        }
        
        // keyboard
        const bool* keyboard = SDL_GetKeyboardState(nullptr);
        
        if (keyboard[SDL_SCANCODE_A]) camPos.x -= 0.005f;
        if (keyboard[SDL_SCANCODE_D]) camPos.x += 0.005f;
        if (keyboard[SDL_SCANCODE_S]) camPos.z -= 0.005f;
        if (keyboard[SDL_SCANCODE_W]) camPos.z += 0.005f;
        if (keyboard[SDL_SCANCODE_SPACE]) camPos.y += 0.005f;
        if (keyboard[SDL_SCANCODE_LSHIFT]) camPos.y -= 0.005f;

        if (keyboard[SDL_SCANCODE_LEFT]) camRotation.y += 0.00075f;
        if (keyboard[SDL_SCANCODE_RIGHT]) camRotation.y -= 0.00075f;
        if (keyboard[SDL_SCANCODE_UP]) camRotation.x += 0.00075f;
        if (keyboard[SDL_SCANCODE_DOWN]) camRotation.x -= 0.00075f;

        std::cout <<
        "X: " << camPos.x <<
        "\tY: " << camPos.y <<
        "\tZ: " << camPos.z <<
        "\r" << std::flush;

        //cubeRotation = translate(cubeRotation,{0.002f,0.002f,0.001f});

        //opdater projekteret placering
        for (int i = 0; i < 8; i++)
        {
            Vector3 point = cube.vertices[i];

            point = rotateY(point,cubeRotation.y);
            point = rotateX(point,cubeRotation.x);
            point = rotateZ(point,cubeRotation.z);
            point = translate(point,cubePos);
            point = translate(point,{-camPos.x, -camPos.y, -camPos.z});
            point = rotateY(point,-camRotation.y);
            point = rotateX(point,camRotation.x);
            

            projected[i] = project(point,aspectRatio);

        }

        renderer.clear(); // ryd skærm med farve

        renderer.drawColor(255,255,255,255);
        for (int i = 0; i < 12; i++)
        {
            Edge edge = cube.edges[i];

            Vector2 a = projected[edge.a];
            Vector2 b = projected[edge.b];

            a.x = (1+a.x) / 2 * width;
            a.y = (1-a.y)/ 2 * height; // vend aksen om

            b.x = (1+b.x) / 2 * width;
            b.y = (1-b.y)/ 2 * height;

            renderer.drawLine(a, b);
        }
        
        
        // Vis det der er renderet
        renderer.present();
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
