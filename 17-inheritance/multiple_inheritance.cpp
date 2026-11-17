#include <iostream>
#include <string>
class Athlete{public:std::string sport;void showSport()const{std::cout<<"Sport: "<<sport<<'\n';}};
class Musician{public:std::string instrument;void showInstrument()const{std::cout<<"Instrument: "<<instrument<<'\n';}};
class Student:public Athlete,public Musician{public:std::string name;void display()const{std::cout<<"Name: "<<name<<'\n';showSport();showInstrument();}};
int main(){Student s;std::cout<<"Name: ";if(!std::getline(std::cin,s.name)||s.name.empty())return 0;std::cout<<"Sport: ";std::getline(std::cin,s.sport);std::cout<<"Instrument: ";std::getline(std::cin,s.instrument);if(s.sport.empty()||s.instrument.empty()){std::cout<<"Sport and instrument are required.\n";return 0;}s.display();}
