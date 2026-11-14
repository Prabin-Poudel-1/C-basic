#include <iostream>
#include <sstream>
#include <string>

class Student {
private:
    std::string name;
    int age = 0;

public:
    const std::string& getName() const {
        return name;
    }

    bool setName(const std::string& value) {
        if (value.empty()) {
            return false;
        }
        name = value;
        return true;
    }

    int getAge() const {
        return age;
    }

    bool setAge(int value) {
        if (value < 1) {
            return false;
        }
        age = value;
        return true;
    }
};

bool readInteger(const std::string& line, int& value) {
    std::istringstream input(line);
    std::string extra;
    return (input >> value) && !(input >> extra);
}

int main() {
    Student student;
    std::string line;
    std::cout << "Enter student name: ";
    if (!std::getline(std::cin, line) || !student.setName(line)) {
        std::cout << "Name cannot be empty.\n";
        return 0;
    }
    std::cout << "Enter positive age: ";
    int age;
    if (!std::getline(std::cin, line) || !readInteger(line, age) || !student.setAge(age)) {
        std::cout << "Age must be a positive whole number.\n";
        return 0;
    }

    std::cout << "Student details:\n";
    std::cout << "Name: " << student.getName() << '\n';
    std::cout << "Age: " << student.getAge() << '\n';
}
