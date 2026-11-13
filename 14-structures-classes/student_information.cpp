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
    if (!(input >> value) || (input >> extra)) {
        return false;
    }
    return value > 0;
}

int main() {
    Student student;
    std::string line;

    std::cout << "Enter student name: ";
    if (!std::getline(std::cin, student.name) || student.name.find_first_not_of(' ') == std::string::npos) {
        std::cout << "A name is required.\n";
        return 0;
    }

    std::cout << "Enter roll number: ";
    if (!std::getline(std::cin, line) || !readPositiveInteger(line, student.rollNumber)) {
        std::cout << "Roll number and age must be positive whole numbers.\n";
        return 0;
    }
    std::cout << "Enter age: ";
    if (!std::getline(std::cin, line) || !readPositiveInteger(line, student.age)) {
        std::cout << "Roll number and age must be positive whole numbers.\n";
        return 0;
    }

    std::cout << "Student information:\n";
    std::cout << "Name: " << student.name << '\n';
    std::cout << "Roll number: " << student.rollNumber << '\n';
    std::cout << "Age: " << student.age << '\n';
}
