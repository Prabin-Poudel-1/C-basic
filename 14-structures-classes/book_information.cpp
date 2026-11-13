#include <iostream>
#include <sstream>
#include <string>

struct Book {
    std::string title;
    std::string author;
    std::string isbn;
    int pages;
};

bool readPositivePages(const std::string& line, int& pages) {
    std::istringstream input(line);
    std::string extra;
    return (input >> pages) && !(input >> extra) && pages > 0;
}

int main() {
    Book book;
    std::string line;

    std::cout << "Enter book title: ";
    if (!std::getline(std::cin, book.title) || book.title.empty()) {
        std::cout << "Title, author, and ISBN are required.\n";
        return 0;
    }
    std::cout << "Enter author: ";
    if (!std::getline(std::cin, book.author) || book.author.empty()) {
        std::cout << "Title, author, and ISBN are required.\n";
        return 0;
    }
    std::cout << "Enter ISBN: ";
    if (!std::getline(std::cin, book.isbn) || book.isbn.empty()) {
        std::cout << "Title, author, and ISBN are required.\n";
        return 0;
    }
    std::cout << "Enter page count: ";
    if (!std::getline(std::cin, line) || !readPositivePages(line, book.pages)) {
        std::cout << "Page count must be a positive whole number.\n";
        return 0;
    }

    std::cout << "Book information:\n";
    std::cout << "Title: " << book.title << '\n';
    std::cout << "Author: " << book.author << '\n';
    std::cout << "ISBN: " << book.isbn << '\n';
    std::cout << "Pages: " << book.pages << '\n';
}
