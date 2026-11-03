#include <iostream>
#include <limits>

int main() {
    std::cout << "Enter a whole number: ";

    int number;
    if (!(std::cin >> number)) {
        std::cout << "Please enter one 32-bit whole number.\n";
        return 0;
    }
    if (std::cin >> std::ws && std::cin.peek() != std::char_traits<char>::eof()) {
        std::cout << "Please enter only one whole number.\n";
        return 0;
    }

    bool isPrime = number >= 2;
    for (int divisor = 2; isPrime && divisor <= number / divisor; ++divisor) {
        if (number % divisor == 0) {
            isPrime = false;
        }
    }

    std::cout << (isPrime ? "Prime number\n" : "Not a prime number\n");
    return 0;
}
