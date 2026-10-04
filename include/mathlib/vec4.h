#pragma once
#include <cmath>
#include <iostream>

struct vec4 {
    float x, y, z, w;

    vec4() : x(0.0f), y(0.0f), z(0.0f), w(0.0f) {}
    vec4(float x_, float y_, float z_, float w_) : x(x_), y(y_), z(z_), w(w_) {}
    vec4(float s) : x(s), y(s), z(s), w(s) {}

    const float* ptr() const { return &x; }

    friend std::ostream& operator<<(std::ostream& os, const vec4& v) {
        os << "(" << v.x << ", " << v.y << ", " << v.z << ", " << v.w << ")";
        return os;
    }

    vec4 operator+(const vec4& v) const { return vec4(x + v.x, y + v.y, z + v.z, w + v.w); }

    vec4 operator-(const vec4& v) const { return vec4(x - v.x, y - v.y, z - v.z, w - v.w); }

    vec4 operator*(float s) const { return vec4(x * s, y * s, z * s, w * s); }

    float length() const { return std::sqrt(x * x + y * y + z * z + w * w); }

    vec4 normalize() const {
        float l = length();
        if (l > 0.0f)
            return vec4(x / l, y / l, z / l, w / l);
        return vec4(0.0f, 0.0f, 0.0f, 0.0f);
    }

    static float dot(const vec4& v1, const vec4& v2) {
        return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z + v1.w * v2.w;
    }
};
