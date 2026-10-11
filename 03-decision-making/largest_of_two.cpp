#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>

// Find the larger of two finite numbers using if/else.
int main() {
    double first, second;
    std::cout << "Enter two numbers: ";
    if (!(std::cin >> first >> second)) {
        std::cout << "Invalid input.\n";
        return 0;
    }
    if (!std::isfinite(first) || !std::isfinite(second)) {
        std::cout << "Enter finite numbers.\n";
        return 0;
    }

    // Preserve double precision when printing the selected value.
    std::cout << std::setprecision(std::numeric_limits<double>::max_digits10);
    if (first > second) {
        std::cout << "Largest: " << first << '\n';
    } else if (second > first) {
        std::cout << "Largest: " << second << '\n';
    } else {
        std::cout << "Both numbers are equal.\n";
    }
    return 0;
}
