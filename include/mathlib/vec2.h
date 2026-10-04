#pragma once
#include <cmath>
#include <iostream>

struct vec2 {
    float x, y;

    vec2() : x(0.0f), y(0.0f) {}
    vec2(float x_, float y_) : x(x_), y(y_) {}
    vec2(float s) : x(s), y(s) {}

    const float* ptr() const { return &x; }

    vec2 operator+(const vec2& v) const { return vec2(x + v.x, y + v.y); }

    vec2 operator-(const vec2& v) const { return vec2(x - v.x, y - v.y); }

    vec2 operator*(float s) const { return vec2(x * s, y * s); }

    float length() const { return std::sqrt(x * x + y * y); }

    vec2 normalize() const {
        float l = length();
        if (l > 0.0f)
            return vec2(x / l, y / l);
        return vec2(0.0f, 0.0f);
    }

    vec2 normalise() const { return normalize(); }

    static float dot(const vec2& v1, const vec2& v2) { return v1.x * v2.x + v1.y * v2.y; }

    static float cross(const vec2& v1, const vec2& v2) { return v1.x * v2.y - v1.y * v2.x; }

    friend std::ostream& operator<<(std::ostream& os, const vec2& v) {
        os << "(" << v.x << ", " << v.y << ")";
        return os;
    }
};
