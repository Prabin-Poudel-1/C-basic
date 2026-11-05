#include <cstdlib>
#include <iostream>

int main() {
    int firstInput;
    int secondInput;
    std::cout << "Enter two 32-bit whole numbers: ";
    if (!(std::cin >> firstInput >> secondInput)) {
        std::cout << "Please enter two 32-bit whole numbers.\n";
        return 0;
    }
    if (std::cin >> std::ws && std::cin.peek() != std::char_traits<char>::eof()) {
        std::cout << "Please enter only two whole numbers.\n";
        return 0;
    }

    long long first = std::llabs(static_cast<long long>(firstInput));
    long long second = std::llabs(static_cast<long long>(secondInput));
    while (second != 0) {
        long long remainder = first % second;
        first = second;
        second = remainder;
    }
    std::cout << "GCD/HCF: " << first << '\n';
    return 0;
}
