#include <iostream>
#include <string>
class Animal {public:std::string name;void describe()const{std::cout<<"Animal: "<<name<<'\n';}};
class Dog:public Animal {public:std::string breed;void show()const{describe();std::cout<<"Breed: "<<breed<<"\nSound: Woof!\n";}};
int main(){Dog d;std::cout<<"Animal name: ";if(!std::getline(std::cin,d.name)||d.name.empty()){std::cout<<"Name and breed are required.\n";return 0;}std::cout<<"Breed: ";if(!std::getline(std::cin,d.breed)||d.breed.empty()){std::cout<<"Name and breed are required.\n";return 0;}d.show();}
