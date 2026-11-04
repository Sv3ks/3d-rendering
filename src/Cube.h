#pragma once

#include "Vector3.h"
#include "Vector2.h"
#include "Edge.h"
#include "Renderer.h"

class Cube {
    public:
        Vector3 vertices[8]; //terning har 8 hjørner
        Edge edges[18]; // kanter
        bool visible[8];
        Vector3 position, rotation; 
        Vector2 projected[8]; // 2d punkter

        Cube(Vector3 pos, Vector3 rot);
        void Update(Vector3 camPos, Vector3 camRotation, float aspectRatio);
        void Draw(Renderer renderer, int width, int height);
};