#include <cmath>
#include <iostream>

// Classify a finite number as positive, negative, or zero using if/else.
int main() {
    double number;
    std::cout << "Enter a number: ";
    if (!(std::cin >> number)) {
        std::cout << "Invalid input.\n";
        return 0;
    }
    if (!std::isfinite(number)) {
        std::cout << "Enter a finite number.\n";
        return 0;
    }

    if (number > 0) {
        std::cout << "Positive\n";
    } else if (number < 0) {
        std::cout << "Negative\n";
    } else {
        // Both 0.0 and -0.0 compare equal to zero.
        std::cout << "Zero\n";
    }
    return 0;
}
