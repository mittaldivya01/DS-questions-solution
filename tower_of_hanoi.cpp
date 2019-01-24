#include <iostream>
#include<math.h>
using namespace std;

/*The tower of Hanoi is a famous puzzle where we have three rods and N disks.
The objective of the puzzle is to move the entire stack to another rod. 
You are given the number of discs N. Initially, these discs are in the rod 1. 
You need to print all the steps of discs movement so that all the discs reach the 3rd rod. 
Also, you need to find the total moves.*/
void tower_of_hanoi(int n,int a,int c,int b)
{
    if(n==0) return;

    if(n>1)
    tower_of_hanoi(n-1,a,b,c);//move all above n-1 disk from primary a to auxilary rod b
    //move nth disk from primary a to destination rod c.
    cout<<"move disk "<<n<< " from rod "<< a<< " to rod "<<c<<endl;
    tower_of_hanoi(n-1,b,c,a);//move back n-1 disk from auxilary rod b  to destination rod c.
}

int main() {
	//code
	int t,n;
	cin>>t;
	while(t--){
	    cin>>n;
	    tower_of_hanoi(n,1,3,2);
	    cout<<pow(2,n)-1<<endl;
	}
	return 0;
}