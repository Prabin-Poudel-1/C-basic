#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>

// Read exactly one value per line; reject trailing tokens.
template <typename T>
bool readValue(T& value) {
    std::string line;
    if (!std::getline(std::cin, line)) return false;
    std::istringstream input(line);
    char extra;
    return (input >> value) && !(input >> extra);
}

// Repeated arithmetic operations selected with a switch menu.
int main() {
    std::cout << std::setprecision(std::numeric_limits<double>::max_digits10);
    while (true) {
        std::cout << "1. Add\n2. Subtract\n3. Multiply\n4. Divide\n5. Remainder\n0. Exit\nChoice: ";
        int choice;
        if (!readValue(choice)) {
            std::cout << "Invalid input.\n";
            return 0;
        }
        if (choice == 0) {
            std::cout << "Goodbye.\n";
            return 0;
        }
        if (choice < 1 || choice > 5) {
            std::cout << "Invalid choice.\n";
            continue;
        }
        double first, second;
        std::cout << "First number: ";
        if (!readValue(first)) {
            std::cout << "Invalid input.\n";
            return 0;
        }
        std::cout << "Second number: ";
        if (!readValue(second)) {
            std::cout << "Invalid input.\n";
            return 0;
        }
        if (!std::isfinite(first) || !std::isfinite(second)) {
            std::cout << "Enter finite numbers.\n";
            return 0;
        }
        if ((choice == 4 || choice == 5) && second == 0) {
            std::cout << "Cannot divide by zero.\n";
            continue;
        }

        double result;
        switch (choice) {
            case 1: result = first + second; break;
            case 2: result = first - second; break;
            case 3: result = first * second; break;
            case 4: result = first / second; break;
            case 5: result = std::fmod(first, second); break;
            default: return 1;
        }
        if (!std::isfinite(result)) {
            std::cout << "Result is too large.\n";
            continue;
        }
        std::cout << "Result: " << result << '\n';
    }
}
