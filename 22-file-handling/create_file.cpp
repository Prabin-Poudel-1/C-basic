#include <filesystem>
#include <fstream>
#include <iostream>

int main() {
    const std::filesystem::path file("practice_output.txt");
    std::error_code error;

    if (std::filesystem::exists(file, error)) {
        std::cout << "File already exists: " << file.string() << '\n';
        return 0;
    }
    if (error) {
        std::cout << "Could not check the file: " << error.message() << '\n';
        return 0;
    }

    std::ofstream output(file);
    if (!output) {
        std::cout << "Could not create the file: " << file.string() << '\n';
        return 0;
    }
    output.close();
    std::cout << "Created file: " << file.string() << '\n';
}
