#include <iostream>

bool isPrime(int number) {
    if (number < 2) return false;
    for (int divisor = 2; divisor <= number / divisor; ++divisor) {
        if (number % divisor == 0) return false;
    }
    return true;
}

int main() {
    int number;
    std::cout << "Enter a whole number: ";
    if (!(std::cin >> number)) { std::cout << "Enter one 32-bit whole number.\n"; return 0; }
    if (std::cin >> std::ws && std::cin.peek() != std::char_traits<char>::eof()) { std::cout << "Enter only one whole number.\n"; return 0; }
    std::cout << (isPrime(number) ? "Prime number\n" : "Not a prime number\n");
}
