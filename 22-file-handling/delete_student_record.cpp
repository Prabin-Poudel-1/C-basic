#include <cstdio>
#include <fstream>
#include <iostream>
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
    std::string record;
    while (std::getline(inputFile, record)) {
        records.push_back(record);
    }
    if (!inputFile.eof()) {
        std::cout << "An error occurred while reading the file.\n";
        return 0;
    }
    inputFile.close();

    std::string wantedName;
    std::cout << "Enter student name to delete: ";
    if (!std::getline(std::cin, wantedName)
            || wantedName.find_first_not_of(" \t\r") == std::string::npos) {
        std::cout << "A student name is required; the file was not changed.\n";
        return 0;
    }
    if (std::string extra; std::getline(std::cin, extra)
            && extra.find_first_not_of(" \t\r") != std::string::npos) {
        std::cout << "Enter exactly one student name; the file was not changed.\n";
        return 0;
    }

    bool found = false;
    for (auto it = records.begin(); it != records.end(); ++it) {
        const std::size_t separator = it->rfind(',');
        if (separator != std::string::npos && separator > 0
                && it->substr(0, separator) == wantedName) {
            records.erase(it);
            found = true;
            break;
        }
    }
    if (!found) {
        std::cout << "Student not found; the file was not changed.\n";
        return 0;
    }

    const std::string temporaryName = fileName + ".tmp";
    std::ofstream outputFile(temporaryName);
    if (!outputFile) {
        std::cout << "Could not create a temporary file for updating.\n";
        return 0;
    }
    for (const std::string& remainingRecord : records) {
        outputFile << remainingRecord << '\n';
    }
    outputFile.close();
    if (!outputFile) {
        std::remove(temporaryName.c_str());
        std::cout << "An error occurred while writing the updated records.\n";
        return 0;
    }
    if (std::rename(temporaryName.c_str(), fileName.c_str()) != 0) {
        std::remove(temporaryName.c_str());
        std::cout << "Could not replace student_records.txt.\n";
        return 0;
    }
    std::cout << "Deleted record for " << wantedName << ".\n";
}
