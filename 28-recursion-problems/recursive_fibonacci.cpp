#include <algorithm>
#include <iostream>
#include <vector>
long long fibonacci(int n,std::vector<long long>& memo){if(n<2)return n;if(memo[n]!=-1)return memo[n];memo[n]=fibonacci(n-1,memo)+fibonacci(n-2,memo);return memo[n];}
int main(){int count;std::cout<<"Enter number of terms (0-93): ";if(!(std::cin>>count)||(std::cin>>std::ws&&std::cin.peek()!=std::char_traits<char>::eof())||count<0||count>93){std::cout<<"Terms must be from 0 to 93.\n";return 0;}std::vector<long long> memo(std::max(2,count),-1);std::cout<<"Fibonacci series: ";for(int i=0;i<count;++i){if(i)std::cout<<' ';std::cout<<fibonacci(i,memo);}if(count==0)std::cout<<"No terms";std::cout<<'\n';}
