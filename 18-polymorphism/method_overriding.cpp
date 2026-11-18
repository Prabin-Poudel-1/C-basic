#include <iostream>

class Animal {
public:
    virtual ~Animal() = default;

    virtual void makeSound() const {
        std::cout << "Animal makes a sound.\n";
    }
};

class Dog : public Animal {
public:
    void makeSound() const override {
        std::cout << "Dog says: Woof!\n";
    }
};

int main() {
    Animal ordinaryAnimal;
    ordinaryAnimal.makeSound();

    Dog dog;
    const Animal& pet = dog;
    pet.makeSound(); // The virtual call selects Dog's override at runtime.
}
