#include <cmath>
#include "Transform.h"

Vector3 translate(Vector3 point, Vector3 translation) {
    point.x += translation.x;
    point.y += translation.y;
    point.z += translation.z;
    return point;
}

Vector3 rotateX(Vector3 point, float angle) {
    Vector3 result;
    float cos = std::cos(angle), sin = std::sin(angle);

    result.x = point.x;
    result.y = point.y * cos - point.z * sin;
    result.z = point.y * sin + point.z * cos;

    return result;
}

Vector3 rotateY(Vector3 point, float angle) {
    Vector3 result;
    float cos = std::cos(angle), sin = std::sin(angle);

    result.x = point.x * cos - point.z * sin;
    result.y = point.y;
    result.z = point.x * sin + point.z * cos;

    return result;
}

Vector3 rotateZ(Vector3 point, float angle) {
    Vector3 result;
    float cos = std::cos(angle), sin = std::sin(angle);

    result.x = point.x * cos - point.y * sin;
    result.y = point.x * sin + point.y * cos;
    result.z = point.z;

    return result;
}