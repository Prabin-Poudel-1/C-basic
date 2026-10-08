#include <cmath>
#include <iomanip>
#include <iostream>

// Calculate circle area and circumference from non-negative dimensions.
int main() {
    double radius;
    std::cout << "Enter radius: ";
    if (!(std::cin >> radius)) {
        std::cout << "Invalid input.\n";
        return 0;
    }
    if (!std::isfinite(radius) || radius < 0) {
        std::cout << "Radius must be finite and non-negative.\n";
        return 0;
    }

    // acos(-1) gives pi without relying on a non-standard constant.
    const double pi = std::acos(-1.0);
    double area = pi * radius * radius;
    double circumference = 2 * pi * radius;
    if (!std::isfinite(area) || !std::isfinite(circumference)) {
        std::cout << "Result is too large.\n";
        return 0;
    }
    std::cout << std::fixed << std::setprecision(2)
              << "Area: " << area << "\nCircumference: " << circumference << '\n';
    return 0;
}
