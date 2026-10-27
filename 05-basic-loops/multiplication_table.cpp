#include <iostream>
#include <sstream>
#include <string>

// Print the first ten multiples of an integer.
int main() {
    constexpr long long maxAbsValue = 922337203685477580LL;
    std::cout << "Enter an integer from -" << maxAbsValue << " to " << maxAbsValue << ": ";
    std::string line;
    std::getline(std::cin, line);
    std::istringstream input(line);
    long long number;
    char extra;
    if (!(input >> number) || (input >> extra)) {
        std::cout << "Invalid input. Enter one whole number.\n";
        return 0;
    }
    if (number < -maxAbsValue || number > maxAbsValue) {
        std::cout << "Number is outside the safe table range.\n";
        return 0;
    }
    for (int multiplier = 1; multiplier <= 10; multiplier++) {
        std::cout << number << " x " << multiplier << " = " << number * multiplier << '\n';
    }
    return 0;
}
