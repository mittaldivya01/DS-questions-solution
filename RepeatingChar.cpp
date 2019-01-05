#include<iostream>
#include<string.h>
using namespace std;

//given an  string, find first character whose index of first occurence is smallest else print -1
//if input is seeks output should be 's'


void repeating(string s1)
{
bool visited[256]={false};
int n1,s=0;
int res;
res=-1;
n1= s1.length();
if(n1)
{
	for(int i=n1;i>=0; i--)
	{
		if(	visited[s1[i]])
			res=s1[i];
		visited[s1[i]]=true;
	}
	if (res== -1)
	{
		cout<< res;
	}
	else
		cout<< (char) res;
}

}

int main()
{
	
	string s1;
	char c;
cin >>s1;
repeating(s1);

	return 0;
}