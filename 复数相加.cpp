#include<iostream>
#include<iomanip>
using namespace std;
double zhengshu(double a,double b)
{
	double c=a-b;
	return c;
}
double xiaoshu(double a,double b)
{
	double c=a-b;
	return c;
}

int main()
{
	double a[4];
	int i;

	for(i=0;i<4;i++)
		cin>>a[i];
	cout<<fixed<<setprecision(2)<<zhengshu(a[0],a[2])<<" "<<xiaoshu(a[1],a[3])<<endl;
	return 0;
}

