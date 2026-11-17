#include <iostream>
#include <string>
class Person{public:std::string name;explicit Person(std::string n):name(n){}void show()const{std::cout<<"Name: "<<name<<'\n';}};
class Student:public Person{int roll;public:Student(std::string n,int r):Person(n),roll(r){}void display()const{show();std::cout<<"Roll: "<<roll<<'\n';}};
class Teacher:public Person{std::string subject;public:Teacher(std::string n,std::string s):Person(n),subject(s){}void display()const{show();std::cout<<"Subject: "<<subject<<'\n';}};
int main(){std::string n,t,sub;int r;std::cout<<"Student name: ";if(!std::getline(std::cin,n)||n.empty())return 0;std::cout<<"Student roll: ";if(!(std::cin>>r)||r<1){std::cout<<"Roll must be positive.\n";return 0;}std::cin.ignore(10000,'\n');std::cout<<"Teacher name: ";std::getline(std::cin,t);std::cout<<"Subject: ";std::getline(std::cin,sub);if(t.empty()||sub.empty()){std::cout<<"Teacher details required.\n";return 0;}Student s(n,r);Teacher q(t,sub);std::cout<<"Student:\n";s.display();std::cout<<"Teacher:\n";q.display();}
