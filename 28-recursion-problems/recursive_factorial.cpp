#include <iostream>
long long factorial(int n){return n<=1?1:n*factorial(n-1);}
int main(){int n;std::cout<<"Enter a whole number from 0 to 20: ";if(!(std::cin>>n)||(std::cin>>std::ws&&std::cin.peek()!=std::char_traits<char>::eof())||n<0||n>20){std::cout<<"Number must be from 0 to 20.\n";return 0;}std::cout<<"Factorial: "<<factorial(n)<<'\n';}
