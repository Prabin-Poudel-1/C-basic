#include <iostream>
void printSeries(int terms) {
    long long first=0, second=1;
    for(int i=0;i<terms;++i){if(i>0)std::cout<<' ';std::cout<<first;if(i+1<terms){long long next=first+second;first=second;second=next;}}
    if(terms==0)std::cout<<"No terms"; std::cout<<'\n';
}
int main(){int terms;std::cout<<"Enter number of terms (0-93): ";if(!(std::cin>>terms)||(std::cin>>std::ws&&std::cin.peek()!=std::char_traits<char>::eof())||terms<0||terms>93){std::cout<<"Terms must be from 0 to 93.\n";return 0;}std::cout<<"Fibonacci series: ";printSeries(terms);}
