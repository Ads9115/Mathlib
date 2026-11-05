#pragma once
#include "common.h"
#include "vec3.h"
#include <cmath>
#include <iostream>

struct mat3 {
    float m[9];
    mat3() : m{1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f} {}
    explicit mat3(float s)
        : m{s, 0.0f, 0.0f, 0.0f, s, 0.0f, 0.0f, 0.0f, s} {} // scalar diagonal initialization

    const float* ptr() const { return m; }
    static mat3 identity() { return mat3(); }
    void print() const {
        std::cout << "mat3:" << std::endl;
        for (int row = 0; row < 3; ++row) {
            std::cout << m[row] << "\t" << m[3 + row] << "\t" << m[6 + row] << std::endl;
        }
    }

    mat3 operator*(const mat3& rhs) const {
        mat3 result;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                float sum = 0.0f;
                for (int k = 0; k < 3; k++) {
                    sum += m[k * 3 + j] * rhs.m[i * 3 + k];
                }
                result.m[i * 3 + j] = sum;
            }
        }
        return result;
    }

    vec3 operator*(const vec3& v) const {
        return vec3(m[0] * v.x + m[3] * v.y + m[6] * v.z, m[1] * v.x + m[4] * v.y + m[7] * v.z,
                    m[2] * v.x + m[5] * v.y + m[8] * v.z);
    }

    mat3 transpose() const {
        mat3 res;
        for (int c = 0; c < 3; c++) {
            for (int r = 0; r < 3; r++) {
                res.m[c * 3 + r] = m[r * 3 + c];
            }
        }
        return res;
    }
};
