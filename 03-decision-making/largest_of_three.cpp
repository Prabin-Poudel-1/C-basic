#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>

// Find the largest of three finite numbers using if/else.
int main() {
    double first, second, third;
    std::cout << "Enter three numbers: ";
    if (!(std::cin >> first >> second >> third)) {
        std::cout << "Invalid input.\n";
        return 0;
    }
    if (!std::isfinite(first) || !std::isfinite(second) || !std::isfinite(third)) {
        std::cout << "Enter finite numbers.\n";
        return 0;
    }

    // Preserve double precision when printing the selected value.
    std::cout << std::setprecision(std::numeric_limits<double>::max_digits10);
    // >= handles ties without losing a shared maximum.
    double largest;
    if (first >= second && first >= third) {
        largest = first;
    } else if (second >= first && second >= third) {
        largest = second;
    } else {
        largest = third;
    }
    std::cout << "Largest: " << largest << '\n';
    return 0;
}
