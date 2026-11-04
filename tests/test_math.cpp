#include "mathlib/mathlib.h"
#include <cassert>
#include <cmath>
#include <iostream>

static bool approxEqual(float a, float b, float eps = 1e-4f) {
    return std::abs(a - b) <= eps;
}

void testVec2() {
    vec2 a(1.0f, 2.0f);
    vec2 b(3.0f, 4.0f);

    vec2 sum = a + b;
    assert(approxEqual(sum.x, 4.0f) && approxEqual(sum.y, 6.0f));

    vec2 diff = b - a;
    assert(approxEqual(diff.x, 2.0f) && approxEqual(diff.y, 2.0f));

    vec2 scaled = a * 2.0f;
    assert(approxEqual(scaled.x, 2.0f) && approxEqual(scaled.y, 4.0f));

    assert(approxEqual(vec2(3.0f, 4.0f).length(), 5.0f));

    vec2 norm = vec2(3.0f, 4.0f).normalize();
    assert(approxEqual(norm.length(), 1.0f));

    float dot = vec2::dot(a, b);
    assert(approxEqual(dot, 11.0f));

    std::cout << "[PASS] vec2 tests" << std::endl;
}

void testVec3() {
    vec3 a(1.0f, 0.0f, 0.0f);
    vec3 b(0.0f, 1.0f, 0.0f);

    vec3 cross = vec3::cross(a, b);
    assert(approxEqual(cross.x, 0.0f) && approxEqual(cross.y, 0.0f) && approxEqual(cross.z, 1.0f));

    assert(approxEqual(vec3::dot(a, b), 0.0f));
    assert(approxEqual(vec3::dot(a, a), 1.0f));

    vec3 neg = -a;
    assert(approxEqual(neg.x, -1.0f));

    vec3 norm = vec3(0.0f, 5.0f, 0.0f).normalize();
    assert(approxEqual(norm.y, 1.0f) && approxEqual(norm.length(), 1.0f));

    std::cout << "[PASS] vec3 tests" << std::endl;
}

void testVec4() {
    vec4 a(1.0f, 2.0f, 3.0f, 4.0f);
    vec4 b(1.0f, 1.0f, 1.0f, 1.0f);

    vec4 sum = a + b;
    assert(approxEqual(sum.x, 2.0f) && approxEqual(sum.w, 5.0f));

    float dot = vec4::dot(a, b);
    assert(approxEqual(dot, 10.0f));

    std::cout << "[PASS] vec4 tests" << std::endl;
}

void testMat4() {
    mat4 I = mat4::identity();
    assert(approxEqual(I.m[0], 1.0f) && approxEqual(I.m[5], 1.0f) && approxEqual(I.m[10], 1.0f) &&
           approxEqual(I.m[15], 1.0f));
    assert(approxEqual(I.m[1], 0.0f) && approxEqual(I.m[14], 0.0f));

    mat4 T = mat4::translate(vec3(2.0f, 3.0f, 4.0f));
    assert(approxEqual(T.m[12], 2.0f) && approxEqual(T.m[13], 3.0f) && approxEqual(T.m[14], 4.0f));

    mat4 S = mat4::scale(vec3(2.0f, 3.0f, 4.0f));
    assert(approxEqual(S.m[0], 2.0f) && approxEqual(S.m[5], 3.0f) && approxEqual(S.m[10], 4.0f));

    mat4 mul = I * T;
    assert(approxEqual(mul.m[12], 2.0f) && approxEqual(mul.m[13], 3.0f) &&
           approxEqual(mul.m[14], 4.0f));

    mat4 proj = mat4::perspective(radians(45.0f), 16.0f / 9.0f, 0.1f, 100.0f);
    assert(approxEqual(proj.m[11], -1.0f));
    assert(approxEqual(proj.m[15], 0.0f));

    std::cout << "[PASS] mat4 tests" << std::endl;
}
void testMat3() {
    mat3 I;
    for (int i = 0; i < 9; i++) {
        float expected = (i == 0 || i == 4 || i == 8) ? 1.0f : 0.0f;
        assert(approxEqual(I.m[i], expected));
    }
    assert(I.ptr() == I.m);

    // Scalar diagonal initialization
    mat3 D(3.0f);
    assert(approxEqual(D.m[0], 3.0f) && approxEqual(D.m[4], 3.0f) && approxEqual(D.m[8], 3.0f));
    assert(approxEqual(D.m[1], 0.0f) && approxEqual(D.m[3], 0.0f) && approxEqual(D.m[7], 0.0f));
    mat3 A;
    for (int i = 0; i < 9; i++)
        A.m[i] = static_cast<float>(i + 1);

    mat3 AI = A * I;
    mat3 IA = I * A;
    for (int i = 0; i < 9; i++) {
        assert(approxEqual(AI.m[i], A.m[i]));
        assert(approxEqual(IA.m[i], A.m[i]));
    }

    mat3 B;
    const float bData[9] = {9, 6, 3, 8, 5, 2, 7, 4, 1};
    for (int i = 0; i < 9; i++)
        B.m[i] = bData[i];
    mat3 AB = A * B;
    const float expectedAB[9] = {54, 72, 90, 42, 57, 72, 30, 42, 54};
    for (int i = 0; i < 9; i++)
        assert(approxEqual(AB.m[i], expectedAB[i]));

    mat3 BA = B * A;
    assert(!approxEqual(AB.m[1], BA.m[1]));

    vec3 v = A * vec3(1.0f, 1.0f, 1.0f);
    assert(approxEqual(v.x, 12.0f) && approxEqual(v.y, 15.0f) && approxEqual(v.z, 18.0f));
    vec3 same = I * vec3(1.0f, 2.0f, 3.0f);
    assert(approxEqual(same.x, 1.0f) && approxEqual(same.y, 2.0f) && approxEqual(same.z, 3.0f));

    // 90 degree rotation about Z (column-major): x axis -> y axis
    mat3 Rz;
    Rz.m[0] = 0.0f;
    Rz.m[1] = 1.0f;
    Rz.m[3] = -1.0f;
    Rz.m[4] = 0.0f;
    vec3 rotated = Rz * vec3(1.0f, 0.0f, 0.0f);
    assert(approxEqual(rotated.x, 0.0f) && approxEqual(rotated.y, 1.0f) &&
           approxEqual(rotated.z, 0.0f));
    mat3 At = A.transpose();
    const float expectedAt[9] = {1, 4, 7, 2, 5, 8, 3, 6, 9};
    for (int i = 0; i < 9; i++)
        assert(approxEqual(At.m[i], expectedAt[i]));
    mat3 Att = At.transpose();
    for (int i = 0; i < 9; i++) {
        assert(approxEqual(Att.m[i], A.m[i]));
        assert(approxEqual(I.transpose().m[i], I.m[i]));
    }

    mat3 lhs = (A * B).transpose();
    mat3 rhs = B.transpose() * A.transpose();
    for (int i = 0; i < 9; i++)
        assert(approxEqual(lhs.m[i], rhs.m[i]));

    std::cout << "[PASS] mat3 tests" << std::endl;
}

int main() {
    std::cout << "Running Mathlib tests..." << std::endl;
    testVec2();
    testVec3();
    testVec4();
    testMat4();
    testMat3();
    std::cout << "All tests passed successfully!" << std::endl;
    return 0;
}
