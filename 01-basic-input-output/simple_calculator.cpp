#include <iostream>
#include <string>
#include <cmath>

// Calculate with +, -, *, /, and %.
int main() {
    double first, second, result;
    std::string operation;
    std::cout << "Enter an expression (example: 8 + 2): ";
    if (!(std::cin >> first >> operation >> second)) {
        std::cout << "Invalid input.\n";
        return 0;
    }
    if (operation == "+") result = first + second;
    else if (operation == "-") result = first - second;
    else if (operation == "*") result = first * second;
    else if (operation == "/" || operation == "%") {
        if (second == 0) {
            std::cout << "Cannot divide by zero.\n";
            return 0;
        }
        result = operation == "/" ? first / second : std::fmod(first, second);
    } else {
        std::cout << "Unsupported operator.\n";
        return 0;
    }
    std::cout << "Result: " << result << '\n';
    return 0;
}
