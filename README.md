# 🧮 OpenGL Mathematics Library (C++)

![C++](https://img.shields.io/badge/C%2B%2B-17-blue?logo=c%2B%2B)
![OpenGL](https://img.shields.io/badge/OpenGL-Math-orange?logo=opengl)
![License](https://img.shields.io/badge/License-MIT-green)
![Status](https://img.shields.io/badge/Version-v0.1--Core--Math-blueviolet)

A lightweight, header-only **mathematics library** written in **C++**, designed to replicate and understand the core mathematical foundations used in **OpenGL graphics programming** — including vectors, matrices, transformations, and projection utilities.

This project is part of an ongoing effort to learn, document, and implement graphics-related math operations from scratch without relying on libraries like GLM.

---

## 🚀 Features

### 🧱 Vector Operations (`vec3`)
- Addition, subtraction, scalar multiplication  
- Dot and cross product  
- Normalization and length calculation  
- Stream output for debugging  

### 🧮 Matrix Operations (`mat4`)
- Identity matrix generation  
- Matrix–matrix multiplication  
- Rotation (arbitrary axis)  
- LookAt view matrix  
- Perspective projection matrix  
- Pointer access for OpenGL (`glUniformMatrix4fv` ready)  

---

## 🔧 Compatibility

- **Language:** C++17 or newer  
- **API:** OpenGL (GLAD + GLFW compatible)  
- **Platform:** Cross-platform (Windows / Linux / macOS)

---

## 🧠 Goals

- Build a strong foundation in graphics math  
- Understand the logic behind OpenGL transformations  
- Create a modular and reusable math system for rendering  
- Use this as groundwork for a future **graphics engine**  

---

## 🌱 Future Plans

| Feature | Status |
|----------|---------|
| `vec2`, `vec4`, `mat3` support | ⏳ Planned |
| Translation & scaling matrices | ⏳ Planned |
| Orthographic projection | ⏳ Planned |
| Quaternions | ⏳ Planned |
| Camera utilities | ⏳ Planned |
| Unit tests | ⏳ Planned |

---

## 🧑‍💻 Contributing

Contributions are welcome!  
If you’d like to improve the math library, add new operations, or optimize existing ones:

1. **Fork** the repository  
2. **Create a branch** (`feature/your-feature-name`)  
3. **Commit your changes**  
4. **Open a Pull Request**

---

