#include <iostream>
#include <sstream>
#include <string>

int main() {
    const int capacity = 5;
    int queue[capacity];
    int front = 0;
    int rear = -1;
    std::string choice;

    while (true) {
        std::cout << "1. Enqueue  2. Dequeue  3. Display  0. Exit\n";
        std::cout << "Choice: ";
        if (!std::getline(std::cin, choice)) {
            break;
        }
        if (choice == "0") {
            break;
        } else if (choice == "1") {
            if (rear == capacity - 1) {
                std::cout << "Queue is full.\n";
                continue;
            }
            std::string line;
            std::cout << "Integer to enqueue: ";
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
            queue[++rear] = value;
            std::cout << "Enqueued " << value << ".\n";
        } else if (choice == "2") {
            if (rear < front) {
                std::cout << "Queue is empty.\n";
            } else {
                std::cout << "Dequeued " << queue[front++] << ".\n";
                if (front > rear) {
                    front = 0;
                    rear = -1;
                }
            }
        } else if (choice == "3") {
            if (rear < front) {
                std::cout << "Queue is empty.\n";
            } else {
                std::cout << "Front to rear: ";
                for (int i = front; i <= rear; ++i) {
                    std::cout << queue[i] << (i == rear ? "" : " ");
                }
                std::cout << '\n';
            }
        } else {
            std::cout << "Choose 1, 2, 3, or 0.\n";
        }
    }
}
