#include <iostream>
#include <sstream>
#include <string>

// Map 1 (January) through 12 (December) to a month name using switch.
int main() {
    std::cout << "Enter a month number (1 = January, 12 = December): ";
    std::string line;
    std::getline(std::cin, line);
    std::istringstream input(line);
    int number;
    char extra;
    if (!(input >> number) || (input >> extra)) {
        std::cout << "Invalid input. Enter one whole-number month.\n";
        return 0;
    }

    std::string month;
    switch (number) {
        case 1: month = "January"; break;
        case 2: month = "February"; break;
        case 3: month = "March"; break;
        case 4: month = "April"; break;
        case 5: month = "May"; break;
        case 6: month = "June"; break;
        case 7: month = "July"; break;
        case 8: month = "August"; break;
        case 9: month = "September"; break;
        case 10: month = "October"; break;
        case 11: month = "November"; break;
        case 12: month = "December"; break;
        default:
            std::cout << "Month number must be between 1 and 12.\n";
            return 0;
    }
    std::cout << month << '\n';
    return 0;
}
