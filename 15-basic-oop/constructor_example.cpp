#include <iostream>
#include <string>

class Student {
public:
    std::string name;
    int rollNumber;

    Student() {
        name = "New Student";
        rollNumber = 1;
    }

    void display() const {
        std::cout << "Name: " << name << '\n';
        std::cout << "Roll number: " << rollNumber << '\n';
    }
};

int main() {
    Student student;
    student.display();
}
