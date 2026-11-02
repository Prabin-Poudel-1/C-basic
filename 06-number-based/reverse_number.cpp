#include <iostream>
#include <limits>
#include <sstream>
#include <string>

// Reverse the decimal digits of a signed 64-bit integer.
int main() {
    std::cout << "Enter a whole number: ";
    std::string line;
    std::getline(std::cin, line);
    std::istringstream input(line);
    long long number;
    char extra;
    if (!(input >> number) || (input >> extra)) {
        std::cout << "Invalid input. Enter an integer within the signed 64-bit range.\n";
        return 0;
    }
    long long remaining = number;
    long long reversed = 0;
    while (remaining != 0) {
        long long digit = remaining % 10;
        if (reversed > std::numeric_limits<long long>::max() / 10
            || (reversed == std::numeric_limits<long long>::max() / 10 && digit > 7)
            || reversed < std::numeric_limits<long long>::min() / 10
            || (reversed == std::numeric_limits<long long>::min() / 10 && digit < -8)) {
            std::cout << "Reversed number is outside the signed 64-bit range.\n";
            return 0;
        }
        reversed = reversed * 10 + digit;
        remaining /= 10;
    }
    std::cout << "Reversed: " << reversed << '\n';
    return 0;
}
