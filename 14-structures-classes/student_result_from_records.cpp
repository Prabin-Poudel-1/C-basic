#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

struct StudentRecord {
    std::string name;
    int rollNumber;
    int marks[3];
};

bool readIntegerLine(const std::string& line, int& value) {
    std::istringstream input(line);
    std::string extra;
    return (input >> value) && !(input >> extra);
}

int main() {
    StudentRecord records[100];
    std::string line;
    int count;

    std::cout << "Enter number of students (1-100): ";
    if (!std::getline(std::cin, line) || !readIntegerLine(line, count) || count < 1 || count > 100) {
        std::cout << "Student count must be a whole number from 1 to 100.\n";
        return 0;
    }

    for (int i = 0; i < count; ++i) {
        std::cout << "Enter name for student " << i + 1 << ": ";
        if (!std::getline(std::cin, records[i].name) || records[i].name.empty()) {
            std::cout << "Student name cannot be empty.\n";
            return 0;
        }
        std::cout << "Enter positive roll number: ";
        if (!std::getline(std::cin, line) || !readIntegerLine(line, records[i].rollNumber) || records[i].rollNumber < 1) {
            std::cout << "Roll number must be a positive whole number.\n";
            return 0;
        }
        for (int subject = 0; subject < 3; ++subject) {
            std::cout << "Enter marks for subject " << subject + 1 << " (0-100): ";
            if (!std::getline(std::cin, line) || !readIntegerLine(line, records[i].marks[subject]) ||
                records[i].marks[subject] < 0 || records[i].marks[subject] > 100) {
                std::cout << "Marks must be a whole number from 0 to 100.\n";
                return 0;
            }
        }
    }

    std::cout << "Student results:\n";
    for (int i = 0; i < count; ++i) {
        int total = 0;
        bool passed = true;
        for (int mark : records[i].marks) {
            total += mark;
            if (mark < 40) {
                passed = false;
            }
        }
        const double average = total / 3.0;
        std::cout << "Name: " << records[i].name << '\n';
        std::cout << "Roll number: " << records[i].rollNumber << '\n';
        std::cout << "Total marks: " << total << "/300\n";
        std::cout << "Average: " << std::fixed << std::setprecision(2) << average << "%\n";
        std::cout << "Result: " << (passed ? "Pass" : "Fail") << "\n\n";
    }
}
