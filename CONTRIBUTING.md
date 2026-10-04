# Contributing to Mathlib

Thanks for checking out Mathlib! Whether you are here for Hacktoberfest or just want to improve graphics math tooling, contributions are welcome.

## Getting Started

1. Fork the repository and create your branch from `main`:
   ```bash
   git checkout -b feature/my-new-feature
   ```

2. Make your changes. Keep them focused on a single feature, bug fix, or test improvement.

## Building and Running Tests

Mathlib uses CMake for building and running tests:

```bash
cmake -B build
cmake --build build
ctest --test-dir build --output-on-failure
```

You can also run tests directly with `g++`:
```bash
g++ -std=c++17 -Iinclude tests/test_math.cpp -o test_runner
./test_runner
```

## Code Style

- Format code using `.clang-format`:
  ```bash
  clang-format -i include/mathlib/*.h tests/test_math.cpp examples/basic_usage.cpp
  ```
- Keep code clean, readable, and minimal.
- Avoid introducing external dependencies for math operations.

## Pull Request Guidelines

- If you add or modify math functions, add corresponding test cases in `tests/test_math.cpp`.
- Ensure all tests pass before submitting.
- Provide a clear PR description explaining what was changed and how you tested it.

### Hacktoberfest Quality Notice

To keep the project healthy and respect everyone's time:
- PRs that only fix trivial typos, tweak whitespace, or submit automated/AI-generated spam without meaningful value will be labeled `invalid` or `spam`.
