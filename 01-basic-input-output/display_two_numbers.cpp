#include <iostream>

// Input and display two numbers.
int main() {
    double first, second;
    std::cout << "Enter two numbers: ";
    if (!(std::cin >> first >> second)) {
        std::cout << "Invalid input.\n";
        return 0;
    }
    std::cout << "First number: " << first << "\nSecond number: " << second << '\n';
    return 0;
}
