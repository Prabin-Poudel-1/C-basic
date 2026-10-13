#include <iostream>
#include <sstream>
#include <string>

// Map 1 (Monday) through 7 (Sunday) to a day name using switch.
int main() {
    std::cout << "Enter a day number (1 = Monday, 7 = Sunday): ";
    std::string line;
    std::getline(std::cin, line);
    std::istringstream input(line);
    int number;
    char extra;
    if (!(input >> number) || (input >> extra)) {
        std::cout << "Invalid input. Enter one whole-number day.\n";
        return 0;
    }

    std::string day;
    switch (number) {
        case 1: day = "Monday"; break;
        case 2: day = "Tuesday"; break;
        case 3: day = "Wednesday"; break;
        case 4: day = "Thursday"; break;
        case 5: day = "Friday"; break;
        case 6: day = "Saturday"; break;
        case 7: day = "Sunday"; break;
        default:
            std::cout << "Day number must be between 1 and 7.\n";
            return 0;
    }
    std::cout << day << '\n';
    return 0;
}
