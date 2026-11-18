#include <cmath>
#include <iomanip>
#include <iostream>
class AreaCalculator { public: double area(double radius)const{return 3.141592653589793*radius*radius;} double area(double length,double width)const{return length*width;} };
int main(){double r,l,w;std::cout<<"Enter circle radius: ";if(!(std::cin>>r))return 0;std::cout<<"Enter rectangle length and width: ";if(!(std::cin>>l>>w)||r<0||l<0||w<0||!std::isfinite(r)||!std::isfinite(l)||!std::isfinite(w)){std::cout<<"Dimensions must be finite and non-negative.\n";return 0;}AreaCalculator c;std::cout<<std::fixed<<std::setprecision(2)<<"Circle area: "<<c.area(r)<<"\nRectangle area: "<<c.area(l,w)<<'\n';}
