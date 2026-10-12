#include <iostream>
#include <sstream>
#include <string>

// Practice an age-only eligibility check with a threshold of 18.
int main() {
    std::cout << "Enter age in whole years: ";
    std::string line;
    std::getline(std::cin, line);
    std::istringstream input(line);
    long long age;
    char extra;
    if (!(input >> age) || (input >> extra)) {
        std::cout << "Invalid input. Enter one whole age within the signed 64-bit range.\n";
        return 0;
    }

    if (age < 0) {
        std::cout << "Age cannot be negative.\n";
        return 0;
    }

    // Example exercise rule: eligible by age when at least 18.
    const int minimumAge = 18;
    if (age >= minimumAge) {
        std::cout << "Eligible by age.\n";
    } else {
        std::cout << "Not eligible by age.\n";
    }
    return 0;
}
