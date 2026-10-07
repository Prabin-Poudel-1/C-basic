#include <iostream>

// Swap two numbers using a temporary variable.
int main() {
    double first, second;
    std::cout << "Enter two numbers: ";
    if (!(std::cin >> first >> second)) {
        std::cout << "Invalid input.\n";
        return 0;
    }
    std::cout << "Before swap: " << first << ' ' << second << '\n';
    double temporary = first;
    first = second;
    second = temporary;
    std::cout << "After swap: " << first << ' ' << second << '\n';
    return 0;
}
