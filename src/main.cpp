#include <SDL3/SDL.h>

int main() {
    // init project
    SDL_Init(SDL_INIT_VIDEO);

    // window
    char* title = "Window";
    int width = 800, height = 600;

    SDL_Window* window = SDL_CreateWindow(
        title,
        width,
        height,
        0
    );

    bool running = true;

    SDL_Event event; // input

    // game loop
    while (running) {
        while (SDL_PollEvent(&event)) { // loop events if any
            if (event.type == SDL_EVENT_QUIT) { // Window close button
                running = false;
            }
        }
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
