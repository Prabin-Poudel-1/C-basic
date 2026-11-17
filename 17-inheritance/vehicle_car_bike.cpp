#include <iostream>
#include <string>
class Vehicle { public: std::string brand; int speed; void display()const{std::cout<<"Brand: "<<brand<<"\nSpeed: "<<speed<<" km/h\n";} };
class Car:public Vehicle { public:int seats; void show()const{display();std::cout<<"Seats: "<<seats<<'\n';} };
class Bike:public Vehicle { public:int gears; void show()const{display();std::cout<<"Gears: "<<gears<<'\n';} };
int main(){Car c;Bike b;std::cout<<"Car brand speed seats: ";if(!(std::cin>>c.brand>>c.speed>>c.seats))return 0;std::cout<<"Bike brand speed gears: ";if(!(std::cin>>b.brand>>b.speed>>b.gears))return 0;if(c.speed<1||c.seats<1||b.speed<1||b.gears<1){std::cout<<"Speed, seats, and gears must be positive whole numbers.\n";return 0;}std::cout<<"Car:\n";c.show();std::cout<<"Bike:\n";b.show();}
