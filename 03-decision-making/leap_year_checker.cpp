#include <iostream>
#include <sstream>
#include <string>

// Check whether a positive year is a leap year using the Gregorian rule.
int main() {
    std::cout << "Enter a positive year: ";
    std::string line;
    std::getline(std::cin, line);
    std::istringstream input(line);
    long long year;
    char extra;
    if (!(input >> year) || (input >> extra)) {
        std::cout << "Invalid input. Enter one whole year within the signed 64-bit range.\n";
        return 0;
    }

    if (year <= 0) {
        std::cout << "Year must be positive.\n";
        return 0;
    }

    // Century years must be divisible by 400; other years by 4.
    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
        std::cout << "Leap year\n";
    } else {
        std::cout << "Not a leap year\n";
    }
    return 0;
}
