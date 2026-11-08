#include <cstdlib>
#include <iostream>
long long reverseNumber(long long value,long long result){if(value==0)return result;return reverseNumber(value/10,result*10+value%10);}
int main(){int number;std::cout<<"Enter a signed 32-bit whole number: ";if(!(std::cin>>number)){std::cout<<"Enter one signed 32-bit whole number.\n";return 0;}if(std::cin>>std::ws&&std::cin.peek()!=std::char_traits<char>::eof()){std::cout<<"Enter only one whole number.\n";return 0;}long long magnitude=std::llabs(static_cast<long long>(number));long long reversed=reverseNumber(magnitude,0);std::cout<<"Reversed number: "<<(number<0?-reversed:reversed)<<'\n';}
