#include <iostream>

long long factorial(int number) {
    long long result = 1;
    for (int factor = 2; factor <= number; ++factor) result *= factor;
    return result;
}

int main() {
    int number;
    std::cout << "Enter a whole number from 0 to 20: ";
    if (!(std::cin >> number) || (std::cin >> std::ws && std::cin.peek() != std::char_traits<char>::eof()) || number < 0 || number > 20) { std::cout << "Number must be from 0 to 20.\n"; return 0; }
    std::cout << "Factorial: " << factorial(number) << '\n';
}
