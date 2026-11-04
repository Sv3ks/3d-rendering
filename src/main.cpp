#include <iostream>
#include <iomanip>
#include <cmath>

#include <SDL3/SDL.h>

#include "Renderer.h"
#include "Cube.h"
#include "Vector2.h"
#include "Vector3.h"
#include "Projection.h"
#include "Transform.h"

const int TARGET_FPS = 60;
const int TARGET_FRAME_TIME = 1000 / TARGET_FPS;

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
    std::cout << aspectRatio << "\n";

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

    Cube cube1({-2,0,5},{0,0,0});
    Cube cube2({2,0,5},{0,0,0});

    Vector3 camPos = {0,0,0};
    Vector3 camRotation = {0,0,0};
    float camSpeed = 0.1f;
    float camRotSpeed = 0.02f;

    // FPS
    uint64_t frameStart;
    uint64_t frameTime;
    int currentFPS;

    bool running = true;
    SDL_Event event; // input

    // game loop
    while (running) {
        frameStart = SDL_GetTicks(); // FPS - starttid af frame

        while (SDL_PollEvent(&event)) { // loop events hvis nogen
            if (event.type == SDL_EVENT_QUIT) { // Window luk knap
                running = false;
            }
        }
        
        // keyboard
        const bool* keyboard = SDL_GetKeyboardState(nullptr);
        
        float cos = std::cos(camRotation.y), sin = std::sin(camRotation.y);
        if (keyboard[SDL_SCANCODE_A]) camPos.z -= camSpeed * -sin, camPos.x -= camSpeed * cos;
        if (keyboard[SDL_SCANCODE_D]) camPos.z += camSpeed * -sin, camPos.x += camSpeed * cos;
        if (keyboard[SDL_SCANCODE_S]) camPos.z -= camSpeed * cos, camPos.x -= camSpeed * sin;
        if (keyboard[SDL_SCANCODE_W]) camPos.z += camSpeed * cos, camPos.x += camSpeed * sin;
        if (keyboard[SDL_SCANCODE_SPACE]) camPos.y += camSpeed;
        if (keyboard[SDL_SCANCODE_LSHIFT]) camPos.y -= camSpeed;

        if (keyboard[SDL_SCANCODE_LEFT]) camRotation.y -= camRotSpeed;
        if (keyboard[SDL_SCANCODE_RIGHT]) camRotation.y += camRotSpeed;
        if (keyboard[SDL_SCANCODE_UP]) camRotation.x += camRotSpeed;
        if (keyboard[SDL_SCANCODE_DOWN]) camRotation.x -= camRotSpeed;


        std::cout <<
        "FPS: " << currentFPS <<
        "\t\tX: " << camPos.x <<
        "\tY: " << camPos.y <<
        "\tZ: " << camPos.z <<
        "\tYaw: " << camRotation.y <<
        "\tPitch: " << camRotation.x <<
        "\r" << std::flush;

        cube1.rotation = translate(cube1.rotation,{0.03f,0.02f,0.01f});

        //opdater projekteret placering
        cube1.Update(camPos, camRotation, aspectRatio);
        cube2.Update(camPos, camRotation, aspectRatio);

        renderer.clear(); // ryd skærm med farve

        renderer.drawColor(255,0,0,255);
        cube1.Draw(renderer, width, height);

        renderer.drawColor(0,255,0,255);
        cube2.Draw(renderer, width, height);
        
        // Vis det der er renderet
        renderer.present();

        frameTime = SDL_GetTicks() - frameStart;
        if (frameTime < TARGET_FRAME_TIME) {
            SDL_Delay(TARGET_FRAME_TIME - frameTime);
            currentFPS = TARGET_FPS;
        } else {
            currentFPS = 1000/frameTime;
        }
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
