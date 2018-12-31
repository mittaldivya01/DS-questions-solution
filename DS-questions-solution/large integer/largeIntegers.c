#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[])
{
	int i,j,k,l;
	
	long long int firstnum = 0,secnum  = 0;
	
	int firstLen = strlen(argv[1]);
	int secondLen = strlen(argv[3]);
	j = firstLen-1;
	k = secondLen -1;
//Large integer handling
	for(int i=0;i<firstLength;i++){

		long long int p = (pow(10,i));
		int n = (argv[1][j]-'0');
		n = p*n;
		j--;
		firstnum += n;
	}

	for(int i=0;i<secondLength;i++){

		long long int p = (pow(10,i));
		int n = (argv[3][k]-'0');
		n = p*n;
		k--;
		secnum += n;
	}

//Airthmatic operations on large integers
	if((strcmp(argv[2],"+"))==0){


		printf("%lld",firstnum+secnum);

	}
	else if((strcmp(argv[2],"-"))==0){

		printf("%lld\n", firstnum-secnum);


	}
	else if((strcmp(argv[2],"*"))==0){
		printf("%lld\n", firstnum*secnum);
	}
	else if((strcmp(argv[2],"/"))==0){
//type conversion to double
		printf("%lf\n", (double)firstnum/secnum);
	}
	else{
		printf("Not a Valid Input.");
	}
	return 0;
}
