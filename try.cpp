#include<iostream>
using namespace std;
int main()
{
	int i=0;
	char a[10]={'\0'},b[10]={'\0'};
	for(i=0;i<10&&a[i]!='\0';i++)
		{
	cin>>a[i];
		if(a[i]<='Z'&&a[i]>='A')
			a[i]=a[i]+32;
	}
	for(i=0;i<10&&b[i]!='\n';i++)
	{
		cin>>b[i];
		if(b[i]<='Z'&&b[i]>='A')
			b[i]=b[i]+32;
	}
	for(i=0;i<10;i++)
	{
		cout<<a[i]<<b[i];
	}
	return 0;
}
