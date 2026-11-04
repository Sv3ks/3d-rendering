#include "Cube.h"
#include "Vector2.h"
#include "Transform.h"
#include "Projection.h"
#include "Renderer.h"

Cube::Cube(Vector3 pos, Vector3 rot) {
    position = pos;
    rotation = rot;

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

    edges[12] = {0,2};
    edges[13] = {5,7};
    edges[14] = {3,4};
    edges[15] = {1,6};
    edges[16] = {3,6};
    edges[17] = {1,4};
};

void Cube::Update(Vector3 camPos, Vector3 camRotation, float aspectRatio) {
    for (int i = 0; i < 8; i++)
    {
        Vector3 point = this->vertices[i];


        point = rotateY(point,rotation.y);
        point = rotateX(point,rotation.x);
        point = rotateZ(point,rotation.z);
        point = translate(point,position);
        point = translate(point,{-camPos.x, -camPos.y, -camPos.z});
        point = rotateY(point,camRotation.y);
        point = rotateX(point,camRotation.x);
        
        if (point.z <= 0.0f) { 
            visible[i] = false;
            continue; 
        } 
        visible[i] = true;

        projected[i] = project(point,aspectRatio);

    }
}

void Cube::Draw(Renderer renderer, int width, int height) {
    for (int i = 0; i < 12; i++)
    {
        Edge edge = edges[i];            

        if (!visible[edge.a] || !visible[edge.b])
            continue;

        Vector2 a = this->projected[edge.a];
        Vector2 b = this->projected[edge.b];

        a.x = (1+a.x) / 2 * width;
        a.y = (1-a.y)/ 2 * height; // vend aksen om

        b.x = (1+b.x) / 2 * width;
        b.y = (1-b.y)/ 2 * height;

        renderer.drawLine(a, b);
    }
}