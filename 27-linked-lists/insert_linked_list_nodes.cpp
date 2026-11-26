#include <iostream>
#include <new>
#include <sstream>
#include <string>

struct Node {
    int value;
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
    Node* head = nullptr;
    std::string choice;
    while (true) {
        std::cout << "1. Insert at beginning  2. Insert at end  3. Display  0. Exit\n";
        std::cout << "Choice: ";
        if (!std::getline(std::cin, choice)) {
            break;
        }
        if (choice == "0") {
            break;
        } else if (choice == "1" || choice == "2") {
            std::string line;
            std::cout << "Integer value: ";
            if (!std::getline(std::cin, line)) {
                break;
            }
            std::istringstream valueInput(line);
            int value;
            std::string extra;
            if (!(valueInput >> value) || (valueInput >> extra)) {
                std::cout << "Enter a whole number.\n";
                continue;
            }
            Node* node = new (std::nothrow) Node{value, nullptr};
            if (node == nullptr) {
                std::cout << "Could not allocate a list node.\n";
                continue;
            }
            if (choice == "1" || head == nullptr) {
                node->next = head;
                head = node;
            } else {
                Node* tail = head;
                while (tail->next != nullptr) {
                    tail = tail->next;
                }
                tail->next = node;
            }
            std::cout << "Inserted " << value << ".\n";
        } else if (choice == "3") {
            if (head == nullptr) {
                std::cout << "List is empty.\n";
            } else {
                std::cout << "List: ";
                for (Node* current = head; current != nullptr; current = current->next) {
                    std::cout << current->value << (current->next == nullptr ? "" : " -> ");
                }
                std::cout << " -> null\n";
            }
        } else {
            std::cout << "Choose 1, 2, 3, or 0.\n";
        }
    }
    deleteList(head);
}
