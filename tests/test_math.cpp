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

int main() {
    std::cout << "Running Mathlib tests..." << std::endl;
    testVec2();
    testVec3();
    testVec4();
    testMat4();
    std::cout << "All tests passed successfully!" << std::endl;
    return 0;
}
