#include<iostream>
using namespace std;
int main()
{
	char c1[10],c2[10];
	int a[10],b[10],c[100];
	int n1,n2,num;
	int i,j,m,n;
	int min;
	cin>>c1>>c2;
	i=0;
	n1=0;
	while(c1[i]!='\0')
	{
		{
			if(c1[i]>='A'&&c1[i]<='Z')
			m=c1[i]-'A';
			else
				m=c1[i]-'a';
		}
		a[n1]=m;
		n1++;
		i++;
	}

	i=0;
	n2=0;
	while(c2[i]!='\0')
	{
		{
			if(c2[i]>='A'&&c2[i]<='Z')
			n=c2[i]-'A';
			else
			 n=c2[i]-'a';
		}
		b[n2]=n;
		n2++;
		i++;
	}
	num=0;
	for(i=0;i<n1;i++)
	{
		for(j=0;j<n2;j++)
		{
			if(a[i]>=b[j])
			c[num]=a[i]-b[j];
			else
			c[num]=b[j]-a[i];
			num++;
		}
		
	}
	
	min=c[0];
	for(i=0;i<num;i++)
	{
		if(c[i]<min)
			min=c[i];}
	cout<<min<<endl;
	return 0;
}


