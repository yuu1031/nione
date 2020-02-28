#include<iostream>
#include<cmath>
using namespace std;
int isPrime(int a)
{
	int k=0,i;
	if(a==1||a==2) 
		k=1;
	if(a>2)
	{
		for(i=2;i<a;i++)
		{
			if(a%i!=0)
				k=1;
			else k=0;
		if(k==0) break;
	}}
	return k;
}
int main()
{
	unsigned short a;
	cin>>a;
	if(isPrime(a))
		cout<<"Y"<<endl;
	else
		cout<<"N"<<endl;
	return 0;
}