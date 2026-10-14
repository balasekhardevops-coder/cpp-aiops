#include <iostream>
#include <exception>
#include "calc.h"

int main() {
    int a = 20;
    int b = 10;

    std::cout << "C++ Calculator\n";

    std::cout << "Addition: "
              << add(a, b) << "\n";

    std::cout << "Subtraction: "
              << subtract(a, b) << "\n";

    std::cout << "Multiplication: "
              << multiply(a, b) << "\n";

    try {
        std::cout << "Division: "
                  << divide(a, b) << "\n";
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }

    return 0;
}
