#include <iostream>
#include <sstream>
#include <string>

class Student {
public:
    std::string name;
    int rollNumber;

    Student(const std::string& studentName, int studentRollNumber)
        : name(studentName), rollNumber(studentRollNumber) {}

    void display() const {
        std::cout << "Name: " << name << '\n';
        std::cout << "Roll number: " << rollNumber << '\n';
    }
};

bool readPositiveInteger(const std::string& line, int& value) {
    std::istringstream input(line);
    std::string extra;
    return (input >> value) && !(input >> extra) && value > 0;
}

int main() {
    std::string name;
    std::string line;
    int rollNumber;

    std::cout << "Enter student name: ";
    if (!std::getline(std::cin, name) || name.empty()) {
        std::cout << "Student name cannot be empty.\n";
        return 0;
    }
    std::cout << "Enter positive roll number: ";
    if (!std::getline(std::cin, line) || !readPositiveInteger(line, rollNumber)) {
        std::cout << "Roll number must be a positive whole number.\n";
        return 0;
    }

    Student student(name, rollNumber);
    student.display();
}
