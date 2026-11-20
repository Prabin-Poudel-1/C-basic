#include <cmath>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>

int main() {
    double dividend, divisor;
    std::cout << "Enter dividend and divisor: ";
    if (!(std::cin >> dividend >> divisor)) {
        std::cout << "Please enter two finite numbers.\n";
        return 0;
    }
    std::string extraInput;
    if ((std::cin >> extraInput) || !std::isfinite(dividend) || !std::isfinite(divisor)) {
        std::cout << "Please enter two finite numbers.\n";
        return 0;
    }

    try {
        if (divisor == 0) {
            throw std::runtime_error("Division by zero is not allowed.");
        }
        std::cout << std::fixed << std::setprecision(2)
                  << "Result: " << dividend / divisor << '\n';
    } catch (const std::runtime_error& error) {
        std::cout << error.what() << '\n';
    }
}
