#include <fstream>
#include <iostream>
#include <string>

int main() {
    std::string data;
    std::cout << "Enter a line to append: ";
    if (!std::getline(std::cin, data)) {
        std::cout << "No line was provided.\n";
        return 0;
    }

    std::ofstream output("practice_data.txt", std::ios::app);
    if (!output) {
        std::cout << "Could not open the file for appending.\n";
        return 0;
    }
    output << data << '\n';
    if (!output) {
        std::cout << "Could not append to the file.\n";
        return 0;
    }
    output.close();
    std::cout << "Appended data to: practice_data.txt\n";
}
