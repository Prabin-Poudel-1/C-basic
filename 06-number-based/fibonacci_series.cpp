#include <iostream>

int main() {
    std::cout << "Enter the number of terms (0-93): ";

    int terms;
    if (!(std::cin >> terms)) {
        std::cout << "Please enter one whole number from 0 to 93.\n";
        return 0;
    }
    if (std::cin >> std::ws && std::cin.peek() != std::char_traits<char>::eof()) {
        std::cout << "Please enter only one whole number.\n";
        return 0;
    }
    if (terms < 0 || terms > 93) {
        std::cout << "The number of terms must be from 0 to 93.\n";
        return 0;
    }

    long long first = 0;
    long long second = 1;
    std::cout << "Fibonacci series: ";
    for (int index = 0; index < terms; ++index) {
        if (index > 0) {
            std::cout << ' ';
        }
        std::cout << first;
        if (index + 1 < terms) {
            long long next = first + second;
            first = second;
            second = next;
        }
    }
    if (terms == 0) {
        std::cout << "No terms";
    }
    std::cout << '\n';
    return 0;
}
