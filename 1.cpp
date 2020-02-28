#include<iostream> 
using namespace std;
void queen(char a[])
{	
	int i,j,c,m=0,n=0;
	int b[8]={0};
	for(i=0;i<8;i++)
		a[i]=a[i]-'0';
	for(i=0;i<8;i++) 
	{
		if(a[i]>0&&a[i]<9)
			b[i]=a[i];
		else 
			m=i;
	}
	for(i=1;i<=8;i++)
	{	
		c=0;
		for(j=0;j<8;j++)
		{
			if(i==b[j])
				continue;
			else 
				c++;
		}
		if(c==8) 
			n=i;
	}  
	c=1;
    b[m]=n;
		
    for(i=0;i<7;i++)
    {
		for(j=i+1;j<8;j++)
		{
			if(b[i]-b[j]==j-i||b[j]-b[i]==j-i)/*Ð±Ïß*/
			c=0;
		}
	}
    if(c)
		cout<<n<<endl;
    else 
		cout<<"No Answer"<<endl;
}
int main()
{  
	char a[8];
	int i;
    for(i=0;i<8;i++)
	{
		cin>>a[i];
	}
	 queen(a);
	 return 0;
}
