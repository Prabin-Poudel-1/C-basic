#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

struct Student {
    std::string name;
    double marks;
};

std::string readName(const std::string& prompt) {
    std::string name;
    std::cout << prompt;
    std::getline(std::cin, name);
    const std::size_t first = name.find_first_not_of(" \t\r");
    if (first == std::string::npos) {
        return "";
    }
    const std::size_t last = name.find_last_not_of(" \t\r");
    return name.substr(first, last - first + 1);
}

void addStudent(std::vector<Student>& students) {
    const std::string name = readName("Student name: ");
    if (name.empty() || name.find(',') != std::string::npos) {
        std::cout << "Name must be non-empty and cannot contain a comma.\n";
        return;
    }

    std::string line;
    std::cout << "Marks (0 to 100): ";
    if (!std::getline(std::cin, line)) {
        return;
    }
    std::istringstream marksInput(line);
    double marks;
    std::string extra;
    if (!(marksInput >> marks) || (marksInput >> extra) || !std::isfinite(marks)
            || marks < 0 || marks > 100) {
        std::cout << "Marks must be a number from 0 to 100.\n";
        return;
    }
    students.push_back({name, marks});
    std::cout << "Student added.\n";
}

void listStudents(const std::vector<Student>& students) {
    if (students.empty()) {
        std::cout << "No students stored.\n";
        return;
    }
    for (const Student& student : students) {
        std::cout << student.name << ", marks " << student.marks << '\n';
    }
}

void searchStudent(const std::vector<Student>& students) {
    const std::string wantedName = readName("Name to search: ");
    for (const Student& student : students) {
        if (student.name == wantedName) {
            std::cout << "Found: " << student.name << ", marks " << student.marks << '\n';
            return;
        }
    }
    std::cout << "Student not found.\n";
}

void deleteStudent(std::vector<Student>& students) {
    const std::string wantedName = readName("Name to delete: ");
    for (auto it = students.begin(); it != students.end(); ++it) {
        if (it->name == wantedName) {
            students.erase(it);
            std::cout << "Student deleted.\n";
            return;
        }
    }
    std::cout << "Student not found.\n";
}

int main() {
    std::vector<Student> students;
    std::string choice;
    while (true) {
        std::cout << "1. Add student  2. List students  3. Search  4. Delete  0. Exit\n";
        std::cout << "Choice: ";
        if (!std::getline(std::cin, choice)) {
            break;
        }
        if (choice == "0") {
            break;
        } else if (choice == "1") {
            addStudent(students);
        } else if (choice == "2") {
            listStudents(students);
        } else if (choice == "3") {
            searchStudent(students);
        } else if (choice == "4") {
            deleteStudent(students);
        } else {
            std::cout << "Choose 1, 2, 3, 4, or 0.\n";
        }
    }
}
