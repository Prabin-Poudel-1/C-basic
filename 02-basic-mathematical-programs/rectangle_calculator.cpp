#include <cmath>
#include <iomanip>
#include <iostream>

// Calculate rectangle area and perimeter from non-negative dimensions.
int main() {
    double length, width;
    std::cout << "Enter length and width: ";
    if (!(std::cin >> length >> width)) {
        std::cout << "Invalid input.\n";
        return 0;
    }
    if (!std::isfinite(length) || !std::isfinite(width) || length < 0 || width < 0) {
        std::cout << "Dimensions must be finite and non-negative.\n";
        return 0;
    }

    // A rectangle has two pairs of equal sides.
    double area = length * width;
    double perimeter = 2 * (length + width);
    if (!std::isfinite(area) || !std::isfinite(perimeter)) {
        std::cout << "Result is too large.\n";
        return 0;
    }
    std::cout << std::fixed << std::setprecision(2)
              << "Area: " << area << "\nPerimeter: " << perimeter << '\n';
    return 0;
}
