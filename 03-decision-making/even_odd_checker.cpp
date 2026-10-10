#include <iostream>
#include <sstream>
#include <string>

// Determine whether a signed 64-bit integer is even or odd.
int main() {
    std::cout << "Enter one whole number: ";
    std::string line;
    std::getline(std::cin, line);
    std::istringstream input(line);
    long long number;
    char extra;
    if (!(input >> number) || (input >> extra)) {
        std::cout << "Invalid input. Enter one integer within the signed 64-bit range.\n";
        return 0;
    }

    // A remainder of zero means the number is divisible by two.
    if (number % 2 == 0) {
        std::cout << "Even\n";
    } else {
        std::cout << "Odd\n";
    }
    return 0;
}
