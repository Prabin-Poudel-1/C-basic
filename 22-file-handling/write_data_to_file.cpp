#include <fstream>
#include <iostream>
#include <string>

int main() {
    std::string data;
    std::cout << "Enter a line to save: ";
    if (!std::getline(std::cin, data)) {
        std::cout << "No line was provided.\n";
        return 0;
    }

    const std::string fileName = "practice_data.txt";
    std::ofstream output(fileName);
    if (!output) {
        std::cout << "Could not open the file for writing.\n";
        return 0;
    }
    output << data << '\n';
    if (!output) {
        std::cout << "Could not write the file.\n";
        return 0;
    }
    output.close();
    std::cout << "Saved data to: " << fileName << '\n';
}
