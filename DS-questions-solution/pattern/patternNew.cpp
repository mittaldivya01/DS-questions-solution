#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

int main(int argc, char *argv[])
{
	int n1, n2,i,j;
	char *text, *pattern;
	int flag = 0;
	text=argv[1];
	pattern=argv[2];
	n1 = strlen(text);
	n2 = strlen(pattern);

	for(i=0;i<= n1-n2; i++)
	{
		for(j=0;j<n2;j++)
		{
			if(text[i+j]!=pattern[j])
				break;
		}
		if(j==n2)
		{
			cout<< i+1<<endl;
			flag = 1;
			break;
		}
	}

	if(flag==0)
	cout<< 0<<endl;
	

return 0;
}
