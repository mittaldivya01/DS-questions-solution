#include<iostream>
#include<unordered_map>
using namespace std;

//given an array of integers & a number k, find count of distinct elements in every subarray of size k

void distinctCount(int a[], int n,int k)
{

unordered_map<int,int> :: iterator it;


for(int j=0; j<n-k+1; j++)
	{
		int res=0;
		unordered_map<int,int> tmp;
		for(int i=j; i<k+j; i++)
 			{
 				if(tmp.find(a[i]) ==tmp.end())
 				tmp.insert(make_pair(a[i],1));
 			else tmp[a[i]]++;
 			}
 			for(it=tmp.begin();it!=tmp.end();it++)
			{
				res++;
			}
			cout<<res<< " ";
 		}
		
return;
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
distinctCount(a,n,k);
	return 0;
}