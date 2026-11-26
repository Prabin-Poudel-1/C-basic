#include <iostream>
#include <new>
#include <sstream>
#include <string>

struct Node {
    int value;
    Node* previous;
    Node* next;
};

void deleteList(Node* head) {
    while (head != nullptr) {
        Node* next = head->next;
        delete head;
        head = next;
    }
}

int main() {
    std::string line;
    std::cout << "Number of values (0 to 100): ";
    if (!std::getline(std::cin, line)) {
        std::cout << "A count is required.\n";
        return 0;
    }
    std::istringstream countInput(line);
    int count;
    std::string extra;
    if (!(countInput >> count) || (countInput >> extra) || count < 0 || count > 100) {
        std::cout << "Enter a whole number from 0 to 100.\n";
        return 0;
    }

    Node* head = nullptr;
    Node* tail = nullptr;
    for (int i = 0; i < count; ++i) {
        std::cout << "Value " << (i + 1) << ": ";
        if (!std::getline(std::cin, line)) {
            std::cout << "List input ended early.\n";
            deleteList(head);
            return 0;
        }
        std::istringstream valueInput(line);
        int value;
        if (!(valueInput >> value) || (valueInput >> extra)) {
            std::cout << "Enter a whole number for every list value.\n";
            deleteList(head);
            return 0;
        }
        Node* node = new (std::nothrow) Node{value, tail, nullptr};
        if (node == nullptr) {
            std::cout << "Could not allocate a list node.\n";
            deleteList(head);
            return 0;
        }
        if (tail == nullptr) {
            head = node;
        } else {
            tail->next = node;
        }
        tail = node;
    }

    if (head == nullptr) {
        std::cout << "The list is empty.\n";
    } else {
        std::cout << "Forward: ";
        for (Node* current = head; current != nullptr; current = current->next) {
            std::cout << current->value << (current->next == nullptr ? "" : " <-> ");
        }
        std::cout << '\n' << "Backward: ";
        for (Node* current = tail; current != nullptr; current = current->previous) {
            std::cout << current->value << (current->previous == nullptr ? "" : " <-> ");
        }
        std::cout << '\n';
    }
    deleteList(head);
}
