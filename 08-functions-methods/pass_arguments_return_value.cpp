#include <cmath>
#include <iomanip>
#include <iostream>
double rectangleArea(double length,double width){return length*width;}
int main(){double length,width;std::cout<<"Enter rectangle length and width: ";if(!(std::cin>>length>>width)){std::cout<<"Enter two finite non-negative dimensions.\n";return 0;}if(std::cin>>std::ws&&std::cin.peek()!=std::char_traits<char>::eof()){std::cout<<"Enter only two dimensions.\n";return 0;}if(!std::isfinite(length)||!std::isfinite(width)||length<0||width<0){std::cout<<"Dimensions must be finite and non-negative.\n";return 0;}std::cout<<std::fixed<<std::setprecision(2)<<"Area: "<<rectangleArea(length,width)<<'\n';}
