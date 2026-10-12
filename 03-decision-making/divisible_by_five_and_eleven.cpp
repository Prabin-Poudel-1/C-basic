#include <iostream>
#include <sstream>
#include <string>

// Check whether a signed 64-bit integer is divisible by both 5 and 11.
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

    // Both remainders must be zero; && requires both conditions.
    if (number % 5 == 0 && number % 11 == 0) {
        std::cout << "Divisible by both 5 and 11.\n";
    } else {
        std::cout << "Not divisible by both 5 and 11.\n";
    }
    return 0;
}
