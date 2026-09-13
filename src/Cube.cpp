#include "Cube.h"

Cube::Cube() {
    // foran
    vertices[0] = {-1, -1, -1};
    vertices[1] = { 1, -1, -1};
    vertices[2] = { 1,  1, -1};
    vertices[3] = {-1,  1, -1};
    // bagved
    vertices[4] = {-1, -1, 1};
    vertices[5] = { 1, -1, 1};
    vertices[6] = { 1,  1, 1};
    vertices[7] = {-1,  1, 1};

    edges[0] = {0,1};
    edges[1] = {1,2};
    edges[2] = {2,3};
    edges[3] = {3,0};

    edges[4] = {4,5};
    edges[5] = {5,6};
    edges[6] = {6,7};
    edges[7] = {7,4};

    edges[8] = {0,4};
    edges[9] = {1,5};
    edges[10] = {2,6};
    edges[11] = {3,7};
};
