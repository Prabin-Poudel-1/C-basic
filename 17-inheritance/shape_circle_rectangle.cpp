#include <cmath>
#include <iomanip>
#include <iostream>
class Shape { public: virtual double area() const=0; virtual ~Shape()=default; };
class Circle: public Shape { double r; public: explicit Circle(double x):r(x){} double area()const override{return 3.141592653589793*r*r;} };
class Rectangle: public Shape { double l,w; public: Rectangle(double a,double b):l(a),w(b){} double area()const override{return l*w;} };
int main(){double r,l,w;std::cout<<"Enter circle radius: ";if(!(std::cin>>r)){return 0;}std::cout<<"Enter rectangle length and width: ";if(!(std::cin>>l>>w)||r<0||l<0||w<0||!std::isfinite(r)||!std::isfinite(l)||!std::isfinite(w)){std::cout<<"Dimensions must be finite and non-negative.\n";return 0;}Circle c(r);Rectangle q(l,w);const Shape* a=&c;const Shape*b=&q;std::cout<<std::fixed<<std::setprecision(2)<<"Circle area: "<<a->area()<<"\nRectangle area: "<<b->area()<<'\n';}
