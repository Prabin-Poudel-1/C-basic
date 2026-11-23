#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main() {
    const std::string fileName = "student_records.txt";
    std::ifstream inputFile(fileName);
    if (!inputFile) {
        std::cout << "Could not open student_records.txt for reading.\n";
        return 0;
    }

    std::vector<std::string> records;
    std::string line;
    while (std::getline(inputFile, line)) {
        records.push_back(line);
    }
    if (!inputFile.eof()) {
        std::cout << "An error occurred while reading the file.\n";
        return 0;
    }
    inputFile.close();

    std::string wantedName;
    std::cout << "Enter student name to update: ";
    if (!std::getline(std::cin, wantedName) || wantedName.find_first_not_of(" \t\r") == std::string::npos) {
        std::cout << "A student name is required.\n";
        return 0;
    }
    std::cout << "Enter new marks (0 to 100): ";
    if (!std::getline(std::cin, line)) {
        std::cout << "Enter marks from 0 to 100.\n";
        return 0;
    }
    std::istringstream marksInput(line);
    double newMarks;
    std::string extra;
    if (!(marksInput >> newMarks) || (marksInput >> extra) || !std::isfinite(newMarks)
            || newMarks < 0 || newMarks > 100) {
        std::cout << "Marks must be a number from 0 to 100.\n";
        return 0;
    }

    bool found = false;
    for (std::string& record : records) {
        const std::size_t separator = record.rfind(',');
        if (separator != std::string::npos && separator > 0
                && record.substr(0, separator) == wantedName) {
            std::ostringstream marksText;
            marksText.precision(15);
            marksText << newMarks;
            record = wantedName + "," + marksText.str();
            found = true;
            break;
        }
    }
    if (!found) {
        std::cout << "Student not found; the file was not changed.\n";
        return 0;
    }

    std::ofstream outputFile(fileName);
    if (!outputFile) {
        std::cout << "Could not open the file for updating.\n";
        return 0;
    }
    for (const std::string& record : records) {
        outputFile << record << '\n';
    }
    if (!outputFile) {
        std::cout << "An error occurred while writing the updated records.\n";
        return 0;
    }
    outputFile.close();
    std::cout << "Updated marks for " << wantedName << ".\n";
}
