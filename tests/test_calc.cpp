
#include "calc.h"

#include <cmath>
#include <iostream>
#include <stdexcept>

int main() {

    if (add(10, 5) != 15) {
        std::cerr << "Addition test failed\n";
        return 1;
    }

    if (subtract(10, 5) != 5) {
        std::cerr << "Subtraction test failed\n";
        return 1;
    }

    if (multiply(10, 5) != 50) {
        std::cerr << "Multiplication test failed\n";
        return 1;
    }

    if (std::abs(divide(10, 4) - 2.5) > 1e-9) {
        std::cerr << "Division test failed\n";
        return 1;
    }

    bool caught = false;

    try {
        divide(10, 0);
    } catch (const std::invalid_argument&) {
        caught = true;
    }

    if (!caught) {
        std::cerr << "Divide-by-zero test failed\n";
        return 1;
    }

    std::cout << "All calculator tests passed!\n";

    return 0;
}