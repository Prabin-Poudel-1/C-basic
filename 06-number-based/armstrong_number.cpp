#include <iostream>
#include <sstream>
#include <string>

// Check whether a non-negative integer equals the sum of its digit powers.
int main() {
    std::cout << "Enter a non-negative whole number: ";
    std::string line;
    std::getline(std::cin, line);
    std::istringstream input(line);
    long long number;
    char extra;
    if (!(input >> number) || (input >> extra)) {
        std::cout << "Invalid input. Enter an integer within the signed 64-bit range.\n";
        return 0;
    }
    if (number < 0) {
        std::cout << "Number must be non-negative.\n";
        return 0;
    }
    int digits = 0;
    long long countCopy = number;
    do {
        digits++;
        countCopy /= 10;
    } while (countCopy != 0);

    long long sum = 0;
    long long remaining = number;
    do {
        int digit = static_cast<int>(remaining % 10);
        long long power = 1;
        for (int i = 0; i < digits; i++) {
            if (digit != 0 && power > number / digit) {
                std::cout << "Not an Armstrong number.\n";
                return 0;
            }
            power *= digit;
        }
        if (power > number - sum) {
            std::cout << "Not an Armstrong number.\n";
            return 0;
        }
        sum += power;
        remaining /= 10;
    } while (remaining != 0);
    std::cout << (sum == number ? "Armstrong number.\n" : "Not an Armstrong number.\n");
    return 0;
}
