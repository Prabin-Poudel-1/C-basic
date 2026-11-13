#include <iostream>
#include <sstream>
#include <string>

struct Student {
    std::string name;
    int rollNumber;
    int age;
};

bool readPositiveInteger(const std::string& line, int& value) {
    std::istringstream input(line);
    std::string extra;
    return (input >> value) && !(input >> extra) && value > 0;
}

int main() {
    Student students[100];
    std::string line;
    int count;

    std::cout << "Enter number of students (1-100): ";
    if (!std::getline(std::cin, line)) {
        std::cout << "Student count must be a whole number from 1 to 100.\n";
        return 0;
    }
    std::istringstream countInput(line);
    std::string extra;
    if (!(countInput >> count) || (countInput >> extra) || count < 1 || count > 100) {
        std::cout << "Student count must be a whole number from 1 to 100.\n";
        return 0;
    }

    for (int i = 0; i < count; ++i) {
        std::cout << "Enter name for student " << i + 1 << ": ";
        if (!std::getline(std::cin, students[i].name) || students[i].name.empty()) {
            std::cout << "Student name cannot be empty.\n";
            return 0;
        }

        std::cout << "Enter positive roll number: ";
        if (!std::getline(std::cin, line) || !readPositiveInteger(line, students[i].rollNumber)) {
            std::cout << "Roll number must be a positive whole number.\n";
            return 0;
        }

        std::cout << "Enter positive age: ";
        if (!std::getline(std::cin, line) || !readPositiveInteger(line, students[i].age)) {
            std::cout << "Age must be a positive whole number.\n";
            return 0;
        }
    }

    std::cout << "Student records:\n";
    for (int i = 0; i < count; ++i) {
        std::cout << "Name: " << students[i].name << '\n';
        std::cout << "Roll number: " << students[i].rollNumber << '\n';
        std::cout << "Age: " << students[i].age << "\n\n";
    }
}
