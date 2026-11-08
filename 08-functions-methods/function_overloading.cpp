#include <cmath>
#include <iostream>
int add(int first,int second){return first+second;}
double add(double first,double second){return first+second;}
int main(){int a,b;double x,y;std::cout<<"Enter two whole numbers, then two decimal numbers: ";if(!(std::cin>>a>>b>>x>>y)){std::cout<<"Enter two whole numbers and two finite decimal numbers.\n";return 0;}if(std::cin>>std::ws&&std::cin.peek()!=std::char_traits<char>::eof()){std::cout<<"Enter exactly four valid numbers.\n";return 0;}if(!std::isfinite(x)||!std::isfinite(y)){std::cout<<"Enter finite decimal values.\n";return 0;}std::cout<<"Integer sum: "<<add(a,b)<<"\nDecimal sum: "<<add(x,y)<<'\n';}
