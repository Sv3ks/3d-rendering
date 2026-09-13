#pragma once

#include "Vector2.h"
#include "Vector3.h"

class Camera {
    public:
        Vector2 project(Vector3 point);
};