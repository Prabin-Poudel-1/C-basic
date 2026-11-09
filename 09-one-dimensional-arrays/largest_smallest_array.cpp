#include <iostream>
#include <limits>
#include <algorithm>
int main(){int n;std::cout<<"Enter array size (1-100): ";if(!(std::cin>>n)||n<1||n>100){std::cout<<"Array size must be from 1 to 100.\n";return 0;}int lo=std::numeric_limits<int>::max(),hi=std::numeric_limits<int>::min();for(int i=0;i<n;++i){int v;if(!(std::cin>>v)){std::cout<<"Enter exactly "<<n<<" whole numbers.\n";return 0;}lo=std::min(lo,v);hi=std::max(hi,v);}if(std::cin>>std::ws&&std::cin.peek()!=std::char_traits<char>::eof()){std::cout<<"Enter only the array values.\n";return 0;}std::cout<<"Smallest: "<<lo<<"\nLargest: "<<hi<<'\n';}
