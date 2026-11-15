#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

class Student {
private:
    int marks[3] = {0, 0, 0};

public:
    bool setMark(int subject, int mark) {
        if (subject < 0 || subject >= 3 || mark < 0 || mark > 100) {
            return false;
        }
        marks[subject] = mark;
        return true;
    }

    int getMark(int subject) const {
        return marks[subject];
    }

    double average() const {
        return (marks[0] + marks[1] + marks[2]) / 3.0;
    }
};

bool readInteger(const std::string& line, int& value) {
    std::istringstream input(line);
    std::string extra;
    return (input >> value) && !(input >> extra);
}

int main() {
    Student student;
    std::string line;
    for (int subject = 0; subject < 3; ++subject) {
        std::cout << "Enter marks for subject " << subject + 1 << " (0-100): ";
        int mark;
        if (!std::getline(std::cin, line) || !readInteger(line, mark) || !student.setMark(subject, mark)) {
            std::cout << "Marks must be whole numbers from 0 to 100.\n";
            return 0;
        }
    }

    std::cout << "Validated marks:\n";
    for (int subject = 0; subject < 3; ++subject) {
        std::cout << "Subject " << subject + 1 << ": " << student.getMark(subject) << '\n';
    }
    std::cout << std::fixed << std::setprecision(2) << "Average: " << student.average() << '\n';
}
