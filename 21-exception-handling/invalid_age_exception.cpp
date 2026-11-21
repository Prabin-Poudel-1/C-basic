#include <iostream>
#include <stdexcept>

int main() {
    int age;
    std::cout << "Enter age (0 to 130): ";
    if (!(std::cin >> age)) {
        std::cout << "Age must be a whole number.\n";
        return 0;
    }

    char extraInput;
    if (std::cin >> extraInput) {
        std::cout << "Enter one whole-number age only.\n";
        return 0;
    }

    try {
        if (age < 0 || age > 130) {
            throw std::out_of_range("Age must be between 0 and 130.");
        }
        std::cout << "Age accepted: " << age << '\n';
    } catch (const std::out_of_range& error) {
        std::cout << error.what() << '\n';
    }
}
