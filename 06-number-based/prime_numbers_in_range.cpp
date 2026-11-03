#include <iostream>
#include <limits>

bool isPrime(long long number) {
    if (number < 2) {
        return false;
    }
    for (long long divisor = 2; divisor <= number / divisor; ++divisor) {
        if (number % divisor == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    std::cout << "Enter the start and end of the range: ";

    int start;
    int end;
    if (!(std::cin >> start >> end)) {
        std::cout << "Please enter two 32-bit whole numbers.\n";
        return 0;
    }
    if (std::cin >> std::ws && std::cin.peek() != std::char_traits<char>::eof()) {
        std::cout << "Please enter only two whole numbers.\n";
        return 0;
    }
    if (start > end) {
        std::cout << "The start must not be greater than the end.\n";
        return 0;
    }

    bool foundPrime = false;
    std::cout << "Prime numbers: ";
    for (long long number = start < 2 ? 2 : start; number <= end; ++number) {
        if (isPrime(number)) {
            if (foundPrime) {
                std::cout << ' ';
            }
            std::cout << number;
            foundPrime = true;
        }
    }
    if (!foundPrime) {
        std::cout << "None";
    }
    std::cout << '\n';
    return 0;
}
