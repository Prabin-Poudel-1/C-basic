#include <exception>
#include <iostream>

class InvalidAgeException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Age must be between 0 and 130.";
    }
};

void validateAge(int age) {
    if (age < 0 || age > 130) {
        throw InvalidAgeException();
    }
}

int main() {
    int age;
    std::cout << "Enter age: ";
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
        validateAge(age);
        std::cout << "Valid age: " << age << '\n';
    } catch (const InvalidAgeException& error) {
        std::cout << error.what() << '\n';
    }
}
