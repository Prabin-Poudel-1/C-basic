#include <iostream>

int main() {
    std::cout << "Enter a signed whole number: ";
    long long number;
    if (!(std::cin >> number)) {
        std::cout << "Please enter one signed 64-bit whole number.\n";
        return 0;
    }
    if (std::cin >> std::ws && std::cin.peek() != std::char_traits<char>::eof()) {
        std::cout << "Please enter only one whole number.\n";
        return 0;
    }

    long long remaining = number;
    long long sum = 0;
    do {
        long long digit = remaining % 10;
        sum += digit < 0 ? -digit : digit;
        remaining /= 10;
    } while (remaining != 0);
    std::cout << "Sum of digits: " << sum << '\n';
    return 0;
}
