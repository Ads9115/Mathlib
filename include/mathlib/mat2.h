#pragma once
#include "common.h"
#include "vec2.h"
#include <cmath>
#include <iostream>

struct mat2 {
    float m[4];

    mat2() : m{ 1.0f, 0.0f, 0.0f, 1.0f } {}

    const float* ptr() const { return m; }

    static mat2 identity() { return mat2(); }

    void print() const {
        std::cout << "mat2:" << std::endl;
        std::cout << m[0] << "\t" << m[2] << std::endl;
        std::cout << m[1] << "\t" << m[3] << std::endl;
    }

    mat2 operator*(const mat2& rhs) const {
        mat2 result;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                float sum = 0.0f;
                for (int k = 0; k < 2; k++) {
                    sum += m[k * 2 + j] * rhs.m[i * 2 + k];
                }
                result.m[i * 2 + j] = sum;
            }
        }
        return result;

    }
    vec2 operator*(const vec2& rhs) const {
        return vec2(
            m[0] * rhs.x + m[2] * rhs.y,
            m[1] * rhs.x + m[3] * rhs.y
        );
    }

    static mat2 scale(const vec2& s) {
        mat2 scale_mat = identity();
        scale_mat.m[0] = s.x;
        scale_mat.m[3] = s.y;
        return scale_mat;
    }

    static mat2 rotate(float angle_rad) {
        float s = std::sin(angle_rad);
        float c = std::cos(angle_rad);
        mat2 res;
        res.m[0] = c;
        res.m[1] = s;
        res.m[2] = -s;
        res.m[3] = c;
        return res;
    }

    float determinant() const {
        return m[0] * m[3] - m[1] * m[2];
    }

    mat2 transpose() const {
        mat2 res;
        res.m[0] = m[0];
        res.m[1] = m[2];
        res.m[2] = m[1];
        res.m[3] = m[3];
        return res;
    }

    mat2 inverse() const {
        float det = determinant();
        if (std::abs(det) < 1e-6f) {
            std::cerr << "mat2 is singular (non-invertible)!\n";
            return identity();
        }
        float invDet = 1.0f / det;
        mat2 res;
        res.m[0] = m[3] * invDet;
        res.m[1] = -m[1] * invDet;
        res.m[2] = -m[2] * invDet;
        res.m[3] = m[0] * invDet;
        return res;
    }

};
