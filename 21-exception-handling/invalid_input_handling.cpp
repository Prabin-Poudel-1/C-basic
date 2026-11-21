#include <iostream>
#include <string>

int main() {
    int first, second;
    std::cout << "Enter two whole numbers: ";
    if (!(std::cin >> first >> second)) {
        std::cout << "Please enter two whole numbers.\n";
        return 0;
    }
    std::string extraInput;
    if (std::cin >> extraInput) {
        std::cout << "Enter exactly two whole numbers.\n";
        return 0;
    }

    std::cout << "Sum: " << (static_cast<long long>(first) + second) << '\n';
}
