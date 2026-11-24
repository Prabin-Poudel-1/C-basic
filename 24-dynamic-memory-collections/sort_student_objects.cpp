#include <algorithm>
#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

struct Student {
    std::string name;
    double marks;
};

int main() {
    std::string line;
    std::cout << "Number of students (0 to 100): ";
    if (!std::getline(std::cin, line)) {
        std::cout << "A student count is required.\n";
        return 0;
    }
    std::istringstream countInput(line);
    int count;
    std::string extra;
    if (!(countInput >> count) || (countInput >> extra) || count < 0 || count > 100) {
        std::cout << "Enter a whole number from 0 to 100.\n";
        return 0;
    }

    std::vector<Student> students;
    for (int i = 0; i < count; ++i) {
        std::string name;
        std::cout << "Student " << (i + 1) << " name: ";
        if (!std::getline(std::cin, name)
                || name.find_first_not_of(" \t\r") == std::string::npos) {
            std::cout << "Each student needs a name and marks from 0 to 100.\n";
            return 0;
        }
        const std::size_t first = name.find_first_not_of(" \t\r");
        const std::size_t last = name.find_last_not_of(" \t\r");
        name = name.substr(first, last - first + 1);

        std::cout << "Marks (0 to 100): ";
        if (!std::getline(std::cin, line)) {
            std::cout << "Marks must be a number from 0 to 100.\n";
            return 0;
        }
        std::istringstream marksInput(line);
        double marks;
        if (!(marksInput >> marks) || (marksInput >> extra) || !std::isfinite(marks)
                || marks < 0 || marks > 100) {
            std::cout << "Marks must be a number from 0 to 100.\n";
            return 0;
        }
        students.push_back({name, marks});
    }
    if (std::getline(std::cin, line) && line.find_first_not_of(" \t\r") != std::string::npos) {
        std::cout << "Unexpected extra input.\n";
        return 0;
    }

    std::sort(students.begin(), students.end(), [](const Student& first, const Student& second) {
        if (first.marks != second.marks) {
            return first.marks < second.marks;
        }
        return first.name < second.name;
    });
    std::cout << "Students sorted by marks (lowest first):\n";
    for (const Student& student : students) {
        std::cout << student.name << ", marks " << student.marks << '\n';
    }
}
