#include <iostream>
#include <sstream>
#include <string>

// Check whether a non-negative integer reads the same in reverse.
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
    if (number < 0 || (number != 0 && number % 10 == 0)) {
        std::cout << "Not a palindrome.\n";
        return 0;
    }
    long long remaining = number;
    long long reversedHalf = 0;
    while (remaining > reversedHalf) {
        reversedHalf = reversedHalf * 10 + remaining % 10;
        remaining /= 10;
    }
    bool palindrome = remaining == reversedHalf || remaining == reversedHalf / 10;
    std::cout << (palindrome ? "Palindrome.\n" : "Not a palindrome.\n");
    return 0;
}
