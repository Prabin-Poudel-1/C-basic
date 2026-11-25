#include <iostream>
#include <sstream>
#include <string>

class CircularQueue {
private:
    static const int capacity = 5;
    int values[capacity]{};
    int front = 0;
    int size = 0;

public:
    void enqueue(int value) {
        if (size == capacity) {
            std::cout << "Queue is full.\n";
            return;
        }
        const int rear = (front + size) % capacity;
        values[rear] = value;
        ++size;
        std::cout << "Enqueued " << value << ".\n";
    }

    void dequeue() {
        if (size == 0) {
            std::cout << "Queue is empty.\n";
            return;
        }
        std::cout << "Dequeued " << values[front] << ".\n";
        front = (front + 1) % capacity;
        --size;
    }

    void display() const {
        if (size == 0) {
            std::cout << "Queue is empty.\n";
            return;
        }
        std::cout << "Front to rear: ";
        for (int i = 0; i < size; ++i) {
            const int index = (front + i) % capacity;
            std::cout << values[index] << (i == size - 1 ? "" : " ");
        }
        std::cout << '\n';
    }
};

int main() {
    CircularQueue queue;
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
            } else {
                queue.enqueue(value);
            }
        } else if (choice == "2") {
            queue.dequeue();
        } else if (choice == "3") {
            queue.display();
        } else {
            std::cout << "Choose 1, 2, 3, or 0.\n";
        }
    }
}
