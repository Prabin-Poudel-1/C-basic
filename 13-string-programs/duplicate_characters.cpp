#include <iostream>
#include <string>
#include <utility>
#include <vector>

int main() {
    std::string text;
    std::cout << "Enter a line of text: ";
    if (!std::getline(std::cin, text)) {
        std::cout << "No line was provided.\n";
        return 0;
    }

    std::vector<std::pair<char, int>> frequencies;
    for (char character : text) {
        bool alreadyCounted = false;
        for (auto& entry : frequencies) {
            if (entry.first == character) {
                ++entry.second;
                alreadyCounted = true;
                break;
            }
        }
        if (!alreadyCounted) {
            frequencies.push_back({character, 1});
        }
    }

    bool foundDuplicate = false;
    for (const auto& entry : frequencies) {
        if (entry.second > 1) {
            std::string label = entry.first == ' ' ? "(space)" : std::string(1, entry.first);
            std::cout << label << ": " << entry.second << '\n';
            foundDuplicate = true;
        }
    }
    if (!foundDuplicate) {
        std::cout << "No duplicate characters.\n";
    }
}
