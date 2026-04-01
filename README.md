# Mathlib

A lightweight C++ math helper library for OpenGL-style graphics programming, plus a minimal shader wrapper.

> Built for learning and small graphics projects where you want transparent math code instead of a large dependency stack.

## What's in this repository

- `glMath.h` — header-only vector and matrix math types
  - `vec2`, `vec3`, `vec4`
  - `mat4` identity, multiply, translate, scale, rotate, lookAt, perspective
  - `radians()` helper
- `Shader.h` / `Shader.cpp` — basic shader program wrapper
  - loads vertex + fragment shader files
  - compiles and links a program
  - uniform helper setters (`float`, `int`, `vec2`, `vec3`, `vec4`, `mat4`)

## Repository layout

```text
.
├── glMath.h
├── Shader.h
├── Shader.cpp
├── README.md
└── LICENSE
```

## Requirements

- C++17 or newer
- OpenGL context setup in your app
- GL loader (current shader wrapper includes `<glad/glad.h>`)

## Quick start

### 1) Use the math types

```cpp
#include "glMath.h"

vec3 position(0.0f, 0.0f, -3.0f);
vec3 axis(0.0f, 1.0f, 0.0f);

mat4 model = mat4::translate(position)
           * mat4::rotate(radians(45.0f), axis)
           * mat4::scale(vec3(1.2f));

mat4 view = mat4::lookAt(
    vec3(0.0f, 0.0f, 3.0f),
    vec3(0.0f, 0.0f, 0.0f),
    vec3(0.0f, 1.0f, 0.0f)
);

mat4 proj = mat4::perspective(radians(45.0f), 16.0f / 9.0f, 0.1f, 100.0f);
```

### 2) Use the shader wrapper

```cpp
#include "Shader.h"

Shader shader("shaders/basic.vert", "shaders/basic.frag");
shader.use();
shader.setMat4("uModel", model);
shader.setMat4("uView", view);
shader.setMat4("uProjection", proj);
shader.setVec3("uColor", vec3(1.0f, 0.5f, 0.2f));
```

## Build note

This repository does not currently ship with CMake or another build system file.

Example (adapt include/library paths to your environment):

```bash
g++ -std=c++17 main.cpp Shader.cpp -I. -lglfw -ldl -lGL -o app
```

## Project goals

- Keep API minimal and easy to read
- Serve as an educational OpenGL math reference
- Incrementally improve correctness, tests, and debug tooling

## Roadmap ideas

- Add unit tests for vector/matrix correctness
- Add robust shader compile/link error reporting
- Add CMake build + CI workflow
- Add orthographic projection and `mat3`

## Contributing

Contributions are welcome. Please keep pull requests focused and include a short test/validation note.

## License

This project is licensed under the MIT License. See [LICENSE](LICENSE).
