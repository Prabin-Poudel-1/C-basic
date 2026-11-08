#include <iostream>
void moveDisks(int disks,char from,char to,char spare){if(disks==0)return;moveDisks(disks-1,from,spare,to);std::cout<<"Move disk "<<disks<<" from "<<from<<" to "<<to<<'\n';moveDisks(disks-1,spare,to,from);}
int main(){int n;std::cout<<"Enter number of disks (1-10): ";if(!(std::cin>>n)||(std::cin>>std::ws&&std::cin.peek()!=std::char_traits<char>::eof())||n<1||n>10){std::cout<<"Number of disks must be from 1 to 10.\n";return 0;}moveDisks(n,'A','C','B');std::cout<<"Total moves: "<<((1<<n)-1)<<'\n';}
