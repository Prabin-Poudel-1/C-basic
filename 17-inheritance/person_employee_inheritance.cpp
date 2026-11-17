#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
class Person { public: std::string name; int age; void display() const { std::cout << "Name: " << name << "\nAge: " << age << '\n'; } };
class Employee : public Person { public: int id; double salary; void displayEmployee() const { display(); std::cout << "Employee ID: " << id << '\n' << std::fixed << std::setprecision(2) << "Monthly salary: " << salary << '\n'; } };
bool positive(const std::string& s,int& v){std::istringstream i(s);std::string x;return (i>>v)&&!(i>>x)&&v>0;}
int main(){Employee e;std::string s;std::cout<<"Name: ";if(!std::getline(std::cin,e.name)||e.name.empty()){std::cout<<"Name is required.\n";return 0;}std::cout<<"Age: ";if(!std::getline(std::cin,s)||!positive(s,e.age)){std::cout<<"Age must be positive.\n";return 0;}std::cout<<"Employee ID: ";if(!std::getline(std::cin,s)||!positive(s,e.id)){std::cout<<"ID must be positive.\n";return 0;}std::cout<<"Monthly salary: ";if(!std::getline(std::cin,s)){return 0;}std::istringstream i(s);std::string x;if(!(i>>e.salary)||(i>>x)||e.salary<0){std::cout<<"Salary must be non-negative.\n";return 0;}e.displayEmployee();}
