#include <iostream>
#include <string>

class Student {
public:
    std::string name;
    int rollNumber;

    Student() : Student("New Student", 1) {}

    Student(const std::string& studentName, int studentRollNumber)
        : name(studentName), rollNumber(studentRollNumber) {}

    void display() const {
        std::cout << "Name: " << name << ", Roll number: " << rollNumber << '\n';
    }
};

int main() {
    Student defaultStudent;
    Student namedStudent("Grace Hopper", 102);

    std::cout << "Default constructor:\n";
    defaultStudent.display();
    std::cout << "Parameterized constructor:\n";
    namedStudent.display();
}
