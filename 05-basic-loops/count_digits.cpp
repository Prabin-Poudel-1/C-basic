#include <iostream>
#include <sstream>
#include <string>

// Count the base-10 digits in a signed 64-bit integer.
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
    int count = 0;
    do {
        count++;
        number /= 10;
    } while (number != 0);
    std::cout << "Digit count: " << count << '\n';
    return 0;
}
