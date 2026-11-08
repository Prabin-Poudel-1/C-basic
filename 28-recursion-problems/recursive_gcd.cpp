#include <cstdlib>
#include <iostream>
long long gcd(long long a,long long b){return b==0?a:gcd(b,a%b);}
int main(){int x,y;std::cout<<"Enter two 32-bit whole numbers: ";if(!(std::cin>>x>>y)){std::cout<<"Enter two 32-bit whole numbers.\n";return 0;}if(std::cin>>std::ws&&std::cin.peek()!=std::char_traits<char>::eof()){std::cout<<"Enter only two whole numbers.\n";return 0;}long long a=std::llabs(static_cast<long long>(x)),b=std::llabs(static_cast<long long>(y));std::cout<<"GCD/HCF: "<<gcd(a,b)<<'\n';}
