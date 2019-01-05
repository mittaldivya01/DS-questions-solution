#include<iostream>
#include<string.h>
using namespace std;

//given an  string, check if  anagram or not


bool anagramcheck(string s1, string s2)
{
int ar1[256]={0};//,ar2[256];//256
int n1,n2;
n1= s1.length();
n2= s2.length();
/*if(n1!=n2)
{
	//cout<< "not anagram";
	return 0;
}

for(int i=0;i<n1;i++)
{
	ar1[s1[i]]++;
}

for(int i=0;i<n2;i++)
{
	if(ar1[s2[i]])
	--ar1[s2[i]];
else
{
	
	return 0;
}
}*/
for(int i=0;i<n1;i++)
{
	ar1[s1[i]]++;
	ar1[s2[i]]--;
}

for(int i=0;i<256;i++)
{
	if(ar1[i])
		return 0;
}

//cout<< "yes anagram";
return 1;
}

int main()
{
	
	string s1,s2;
cin >>s1;
cin >>s2;
if(anagramcheck(s1,s2))
cout<< "yes given strings are anagram";
else
	cout<< "no, given strings are not anagram";

	return 0;
}