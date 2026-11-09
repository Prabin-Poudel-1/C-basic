#include <iomanip>
#include <iostream>
int main(){int n;std::cout<<"Enter array size (1-100): ";if(!(std::cin>>n)||n<1||n>100){std::cout<<"Array size must be from 1 to 100.\n";return 0;}long long sum=0;for(int i=0;i<n;++i){int v;if(!(std::cin>>v)){std::cout<<"Enter exactly "<<n<<" whole numbers.\n";return 0;}sum+=v;}if(std::cin>>std::ws&&std::cin.peek()!=std::char_traits<char>::eof()){std::cout<<"Enter only the array values.\n";return 0;}std::cout<<std::fixed<<std::setprecision(2)<<"Average: "<<static_cast<double>(sum)/n<<'\n';}
