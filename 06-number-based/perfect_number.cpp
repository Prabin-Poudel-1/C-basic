#include <iostream>

int main() {
    std::cout << "Enter a positive whole number: ";
    int number;
    if (!(std::cin >> number)) {
        std::cout << "Please enter one 32-bit whole number.\n";
        return 0;
    }
    if (std::cin >> std::ws && std::cin.peek() != std::char_traits<char>::eof()) {
        std::cout << "Please enter only one whole number.\n";
        return 0;
    }

    long long divisorSum = 0;
    if (number > 1) {
        divisorSum = 1;
        for (int divisor = 2; divisor <= number / divisor; ++divisor) {
            if (number % divisor == 0) {
                divisorSum += divisor;
                int pairedDivisor = number / divisor;
                if (pairedDivisor != divisor) {
                    divisorSum += pairedDivisor;
                }
            }
        }
    }
    std::cout << (number > 1 && divisorSum == number
                      ? "Perfect number\n" : "Not a perfect number\n");
    return 0;
}
