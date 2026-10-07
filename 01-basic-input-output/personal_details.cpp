#include <iostream>
#include <string>
#include <limits>

// Read name, age, and address.
int main() {
    std::string name, address;
    int age;
    std::cout << "Name: ";
    std::getline(std::cin, name);
    std::cout << "Age: ";
    if (!(std::cin >> age)) {
        std::cout << "Invalid input.\n";
        return 0;
    }
    if (age < 0) {
        std::cout << "Age cannot be negative.\n";
        return 0;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Address: ";
    std::getline(std::cin, address);
    std::cout << "Name: " << name << "\nAge: " << age
              << "\nAddress: " << address << '\n';
    return 0;
}
