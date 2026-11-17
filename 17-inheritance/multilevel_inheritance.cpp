#include <iostream>
#include <string>
class Person{public:std::string name;void showPerson()const{std::cout<<"Name: "<<name<<'\n';}};
class Employee:public Person{public:int id;void showEmployee()const{showPerson();std::cout<<"Employee ID: "<<id<<'\n';}};
class Manager:public Employee{public:std::string department;void show()const{showEmployee();std::cout<<"Department: "<<department<<'\n';}};
int main(){Manager m;std::string line;std::cout<<"Name: ";if(!std::getline(std::cin,m.name)||m.name.empty())return 0;std::cout<<"ID: ";if(!(std::cin>>m.id)||m.id<1){std::cout<<"ID must be positive.\n";return 0;}std::cin.ignore(10000,'\n');std::cout<<"Department: ";std::getline(std::cin,m.department);if(m.department.empty()){std::cout<<"Department is required.\n";return 0;}m.show();}
