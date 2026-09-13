#include "Projection.h"

Vector2 project(Vector3 point) {
    float focalLength = 400.0f;
    Vector2 result;

    result.x = (point.x / point.z) * focalLength + 400;
    result.y = (point.y / point.z) * focalLength + 300;

    return result;
}