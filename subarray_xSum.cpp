#include<iostream>
#include<unordered_map>
using namespace std;

//given an array of integers & a number k, find the maximumum sum of any  subarray of size k. ip  3 -2 8 -1 20 3 k=3 op 27

int sum(int a[], int n,int k)
{
int tmp=0,res=-1000000;
for(int i=0; i<k-1; i++)
tmp+=a[i];

for(int j=k-1; j<n; j++)
	{
		if ((j-k) < 0)
		{
			tmp= tmp+a[j];/* code */
		}
		else
		tmp= tmp+a[j]-a[j-k];
		if(tmp>res)
		res=tmp;
	
}
return res;
}


int main()
{
int x,n,k;
cout<< "enter size of array: ";
cin >>n;
cout<< "enter size of subarray: ";
cin >>k;
int a[n];
cout<< "enter "<<n <<" elements of array ";
for(int i=0; i<n; i++)
{
	cin>>x;
	a[i]=x;
}
int s=sum(a,n,k);
cout <<"maximum subarray sum of size "<<k << " in given array is " << s;
	return 0;
}