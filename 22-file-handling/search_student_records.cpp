#include <fstream>
#include <iostream>
#include <string>

int main() {
    std::ifstream file("student_records.txt");
    if (!file) {
        std::cout << "Could not open student_records.txt for reading.\n";
        return 0;
    }

    std::string wantedName;
    std::cout << "Enter student name to search: ";
    if (!std::getline(std::cin, wantedName) || wantedName.find_first_not_of(" \t\r") == std::string::npos) {
        std::cout << "A student name is required.\n";
        return 0;
    }

    std::string record;
    bool found = false;
    int lineNumber = 0;
    while (std::getline(file, record)) {
        ++lineNumber;
        const std::size_t separator = record.rfind(',');
        if (separator == std::string::npos || separator == 0 || separator + 1 == record.size()) {
            std::cout << "Skipping malformed record on line " << lineNumber << ".\n";
            continue;
        }
        const std::string name = record.substr(0, separator);
        const std::string marks = record.substr(separator + 1);
        if (name == wantedName) {
            std::cout << "Found: " << name << ", marks " << marks << '\n';
            found = true;
        }
    }
    if (!file.eof()) {
        std::cout << "An error occurred while reading the file.\n";
        return 0;
    }
    if (!found) {
        std::cout << "Student not found.\n";
    }
}
