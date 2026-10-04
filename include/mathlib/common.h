#pragma once
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

inline constexpr float PI = 3.14159265359f;

inline float radians(float degrees) {
    return degrees * (PI / 180.0f);
}
