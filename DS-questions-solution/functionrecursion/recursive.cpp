#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int f(int n,int r)
{
	if(n==0 || r==0)
		return 1;
//as per function given
	return f(n-1,r)+ f(n-1,r-1);
}


int main(int argc,char *argv[]){


	int num = atoi(argv[1]);
	int r = atoi(argv[2]);

	printf("%d",f(num,r));
	cout<<endl;

	return 0;
}
