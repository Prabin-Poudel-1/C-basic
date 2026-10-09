#include <iostream>
#include <sstream>
#include <string>

// Split a non-negative number of seconds into hours, minutes, and seconds.
int main() {
    std::cout << "Enter total seconds (whole number): ";
    std::string line;
    std::getline(std::cin, line);
    std::istringstream input(line);
    long long totalSeconds;
    char extra;
    if (!(input >> totalSeconds) || (input >> extra)) {
        std::cout << "Invalid input. Enter one whole number within the 64-bit signed range.\n";
        return 0;
    }
    if (totalSeconds < 0) {
        std::cout << "Seconds cannot be negative.\n";
        return 0;
    }

    // Division gives whole units; remainder keeps the unconverted part.
    long long hours = totalSeconds / 3600;
    long long minutes = (totalSeconds % 3600) / 60;
    long long seconds = totalSeconds % 60;
    std::cout << "Hours: " << hours << "\nMinutes: " << minutes << "\nSeconds: " << seconds << '\n';
    return 0;
}
