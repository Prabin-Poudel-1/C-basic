#include <iostream>

// Print even integers from 1 through 100 using a for loop.
int main() {
    for (int number = 2; number <= 100; number += 2) {
        std::cout << number << '\n';
    }
    return 0;
}
