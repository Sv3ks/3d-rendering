#pragma once

#include "Vector3.h"
#include "Edge.h"

class Cube {
    public:
        Vector3 vertices[8]; //terning har 8 hjørner
        Edge edges[12]; // kanter

        Cube();
};