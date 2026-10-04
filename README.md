# Mathlib

A lightweight, header-only C++ math library for graphics programming.

> Built for learning and small graphics projects where you want transparent math code instead of a large dependency stack.

## Features

- **Vectors (`vec2`, `vec3`, `vec4`)**:
  - Addition, subtraction, scalar multiplication
  - Dot product, cross product, length, and normalization
- **Matrices (`mat4`)**:
  - Identity and matrix multiplication
  - Transformations: `translate`, `scale`, `rotate`
  - Camera & projection: `lookAt`, `perspective`
- **Helpers**:
  - `radians()` conversion helper

## Repository Layout

```text
.
├── include/
│   └── mathlib/
│       ├── common.h
│       ├── mathlib.h        # Umbrella header
│       ├── vec2.h
│       ├── vec3.h
│       ├── vec4.h
│       └── mat4.h
├── examples/
│   └── basic_usage.cpp      # Usage example
├── tests/
│   └── test_math.cpp        # Unit tests
├── glMath.h                 # Backwards-compatible include
├── CMakeLists.txt
├── CONTRIBUTING.md
├── LICENSE
└── README.md
```

## How to Use

Since Mathlib is header-only, you can either:

1. Include the umbrella header in your project:
   ```cpp
   #include <mathlib/mathlib.h>
   ```
   *(or `#include "glMath.h"` if migrating from earlier versions)*

2. Or add it with CMake:
   ```cmake
   add_subdirectory(Mathlib)
   target_link_libraries(your_target PRIVATE mathlib)
   ```

### Quick Example

```cpp
#include <mathlib/mathlib.h>

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

## Building & Tests

Requires C++17 or newer. To build and run the test suite:

```bash
cmake -B build
cmake --build build
ctest --test-dir build --output-on-failure
```

To run the example:
```bash
./build/basic_usage
```

Or compile and run tests directly with `g++`:

```bash
g++ -std=c++17 -Iinclude tests/test_math.cpp -o test_runner
./test_runner
```

## Contributing

Contributions are welcome! Check [CONTRIBUTING.md](CONTRIBUTING.md) for guidelines on code style, tests, and pull requests.

## License

This project is licensed under the MIT License. See [LICENSE](LICENSE).
