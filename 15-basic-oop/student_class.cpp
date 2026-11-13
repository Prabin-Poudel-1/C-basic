#include <iostream>
#include <sstream>
#include <string>

class Student {
public:
    std::string name;
    int rollNumber;
    int age;

    void displayDetails() const {
        std::cout << "Student details:\n";
        std::cout << "Name: " << name << '\n';
        std::cout << "Roll number: " << rollNumber << '\n';
        std::cout << "Age: " << age << '\n';
    }
};

bool readPositiveInteger(const std::string& line, int& value) {
    std::istringstream input(line);
    std::string extra;
    return (input >> value) && !(input >> extra) && value > 0;
}

int main() {
    Student student;
    std::string line;

    std::cout << "Enter student name: ";
    if (!std::getline(std::cin, student.name) || student.name.empty()) {
        std::cout << "Student name cannot be empty.\n";
        return 0;
    }
    std::cout << "Enter positive roll number: ";
    if (!std::getline(std::cin, line) || !readPositiveInteger(line, student.rollNumber)) {
        std::cout << "Roll number must be a positive whole number.\n";
        return 0;
    }
    std::cout << "Enter positive age: ";
    if (!std::getline(std::cin, line) || !readPositiveInteger(line, student.age)) {
        std::cout << "Age must be a positive whole number.\n";
        return 0;
    }

    student.displayDetails();
}
