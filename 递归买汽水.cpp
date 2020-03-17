#include<iostream>
using namespace std;
 
int Number(int cap,int empty,int bottle)	//cap∆ø∏«£¨emptyø’∆ø£¨bottle∆°æ∆∆ø
{
	int a,b,c,d;
	if(empty<2&&cap<3)
	{
	return bottle;
	}
	a=empty/2;		//ø’∆øø…ªªµƒ∆°æ∆ ˝
	b=empty%2;		//ø’∆øªªÕÍ £œ¬µƒø’∆ø ˝
	c=cap/3;		//∆ø∏«ø…ªªµƒ∆°æ∆ ˝
	d=cap%3;		//∆ø∏«ªªÕÍ £œ¬µƒ∆ø∏« ˝
	return Number(a+c+d,a+c+b,a+c+bottle);
}
 
int main()
{
	int num,n;
	cin>>num;
	n=num+Number(num,num,0);
	cout<<n<<endl;
	return 0;
}
