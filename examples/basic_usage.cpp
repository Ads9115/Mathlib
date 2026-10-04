#include "mathlib/mathlib.h"
#include <iostream>

int main() {
    vec3 position(0.0f, 0.0f, -3.0f);
    vec3 axis(0.0f, 1.0f, 0.0f);

    mat4 model =
        mat4::translate(position) * mat4::rotate(radians(45.0f), axis) * mat4::scale(vec3(1.2f));

    mat4 view =
        mat4::lookAt(vec3(0.0f, 0.0f, 3.0f), vec3(0.0f, 0.0f, 0.0f), vec3(0.0f, 1.0f, 0.0f));

    mat4 proj = mat4::perspective(radians(45.0f), 16.0f / 9.0f, 0.1f, 100.0f);

    std::cout << "Model matrix:" << std::endl;
    model.print();

    std::cout << "\nView matrix:" << std::endl;
    view.print();

    std::cout << "\nProjection matrix:" << std::endl;
    proj.print();

    return 0;
}
