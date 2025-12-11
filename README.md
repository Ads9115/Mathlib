# 🧮 OpenGL Mathematics Library (C++)

![C++](https://img.shields.io/badge/C%2B%2B-17-blue?logo=c%2B%2B)
![OpenGL](https://img.shields.io/badge/OpenGL-Math-orange?logo=opengl)
![License](https://img.shields.io/badge/License-MIT-green)
![Status](https://img.shields.io/badge/Version-v0.3--Core--Math-blueviolet)

A lightweight, header-only **mathematics library** written in **C++**, designed to rebuild and understand the core mathematical foundations used in **OpenGL graphics programming** — including vectors, matrices, transformations, shaders, and projection utilities.

This project is part of an ongoing effort to learn, document, and implement graphics-related math operations from scratch without relying on libraries like GLM.

---

## 🚀 Features

### 🧱 Vector Types

#### `vec2`
- Addition, subtraction, scalar multiplication  
- Dot product  
- Length and normalization  
- Stream output helpers  

#### `vec3`
- Addition, subtraction, scalar multiplication  
- Dot and cross product  
- Length and normalization  
- Stream output for debugging  

#### `vec4` *(new)*
- Addition, subtraction, scalar multiplication  
- Dot product  
- Homogeneous coordinate utilities  
- Stream output helpers  

---

## 🧮 Matrix Operations (`mat4`)
- Identity matrix  
- Matrix–matrix multiplication  
- **Scale matrix** ✔ *(new)*  
- **Rotation matrix** (X/Y/Z + arbitrary axis) ✔ *(new)*  
- LookAt view matrix  
- Perspective projection matrix  
- Pointer access for OpenGL (`glUniformMatrix4fv`)  

---

## 🎨 Shader Abstraction *(new)*

### Files:
- `shader.cpp`
- `shader.h`

### Features:
- Load vertex and fragment shader files  
- Compile and link shaders  
- Error checking and log output  
- `use()` method binding  
- Uniform helpers:  
  - `setMat4()`  
  - `setVec3()`  
  - `setVec4()`  
  - `setFloat()`  
  - `setInt()`  

A minimal, modern OpenGL-style abstraction to clean up rendering code.

---

## 🔧 Compatibility
- **Language:** C++17 or newer  
- **API:** OpenGL (GLAD + GLFW)  
- **Platform:** Windows / Linux / macOS  

---

## 🧠 Goals
- Build a strong foundation in graphics math  
- Understand the logic behind OpenGL transformations  
- Create a reusable math + shader abstraction layer  
- Prepare groundwork for a future graphics engine  

---

## 🌱 Future Plans

| Feature | Status |
|--------|--------|
| `mat3` support | ⏳ Planned |
| Translation matrix | ⏳ Planned |
| Orthographic projection | ⏳ Planned |
| Quaternions | ⏳ Planned |
| Camera utilities | ⏳ Planned |
| Material + Texture abstraction | ⏳ Planned |
| Unit tests | ⏳ Planned |

---

## 🧑‍💻 Contributing

1. **Fork** the repository  
2. **Create a branch** (`feature/your-feature-name`)  
3. **Commit your changes**  
4. **Open a Pull Request**  

---

