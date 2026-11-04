#include <iostream>

int factorial(int digit) {
    int result = 1;
    for (int factor = 2; factor <= digit; ++factor) {
        result *= factor;
    }
    return result;
}

int main() {
    std::cout << "Enter a non-negative whole number: ";
    int number;
    if (!(std::cin >> number)) {
        std::cout << "Please enter one non-negative 32-bit whole number.\n";
        return 0;
    }
    if (std::cin >> std::ws && std::cin.peek() != std::char_traits<char>::eof()) {
        std::cout << "Please enter only one whole number.\n";
        return 0;
    }
    if (number < 0) {
        std::cout << "The number must be non-negative.\n";
        return 0;
    }

    int remaining = number;
    long long factorialSum = 0;
    do {
        factorialSum += factorial(remaining % 10);
        remaining /= 10;
    } while (remaining > 0);

    std::cout << (factorialSum == number
                      ? "Strong number\n" : "Not a strong number\n");
    return 0;
}
