cmake_minimum_required(VERSION 3.14)
project(Mathlib VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Header-only math library target
add_library(mathlib INTERFACE)
target_include_directories(mathlib INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include>
)

# Test suite
option(MATHLIB_BUILD_TESTS "Build Mathlib unit tests" ON)
if(MATHLIB_BUILD_TESTS)
    enable_testing()
    add_executable(test_runner tests/test_math.cpp)
    target_link_libraries(test_runner PRIVATE mathlib)
    add_test(NAME math_tests COMMAND test_runner)
endif()

# Examples
option(MATHLIB_BUILD_EXAMPLES "Build Mathlib examples" ON)
if(MATHLIB_BUILD_EXAMPLES)
    add_executable(basic_usage examples/basic_usage.cpp)
    target_link_libraries(basic_usage PRIVATE mathlib)
endif()
