
cmake_minimum_required(VERSION 3.16)

project(Calculator VERSION 1.0.0 LANGUAGES CXX)

# C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Calculator library
add_library(calc_lib src/calc.cpp)

target_include_directories(calc_lib PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
)

# Main application
add_executable(calculator src/main.cpp)

target_link_libraries(calculator PRIVATE calc_lib)

# Enable testing
include(CTest)

if(BUILD_TESTING)

    add_executable(calc_tests
        tests/test_calc.cpp
    )

    target_link_libraries(calc_tests PRIVATE calc_lib)

    add_test(
        NAME CalculatorTest
        COMMAND calc_tests
    )

endif()

# Install only production executable
install(
    TARGETS calculator
    RUNTIME DESTINATION bin
)
