#include<iostream>
using namespace std;

//find square root of n.
void sqrootn(int n)
{
	int l=0,h=n,res=0;

int mid=0;
while(l<h)
{
	mid=(h+l)/2;
if(mid * mid == n || ( mid * mid < n && ((mid+1)*(mid+1))> n ))
{cout<< mid;
	return;}
	else if(mid * mid < n)
	{
		
		l=mid+1;
		res=l;
	}
	else
		{
			h=mid-1;
			res=h;
}
}
cout<< res;

}
int main()
{
	int n;
	cin>>n;
	sqrootn(n);
	return 0;
}