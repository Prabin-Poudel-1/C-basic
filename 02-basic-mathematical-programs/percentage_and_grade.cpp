#include <cmath>
#include <iomanip>
#include <iostream>

// Calculate a percentage and assign a grade using an example practice scale.
int main() {
    double obtained, maximum;
    std::cout << "Enter obtained marks and maximum marks: ";
    if (!(std::cin >> obtained >> maximum)) {
        std::cout << "Invalid input.\n";
        return 0;
    }
    if (!std::isfinite(obtained) || !std::isfinite(maximum)
        || maximum <= 0 || obtained < 0 || obtained > maximum) {
        std::cout << "Maximum marks must be positive; obtained marks must be between 0 and maximum. Both must be finite.\n";
        return 0;
    }

    double percentage = (obtained / maximum) * 100;
    // Practice scale: A >= 90, B >= 80, C >= 70, D >= 60, E >= 50; otherwise F.
    char grade;
    if (percentage >= 90) grade = 'A';
    else if (percentage >= 80) grade = 'B';
    else if (percentage >= 70) grade = 'C';
    else if (percentage >= 60) grade = 'D';
    else if (percentage >= 50) grade = 'E';
    else grade = 'F';

    std::cout << std::fixed << std::setprecision(2)
              << "Percentage: " << percentage << "%\nGrade: " << grade << '\n';
    return 0;
}
