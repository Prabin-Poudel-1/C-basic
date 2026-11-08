#include <iostream>
long long sumDigits(long long n){if(n>-10&&n<10)return n<0?-n:n;long long digit=n%10;return (digit<0?-digit:digit)+sumDigits(n/10);}
int main(){long long n;std::cout<<"Enter a signed 64-bit whole number: ";if(!(std::cin>>n)){std::cout<<"Enter one signed 64-bit whole number.\n";return 0;}if(std::cin>>std::ws&&std::cin.peek()!=std::char_traits<char>::eof()){std::cout<<"Enter only one whole number.\n";return 0;}std::cout<<"Sum of digits: "<<sumDigits(n)<<'\n';}
