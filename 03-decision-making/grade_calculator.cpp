#include <cmath>
#include <iostream>
#include <sstream>
#include <string>

// Assign a letter grade to a score out of 100 using an example scale.
int main() {
    std::cout << "Enter one score out of 100: ";
    std::string line;
    std::getline(std::cin, line);
    std::istringstream input(line);
    double score;
    char extra;
    if (!(input >> score) || (input >> extra)) {
        std::cout << "Invalid input.\n";
        return 0;
    }
    if (!std::isfinite(score) || score < 0 || score > 100) {
        std::cout << "Score must be finite and between 0 and 100.\n";
        return 0;
    }

    // Descending comparisons select the first matching grade band.
    char grade;
    if (score >= 90) grade = 'A';
    else if (score >= 80) grade = 'B';
    else if (score >= 70) grade = 'C';
    else if (score >= 60) grade = 'D';
    else if (score >= 50) grade = 'E';
    else grade = 'F';
    std::cout << "Grade: " << grade << '\n';
    return 0;
}
