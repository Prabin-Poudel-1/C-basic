#include <iostream>
#include <string>

class Greeter {
public:
    std::string name;

    void greet() const {
        std::cout << "Hello, " << name << "!\n";
    }
};

int main() {
    Greeter greeter;
    std::cout << "Enter your name: ";
    if (!std::getline(std::cin, greeter.name) || greeter.name.empty()) {
        std::cout << "Name cannot be empty.\n";
        return 0;
    }

    // Create an object, set its data, and call its method.
    greeter.greet();
}
