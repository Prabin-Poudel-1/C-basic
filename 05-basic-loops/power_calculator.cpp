#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

// Raise a finite double base to an integer exponent using a loop.
int main() {
    std::cout << "Enter base and integer exponent (-1024 to 1024): ";
    std::string line;
    std::getline(std::cin, line);
    std::istringstream input(line);
    double base;
    int exponent;
    char extra;
    if (!(input >> base >> exponent) || (input >> extra)) {
        std::cout << "Invalid input.\n";
        return 0;
    }
    if (!std::isfinite(base)) {
        std::cout << "Base must be finite.\n";
        return 0;
    }
    if (exponent < -1024 || exponent > 1024) {
        std::cout << "Exponent must be between -1024 and 1024.\n";
        return 0;
    }
    if (base == 0 && exponent < 0) {
        std::cout << "Zero cannot have a negative exponent.\n";
        return 0;
    }
    double result = 1;
    int repetitions = exponent < 0 ? -exponent : exponent;
    for (int i = 0; i < repetitions; i++) {
        result *= base;
    }
    if (exponent < 0) result = 1 / result;
    if (!std::isfinite(result)) {
        std::cout << "Result is too large.\n";
        return 0;
    }
    std::cout << std::setprecision(10) << "Result: " << result << '\n';
    return 0;
}
