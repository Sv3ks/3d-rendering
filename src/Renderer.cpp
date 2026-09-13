#include "Renderer.h"
#include "Vector2.h"

Renderer::Renderer(SDL_Renderer* renderer) {
    this->renderer = renderer;
}

void Renderer::clear() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
}

void Renderer::present() {
    SDL_RenderPresent(renderer);
}

void Renderer::drawColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
    SDL_SetRenderDrawColor(renderer, r, g, b, a);
}

void Renderer::drawLine(int x1, int y1, int x2, int y2) {
    SDL_RenderLine(renderer, x1, y1, x2, y2);
}

void Renderer::drawLine(Vector2 a, Vector2 b) {
    SDL_RenderLine(renderer, a.x, a.y, b.x, b.y);
}