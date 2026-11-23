#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

struct StudentRecord {
    std::string name;
    double marks;
};

int main() {
    int count;
    std::cout << "Enter number of students (1 to 100): ";
    if (!(std::cin >> count) || count < 1 || count > 100) {
        std::cout << "Enter a whole-number count from 1 to 100.\n";
        return 0;
    }
    std::string line;
    std::getline(std::cin, line); // Consume the rest of the count line.

    std::vector<StudentRecord> records;
    for (int i = 1; i <= count; ++i) {
        std::string name;
        std::cout << "Student " << i << " name: ";
        if (!std::getline(std::cin, name)) {
            std::cout << "A student name is missing.\n";
            return 0;
        }
        std::cout << "Student " << i << " marks (0 to 100): ";
        if (!std::getline(std::cin, line)) {
            std::cout << "Student marks are missing.\n";
            return 0;
        }
        std::istringstream marksInput(line);
        double marks;
        std::string extra;
        if (!(marksInput >> marks) || (marksInput >> extra) || !std::isfinite(marks)
                || marks < 0 || marks > 100 || name.find_first_not_of(" \t\r") == std::string::npos
                || name.find(',') != std::string::npos) {
            std::cout << "Use a non-empty name without commas and marks from 0 to 100.\n";
            return 0;
        }
        records.push_back({name, marks});
    }

    std::ofstream output("student_records.txt");
    if (!output) {
        std::cout << "Could not open student_records.txt for writing.\n";
        return 0;
    }
    output.precision(15);
    for (const StudentRecord& student : records) {
        output << student.name << ',' << student.marks << '\n';
    }
    if (!output) {
        std::cout << "Could not save the records.\n";
        return 0;
    }
    output.close();
    std::cout << "Saved " << count << " student record(s) to student_records.txt\n";
}
