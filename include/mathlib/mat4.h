#pragma once
#include "common.h"
#include "vec3.h"
#include <cmath>
#include <iostream>

struct mat4 {
    float m[16];

    mat4() {
        for (int i = 0; i < 16; i++)
            m[i] = 0.0f;
        m[0] = 1.0f;
        m[5] = 1.0f;
        m[10] = 1.0f;
        m[15] = 1.0f;
    }

    const float* ptr() const { return m; }

    static mat4 identity() { return mat4(); }

    void print() const {
        std::cout << "mat4:" << std::endl;
        for (int i = 0; i < 16; ++i) {
            std::cout << m[i] << "\t";
            if ((i + 1) % 4 == 0) {
                std::cout << std::endl;
            }
        }
    }

    mat4 operator*(const mat4& rhs) const {
        mat4 result;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                float sum = 0.0f;
                for (int k = 0; k < 4; k++) {
                    sum += m[k * 4 + j] * rhs.m[i * 4 + k];
                }
                result.m[i * 4 + j] = sum;
            }
        }
        return result;
    }

    static mat4 translate(const vec3& t) {
        mat4 result = identity();
        result.m[12] = t.x;
        result.m[13] = t.y;
        result.m[14] = t.z;
        return result;
    }

    static mat4 scale(const vec3& s) {
        mat4 scale_mat = identity();
        scale_mat.m[0] = s.x;
        scale_mat.m[5] = s.y;
        scale_mat.m[10] = s.z;
        return scale_mat;
    }

    static mat4 rotate(float angle_rad, const vec3& axis) {
        vec3 norm_axis = axis.normalize();
        float c = std::cos(angle_rad);
        float s = std::sin(angle_rad);
        float t = 1.0f - c;
        float x = norm_axis.x;
        float y = norm_axis.y;
        float z = norm_axis.z;

        mat4 rot = identity();
        rot.m[0] = t * x * x + c;
        rot.m[1] = t * x * y + s * z;
        rot.m[2] = t * x * z - s * y;

        rot.m[4] = t * x * y - s * z;
        rot.m[5] = t * y * y + c;
        rot.m[6] = t * y * z + s * x;

        rot.m[8] = t * x * z + s * y;
        rot.m[9] = t * y * z - s * x;
        rot.m[10] = t * z * z + c;

        return rot;
    }

    static mat4 lookAt(const vec3& eye, const vec3& centre, const vec3& up) {
        vec3 f = (eye - centre).normalize();
        vec3 s = vec3::cross(up, f).normalize();
        vec3 u = vec3::cross(f, s);

        mat4 result = identity();
        result.m[0] = s.x;
        result.m[1] = u.x;
        result.m[2] = f.x;

        result.m[4] = s.y;
        result.m[5] = u.y;
        result.m[6] = f.y;

        result.m[8] = s.z;
        result.m[9] = u.z;
        result.m[10] = f.z;

        result.m[12] = -vec3::dot(s, eye);
        result.m[13] = -vec3::dot(u, eye);
        result.m[14] = -vec3::dot(f, eye);

        return result;
    }

    static mat4 perspective(float fov_rad, float aspect_ratio, float zNear, float zFar) {
        mat4 result;
        for (int i = 0; i < 16; i++)
            result.m[i] = 0.0f;

        float tanHalfFov = std::tan(fov_rad / 2.0f);
        float f = 1.0f / tanHalfFov;
        float zRange = zNear - zFar;

        result.m[0] = f / aspect_ratio;
        result.m[5] = f;
        result.m[10] = (zFar + zNear) / zRange;
        result.m[11] = -1.0f;
        result.m[14] = (2.0f * zFar * zNear) / zRange;

        return result;
    }
};
